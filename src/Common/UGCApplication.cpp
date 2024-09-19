#include "UGCApplication.h"
#include <SettingManager.h>
#include <LinkManager.h>

// #include <common/mavlink.h>
#include <mavlink_helpers.h>
#include <USV/mavlink.h>
#include <USV/mavlink_msg_usv_system_information.h>
#include <USV/mavlink_msg_usv_connect_response.h>

UGC::UGCApplication::UGCApplication(){
    mSettingManagerPtr = new UGC::SettingManager(this);
    mLinkManagerPtr = new UGC::LinkManager(this);
}

void UGC::UGCApplication::init(QQmlContext *context){
    context->setContextProperty("settingManager", mSettingManagerPtr);
    mLinkManagerPtr->start();
    // mLinkManagerPtr->sendMessage("I AM UGC.");

    // mavlink_message_t message;
    // const uint8_t system_id = 42;
    // const uint8_t base_mode = 0;
    // const uint8_t custom_mode = 0;
    // mavlink_msg_heartbeat_pack_chan(
    //     system_id,
    //     MAV_COMP_ID_PERIPHERAL,
    //     MAVLINK_COMM_0,
    //     &message,
    //     MAV_TYPE_GENERIC,
    //     MAV_AUTOPILOT_GENERIC,
    //     base_mode,
    //     custom_mode,
    //     MAV_STATE_STANDBY);

    // uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    // const int len = mavlink_msg_to_send_buffer(buffer, &message);

    // mavlink_message_t message_t;
    // mavlink_status_t status_t;
    // for (int i = 0; i < len; ++i) {
    //     if (mavlink_parse_char(MAVLINK_COMM_0, buffer[i], &message_t, &status_t) == 1) {
    //         switch (message_t.msgid) {
    //             case MAVLINK_MSG_ID_HEARTBEAT:
    //                 mavlink_heartbeat_t heartbeat;
    //                 mavlink_msg_heartbeat_decode(&message_t, &heartbeat);
    //                 qDebug() << "name:" << heartbeat.type;
    //                 break;
    //         }
    //     }
    // }


    mavlink_message_t message;
    mavlink_msg_usv_connect_response_pack_chan(1, 1, MAVLINK_COMM_0, &message, 1, 1);
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    const int len = mavlink_msg_to_send_buffer(buffer, &message);

    mavlink_status_t status_t;
    mavlink_message_t message_t;
    for (int i = 0; i <len; i++)
    {
        // qDebug() << "i = " << i << "==" << buffer[i];
        if (mavlink_parse_char(MAVLINK_COMM_0, buffer[i], &message_t, &status_t) == 1)
        {
            qDebug() << "wewwwwwwwwwwww";
            switch (message_t.msgid)
            {
            case MAVLINK_MSG_ID_USV_CONNECT_RESPONSE:
                //mavlink_heartbeat_t heartbeat;
                mavlink_usv_connect_response_t system_information;
                //mavlink_usv_system_information_t system_information;
                //mavlink_msg_heartbeat_decode(&rmsg, &heartbeat);
                mavlink_msg_usv_connect_response_decode(&message_t, &system_information);
                qDebug() << "ack:" << system_information.ack;
                // qDebug() << "lat:" << system_information.lat;
                // qDebug() << "lon:" << system_information.lon;
                // qDebug() << "connected:" << system_information.connected;
                break;
            default:
                break;
            }
        }
    }
    mLinkManagerPtr->sendMessage(message_t);
    qDebug() << "dddd";

}
