#include "VehicleManager.h"
#include <LinkManager.h>
#include <SettingManager.h>

UGC::VehicleManager::VehicleManager(UGCApplication *app) : UGCContext{app}{
    connect(this->mApp->linkManager(), &LinkManager::receivedMessage, this, &VehicleManager::handleMessage);
}

void UGC::VehicleManager::handleMessage(const mavlink_message_t &message){
    if(message.msgid == MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION){
        mavlink_usv_system_information_t system_information;
        mavlink_msg_usv_system_information_decode(&message, &system_information);
        int vehicleSystemId = message.sysid;
        QString name = QString::fromStdString(system_information.name);
        float longitude = system_information.lon;
        float latitude = system_information.lat;
        Vehicle vehicle{vehicleSystemId, name, longitude, latitude, UGC::VehicleType::survey};
        mVehicles.insert(vehicleSystemId, vehicle);
        emit vehiclesChanged(mVehicles.values());
    }
}

void UGC::VehicleManager::connectVehicle(int systemId){
    mavlink_message_t message;
    mavlink_msg_usv_connect_request_pack_chan(this->mApp->settingManager()->systemId(), 0, MAVLINK_COMM_0, &message, systemId);
    this->mApp->linkManager()->sendMessage(message);
}

void UGC::VehicleManager::disconnectVehicle(int systemId){
    mavlink_message_t message;
    mavlink_msg_usv_disconnect_request_pack_chan(this->mApp->settingManager()->systemId(), 0, MAVLINK_COMM_0, &message, systemId);
    this->mApp->linkManager()->sendMessage(message);
}
