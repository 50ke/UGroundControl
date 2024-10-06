#include "VehicleManager.h"
#include <LinkManager.h>
#include <SettingManager.h>

UGC::VehicleManager::VehicleManager(UGCApplication *app) : UGCContext{app}{
    connect(this->mApp->linkManager(), &LinkManager::receivedMessage, this, &VehicleManager::handleMessage);
}

void UGC::VehicleManager::handleMessage(const UsvLink::MessagePacket &message){
    if(message.msg_id() == UsvLink::MsgId::MSG_ID_HEARTBEAT){
        // 解析消息
        UsvLink::Heartbeat heartbeat = message.heartbeat();
        int vehicleSystemId = message.system_id();
        QString name = QString::fromStdString(heartbeat.name());
        float longitude = heartbeat.longitude();
        float latitude = heartbeat.latitude();
        bool connected = heartbeat.connect_status();
        bool own = (vehicleSystemId == mOwnVehicleSystemId);
        // 更新无人船列表
        Vehicle vehicle{vehicleSystemId, name, longitude, latitude, UGC::VehicleType::survey, connected, own};
        mVehicles.insert(vehicleSystemId, vehicle);
        // 通知更新
        QList<QVariantMap> res;
        QList<Vehicle> list = mVehicles.values();
        for (int i = 0; i < list.size(); ++i) {
            res.append(list.value(i).toQVariantMap());
        }
        if(message.system_id() == mOwnVehicleSystemId){
            mOwnVehicleTrajectory.append(QGeoCoordinate(latitude, longitude));
            if(mOwnVehicleTrajectory.size() > 50){
                mOwnVehicleTrajectory.removeFirst();
            }
            emit vehicleTrajectoryChanged(QGeoCoordinate(latitude, longitude));
        }
        emit vehiclesChanged(res);
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_CONNECT_RESPONSE){
        UsvLink::ConnectResponse connectResponse = message.connect_response();
        int gcsSystemId = this->mApp->settingManager()->systemId();
        if(message.target_system_id() != gcsSystemId){
            qDebug() << "[VehicleManager]GCS System ID Cannot Match" << message.target_system_id();
            return;
        }
        if(connectResponse.ack() == 1){
            qDebug() << "[VehicleManager]Successfully Connected to Vehicle" << message.system_id();
            mOwnVehicleSystemId = message.system_id();
        }else{
            qDebug() << "[VehicleManager]Failed to Connected to Vehicle" << message.system_id();
        }
        emit connectVehicleCompleted(message.system_id(), connectResponse.ack());
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_DISCONNECT_RESPONSE){
        UsvLink::DisconnectResponse disconnectResponse = message.disconnect_response();
        int gcsSystemId = this->mApp->settingManager()->systemId();
        if(message.target_system_id() != gcsSystemId){
            qDebug() << "[VehicleManager]GCS System ID Cannot Match" << message.target_system_id();
            return;
        }
        if(disconnectResponse.ack() == 1){
            qDebug() << "[VehicleManager]Successfully Disconnected to Vehicle" << message.system_id();
            mOwnVehicleSystemId = 0;
        }else{
            qDebug() << "[VehicleManager]Failed to Disconnected to Vehicle" << message.system_id();
        }
        emit disconnectVehicleCompleted(message.system_id(), disconnectResponse.ack() == 1);
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_PARAM_READ_RESPONSE){
        int gcsSystemId = this->mApp->settingManager()->systemId();
        if(message.system_id() != mOwnVehicleSystemId || message.target_system_id() != gcsSystemId){
            qDebug() << "[VehicleManager]GCS or Vehicle System ID Cannot Match";
            return;
        }
        UsvLink::ParamReadResponse paramReadResponse = message.param_read_response();
        if(!paramReadResponse.ack()){
            qDebug() << "[VehicleManager]Read Param Failed:" << QString::fromStdString(paramReadResponse.err_msg());
            return;
        }
        for (UsvLink::ParamItem param: paramReadResponse.param_items()) {
            QVariantMap paramItem = {
                {"paramId", QString::fromStdString(param.param_id())},
                {"paramValue", param.param_value()},
                {"paramIndex", param.param_index()},
            };
            mOwnVehicleParams.insert(QString::fromStdString(param.param_id()), paramItem);
        }
        emit readVehicleParamsCompleted(mOwnVehicleParams.values());
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_PARAM_WRITE_RESPONSE){
        UsvLink::ParamWriteResponse paramWriteResponse = message.param_write_response();
        if(paramWriteResponse.ack()){
            qDebug() << "[VehicleManager]Param Write Success.";
            requestVehicleParams();
        }else{
            qDebug() << "[VehicleManager]Param Write Failed.";
        }
    }
}

void UGC::VehicleManager::clear(){
    mOwnVehicleSystemId = 0;
    mOwnVehicleParams.clear();
    mOwnVehicleTrajectory.clear();
}

void UGC::VehicleManager::requestVehicleParams(){
    UsvLink::ParamReadRequest *payload = new UsvLink::ParamReadRequest();
    payload->set_allocated_param_id(new std::string(""));
    payload->set_param_index(-1);

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_PARAM_READ_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(mOwnVehicleSystemId);
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_param_read_request(payload);

    this->mApp->linkManager()->sendMessage(mOwnVehicleSystemId, packet);
}

void UGC::VehicleManager::connectVehicle(int systemId){
    qDebug() << "[VehicleManager]Requesting to Connecte to Vehicle" << systemId;
    UsvLink::ConnectRequest *payload  = new UsvLink::ConnectRequest();

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_CONNECT_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(systemId);
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_connect_request(payload);

    this->mApp->linkManager()->sendMessage(systemId, packet);
}

void UGC::VehicleManager::disconnectVehicle(int systemId){
    qDebug() << "[VehicleManager]Requesting to Disconnecte to Vehicle" << systemId;
    UsvLink::DisconnectRequest *payload = new UsvLink::DisconnectRequest();

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_DISCONNECT_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(systemId);
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_disconnect_request(payload);

    this->mApp->linkManager()->sendMessage(systemId, packet);
}

void UGC::VehicleManager::getVehicles(){
    QList<QVariantMap> res;
    QList<Vehicle> list = mVehicles.values();
    for (int i = 0; i < list.size(); ++i) {
        res.append(list.value(i).toQVariantMap());
    }
    emit vehiclesChanged(res);
}

QList<QVariantMap> UGC::VehicleManager::readVehicleParams(){
    qDebug() << "[VehicleManager]Requesting to Read Params for Vehicle" << mOwnVehicleSystemId;
    if(mOwnVehicleSystemId == 0){
        return QList<QVariantMap>();
    }
    if(!mOwnVehicleParams.empty()){
        return mOwnVehicleParams.values();
    }

    UsvLink::ParamReadRequest *payload = new UsvLink::ParamReadRequest();
    payload->set_allocated_param_id(new std::string(""));
    payload->set_param_index(-1);

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_PARAM_READ_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(mOwnVehicleSystemId);
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_param_read_request(payload);

    this->mApp->linkManager()->sendMessage(mOwnVehicleSystemId, packet);
    return QList<QVariantMap>();
}

void UGC::VehicleManager::readVehicleParam(QString paramId){
    qDebug() << "[VehicleManager]Requesting to Read Single Param for Vehicle" << mOwnVehicleSystemId;
    if(mOwnVehicleSystemId == 0){
        return;
    }
    if(!mOwnVehicleParams.contains(paramId)){
        return;
    }
    QVariantMap paramItem = mOwnVehicleParams.value(paramId);

    UsvLink::ParamReadRequest *payload = new UsvLink::ParamReadRequest();
    payload->set_allocated_param_id(new std::string(paramId.toStdString()));
    payload->set_param_index(paramItem["paramIndex"].toInt());

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_PARAM_READ_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(mOwnVehicleSystemId);
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_param_read_request(payload);

    this->mApp->linkManager()->sendMessage(mOwnVehicleSystemId, packet);
}

void UGC::VehicleManager::writeVehicleParam(QString paramId, float paramValue){
    if(mOwnVehicleSystemId == 0){
        return;
    }
    if(!mOwnVehicleParams.contains(paramId)){
        return;
    }
    QVariantMap paramItemMap = mOwnVehicleParams.value(paramId);
    // 封装参数
    UsvLink::ParamItem paramItem;
    paramItem.set_allocated_param_id(new std::string(paramId.toStdString()));
    paramItem.set_param_value(paramValue);
    paramItem.set_param_index(paramItemMap["paramIndex"].toInt());
    // 发送参数写请求
    UsvLink::ParamWriteRequest *payload = new UsvLink::ParamWriteRequest();
    payload->add_param_items()->CopyFrom(paramItem);
    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_PARAM_WRITE_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(mOwnVehicleSystemId);
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_param_write_request(payload);

    this->mApp->linkManager()->sendMessage(mOwnVehicleSystemId, packet);
}
