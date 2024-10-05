#include "VehicleManager.h"
#include <LinkManager.h>
#include <SettingManager.h>

UGC::VehicleManager::VehicleManager(UGCApplication *app) : UGCContext{app}{
    connect(this->mApp->linkManager(), &LinkManager::receivedMessage, this, &VehicleManager::handleMessage);
}

void UGC::VehicleManager::handleMessage(const UsvLink::MessagePacket &message){
    if(message.msg_id() == UsvLink::MsgId::MSG_ID_HEARTBEAT){
        // 解析消息
        qDebug() << QString("[MSG_ID_HEARTBEAT]sysid=%1").arg(message.system_id());
        UsvLink::Heartbeat heartbeat = message.heartbeat();
        int vehicleSystemId = message.system_id();
        QString name = QString::fromStdString(heartbeat.name());
        float longitude = heartbeat.longitude();
        float latitude = heartbeat.latitude();
        bool connected = heartbeat.connect_status();
        bool owner = (vehicleSystemId == mOwnerVehicleSystemId);
        // 更新无人船列表
        Vehicle vehicle{vehicleSystemId, name, longitude, latitude, UGC::VehicleType::survey, connected, owner};
        mVehicles.insert(vehicleSystemId, vehicle);
        // 通知更新
        QList<QVariantMap> res;
        QList<Vehicle> list = mVehicles.values();
        for (int i = 0; i < list.size(); ++i) {
            res.append(list.value(i).toQVariantMap());
        }
        if(message.system_id() == mOwnerVehicleSystemId){
            mOwnerVehicleTrajectory.append(QGeoCoordinate(latitude, longitude));
            if(mOwnerVehicleTrajectory.size() > 50){
                mOwnerVehicleTrajectory.removeFirst();
            }
            emit vehicleTrajectoryChanged(QGeoCoordinate(latitude, longitude));
        }
        emit vehiclesChanged(res);
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_CONNECT_RESPONSE){
        qDebug() << QString("[MSG_ID_CONNECT_RESPONSE]sysid=%1").arg(message.system_id());
        UsvLink::ConnectResponse connectResponse = message.connect_response();
        int gcsSystemId = this->mApp->settingManager()->systemId();
        if(message.target_system_id() != gcsSystemId){
            qDebug() << "GCS System ID Not Match: " << message.target_system_id();
            return;
        }
        if(connectResponse.ack() == 1){
            qDebug() << "Connect Vehicle Succeed: " << message.system_id();
            mOwnerVehicleSystemId = message.system_id();
        }else{
            qDebug() << "Connect Vehicle Failed: " << message.system_id();
        }
        emit connectVehicleCompleted(message.system_id(), connectResponse.ack());
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_DISCONNECT_RESPONSE){
        qDebug() << QString("[MSG_ID_DISCONNECT_RESPONSE]sysid=%1").arg(message.system_id());
        UsvLink::DisconnectResponse disconnectResponse = message.disconnect_response();
        int gcsSystemId = this->mApp->settingManager()->systemId();
        if(message.target_system_id() != gcsSystemId){
            qDebug() << "GCS System ID Not Match: " << message.target_system_id();
            return;
        }
        if(disconnectResponse.ack() == 1){
            qDebug() << "Disconnect Vehicle Succeed: " << message.system_id();
            mOwnerVehicleSystemId = 0;
        }else{
            qDebug() << "Disconnect Vehicle Failed: " << message.system_id();
        }
        emit disconnectVehicleCompleted(message.system_id(), disconnectResponse.ack() == 1);
    }
}

void UGC::VehicleManager::connectVehicle(int systemId){
    qDebug() << "Connecting Vehicle: " << systemId;
    UsvLink::ConnectRequest connectRequest;

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_CONNECT_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(systemId);
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_connect_request(&connectRequest);

    this->mApp->linkManager()->sendMessage(systemId, packet);
}

void UGC::VehicleManager::disconnectVehicle(int systemId){
    qDebug() << "Disconnecting Vehicle: " << systemId;
    UsvLink::DisconnectRequest disconnectRequest;

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_DISCONNECT_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(systemId);
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_disconnect_request(&disconnectRequest);

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
