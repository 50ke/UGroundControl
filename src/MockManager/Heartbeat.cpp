#include "Heartbeat.h"
#include <MqttLink.h>
#include <SettingManager.h>

UGC::Heartbeat::Heartbeat(MqttLink *mqttLink) : mVehicleMqttLink{mqttLink}{}

void UGC::Heartbeat::updateConnectedUsvSystemId(int systemId){
    mconnectedUsvSystemId = systemId;
}

void UGC::Heartbeat::publishSystemInfo(){
    while(true){
        mavlink_message_t message;
        mavlink_msg_usv_system_information_pack_chan(2, 0, MAVLINK_COMM_0, &message, "USV02", mconnectedUsvSystemId == 2 ? 1 : 0, 12.34, 56.78);
        mVehicleMqttLink->publish(0, message);

        mavlink_msg_usv_system_information_pack_chan(3, 0, MAVLINK_COMM_0, &message, "USV03", mconnectedUsvSystemId == 3 ? 1 : 0, 34.34, 56.56);
        mVehicleMqttLink->publish(0, message);
        QThread::msleep(3000);
    }
}
