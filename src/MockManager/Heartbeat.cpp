#include "Heartbeat.h"
#include <MqttLink.h>
#include <SettingManager.h>

UGC::Heartbeat::Heartbeat(MqttLink *mqttLink) : mVehicleMqttLink{mqttLink}{}

void UGC::Heartbeat::updateConnectedUsvSystemId(int systemId){
    mconnectedUsvSystemId = systemId;
}

void UGC::Heartbeat::publishSystemInfo(){
    float x = 28.873177;
    float y = 105.458048;
    QRandomGenerator generator;
    while(true){
        float lan = x + generator.bounded(10)*0.0001;
        float lon = y + generator.bounded(10)*0.0001;
        mavlink_message_t message;
        mavlink_msg_usv_system_information_pack_chan(2, 0, MAVLINK_COMM_0, &message, "USV02", mconnectedUsvSystemId == 2 ? 1 : 0, lan, lon);
        mVehicleMqttLink->publish(0, message);

        mavlink_msg_usv_system_information_pack_chan(3, 0, MAVLINK_COMM_0, &message, "USV03", mconnectedUsvSystemId == 3 ? 1 : 0, 28.863177, 105.458048);
        mVehicleMqttLink->publish(0, message);

        mavlink_msg_usv_system_information_pack_chan(4, 0, MAVLINK_COMM_0, &message, "USV04", mconnectedUsvSystemId == 4 ? 1 : 0, 28.853177, 105.458048);
        mVehicleMqttLink->publish(0, message);

        mavlink_msg_usv_system_information_pack_chan(5, 0, MAVLINK_COMM_0, &message, "USV05", mconnectedUsvSystemId == 5 ? 1 : 0, 28.843177, 105.458048);
        mVehicleMqttLink->publish(0, message);

        mavlink_msg_usv_system_information_pack_chan(6, 0, MAVLINK_COMM_0, &message, "USV06", mconnectedUsvSystemId == 6 ? 1 : 0, 28.833177, 105.458048);
        mVehicleMqttLink->publish(0, message);

        // float x = 28.833177 + generator.bounded(10)*0.01;
        // float y = 105.458048f + generator.bounded(10)*0.01;
        // std::vector<float> pos_x = {x};
        // std::vector<float> pos_y = {y};
        // mavlink_msg_trajectory_representation_bezier_pack_chan(2, 0, MAVLINK_COMM_0, &message, 1, 1, pos_x.data(), pos_y.data(), {0}, {0}, {0});
        // mVehicleMqttLink->publish("GCS/1", message);
        QThread::msleep(3000);
    }
}
