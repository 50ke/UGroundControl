#include "Heartbeat.h"
#include <MqttLink.h>
#include <SettingManager.h>

UGC::Heartbeat::Heartbeat(MqttLink *mqttLink) : mVehicleMqttLink{mqttLink}{}

void UGC::Heartbeat::updateConnection(int gcsSystemId, int usvSystemId){
    mConnectedGcsSystemId = gcsSystemId;
    mConnectedUsvSystemId = usvSystemId;
}

void UGC::Heartbeat::publishHeartbeat(){
    float x = 28.873177;
    float y = 105.458048;
    QRandomGenerator generator;
    while(true){
        float lan = x + generator.bounded(10)*0.001;
        float lon = y + generator.bounded(10)*0.001;
        // USV02
        UsvLink::Heartbeat *heartbeat2 = new UsvLink::Heartbeat();
        heartbeat2->set_allocated_name(new std::string("USV02"));
        heartbeat2->set_latitude(lan);
        heartbeat2->set_longitude(lon);
        heartbeat2->set_anchor_remaining(0);
        heartbeat2->set_connect_status(mConnectedUsvSystemId == 2);
        heartbeat2->set_connect_target_system_id(mConnectedUsvSystemId == 2 ? mConnectedGcsSystemId : 0);
        UsvLink::MessagePacket packet2;
        packet2.set_msg_id(UsvLink::MsgId::MSG_ID_HEARTBEAT);
        packet2.set_system_id(2);
        packet2.set_component_id(0);
        packet2.set_target_system_id(0);
        packet2.set_target_component_id(0);
        packet2.set_time_ms(QDateTime::currentMSecsSinceEpoch());
        packet2.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
        packet2.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
        packet2.set_allocated_heartbeat(heartbeat2);
        mVehicleMqttLink->publish(0, packet2);
        // USV03
        // UsvLink::Heartbeat heartbeat3;
        // heartbeat3.set_allocated_name(new std::string("USV03"));
        // heartbeat3.set_latitude(28.86317);
        // heartbeat3.set_longitude(105.458048);
        // heartbeat3.set_anchor_remaining(0);
        // heartbeat3.set_connect_status(mConnectedUsvSystemId == 3);
        // heartbeat3.set_connect_target_system_id(mConnectedUsvSystemId == 3 ? mConnectedGcsSystemId : 0);
        // UsvLink::MessagePacket packet3;
        // packet3.set_msg_id(UsvLink::MsgId::MSG_ID_HEARTBEAT);
        // packet3.set_system_id(3);
        // packet3.set_component_id(0);
        // packet3.set_target_system_id(0);
        // packet3.set_target_component_id(0);
        // packet3.set_time_ms(QDateTime::currentMSecsSinceEpoch());
        // packet3.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
        // packet3.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
        // packet3.set_allocated_heartbeat(&heartbeat3);
        // mVehicleMqttLink->publish(0, packet3);

        QThread::msleep(3000);
    }
}
