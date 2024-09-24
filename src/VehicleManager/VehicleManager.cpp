#include "VehicleManager.h"
#include <LinkManager.h>
#include <SettingManager.h>

UGC::VehicleManager::VehicleManager(UGCApplication *app) : UGCContext{app}{
    connect(this->mApp->linkManager(), &LinkManager::receivedMessage, this, &VehicleManager::handleMessage);
}

void UGC::VehicleManager::handleMessage(const mavlink_message_t &message){
    if(message.msgid == MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION){
        // 解析消息
        qDebug() << QString("[MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION]sysid=%1").arg(message.sysid);
        mavlink_usv_system_information_t system_information;
        mavlink_msg_usv_system_information_decode(&message, &system_information);
        int vehicleSystemId = message.sysid;
        QString name = QString::fromStdString(system_information.name);
        float longitude = system_information.lon;
        float latitude = system_information.lat;
        bool connected = system_information.connected;
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
        if(message.sysid == mOwnerVehicleSystemId){
            mOwnerVehicleTrajectory.append(QGeoCoordinate(latitude, longitude));
            if(mOwnerVehicleTrajectory.size() > 50){
                mOwnerVehicleTrajectory.removeFirst();
            }
            emit vehicleTrajectoryChanged(QGeoCoordinate(latitude, longitude));
        }
        emit vehiclesChanged(res);
    }else if(message.msgid == MAVLINK_MSG_ID_USV_CONNECT_RESPONSE){
        qDebug() << QString("[MAVLINK_MSG_ID_USV_CONNECT_RESPONSE]sysid=%1").arg(message.sysid);
        mavlink_usv_connect_response_t connect_response;
        mavlink_msg_usv_connect_response_decode(&message, &connect_response);
        int gcsSystemId = this->mApp->settingManager()->systemId();
        if(connect_response.target_system != gcsSystemId){
            qDebug() << "GCS System ID Not Match: " << connect_response.target_system;
            return;
        }
        if(connect_response.ack == 1){
            qDebug() << "Connect Vehicle Succeed: " << message.sysid;
            mOwnerVehicleSystemId = message.sysid;
        }else{
            qDebug() << "Connect Vehicle Failed: " << message.sysid;
        }
        emit connectVehicleCompleted(message.sysid, connect_response.ack);
    }else if(message.msgid == MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE){
        qDebug() << QString("[MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE]sysid=%1").arg(message.sysid);
        mavlink_usv_disconnect_response_t disconnect_response;
        mavlink_msg_usv_disconnect_response_decode(&message, &disconnect_response);
        int gcsSystemId = this->mApp->settingManager()->systemId();
        if(disconnect_response.target_system != gcsSystemId){
            qDebug() << "GCS System ID Not Match: " << disconnect_response.target_system;
            return;
        }
        if(disconnect_response.ack == 1){
            qDebug() << "Disconnect Vehicle Succeed: " << message.sysid;
            mOwnerVehicleSystemId = 0;
        }else{
            qDebug() << "Disconnect Vehicle Failed: " << message.sysid;
        }
        emit disconnectVehicleCompleted(message.sysid, disconnect_response.ack == 1);
    }
}

void UGC::VehicleManager::connectVehicle(int systemId){
    qDebug() << "Connecting Vehicle: " << systemId;
    mavlink_message_t message;
    mavlink_msg_usv_connect_request_pack_chan(this->mApp->settingManager()->systemId(), 0, MAVLINK_COMM_0, &message, systemId);
    this->mApp->linkManager()->sendMessage(systemId, message);
}

void UGC::VehicleManager::disconnectVehicle(int systemId){
    qDebug() << "Disconnecting Vehicle: " << systemId;
    mavlink_message_t message;
    mavlink_msg_usv_disconnect_request_pack_chan(this->mApp->settingManager()->systemId(), 0, MAVLINK_COMM_0, &message, systemId);
    this->mApp->linkManager()->sendMessage(systemId, message);
}

void UGC::VehicleManager::getVehicles(){
    QList<QVariantMap> res;
    QList<Vehicle> list = mVehicles.values();
    for (int i = 0; i < list.size(); ++i) {
        res.append(list.value(i).toQVariantMap());
    }
    emit vehiclesChanged(res);
}
