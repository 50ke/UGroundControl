#include "MockManager.h"
#include <MqttLink.h>
#include <SettingManager.h>

UGC::MockManager::MockManager(UGCApplication *app) : UGCContext{app}{
    QString networkServer = this->mApp->settingManager()->networkServer();
    mVehicleMqttLink = new MqttLink(networkServer, "USV/" + QString::number(mVehicleSystemId), "usv-mqtt-client-id");
    mHeartbeat = new Heartbeat(mVehicleMqttLink);
}

UGC::MockManager::~MockManager(){
    mHeartbeatThread.quit();
    mHeartbeatThread.wait();

    mMqttLinkWorkThread.quit();
    mMqttLinkWorkThread.wait();
}

void UGC::MockManager::start(){
    mVehicleMqttLink->moveToThread(&mMqttLinkWorkThread);
    connect(&mMqttLinkWorkThread, &QThread::started, mVehicleMqttLink, &MqttLink::subscribe);
    connect(&mMqttLinkWorkThread, &QThread::finished, mVehicleMqttLink, &QObject::deleteLater);
    connect(mVehicleMqttLink, &MqttLink::receivedMessage, this, &MockManager::handleReceivedMessage);
    mMqttLinkWorkThread.start();

    mHeartbeat->moveToThread(&mHeartbeatThread);
    connect(&mHeartbeatThread, &QThread::started, mHeartbeat, &Heartbeat::publishSystemInfo);
    connect(&mHeartbeatThread, &QThread::finished, mHeartbeat, &QObject::deleteLater);
    mHeartbeatThread.start();
}

void UGC::MockManager::publishSystemInfo(){
    while(true){
        mavlink_message_t message;
        mavlink_msg_usv_system_information_pack_chan(2, 0, MAVLINK_COMM_0, &message, "USV02", 0, 12.34, 56.78);
        mVehicleMqttLink->publish(0, message);

        mavlink_msg_usv_system_information_pack_chan(3, 0, MAVLINK_COMM_0, &message, "USV03", 0, 34.34, 56.56);
        mVehicleMqttLink->publish(0, message);
        QThread::msleep(5000);
    }
}

void UGC::MockManager::handleReceivedMessage(const mavlink_message_t &message){
    if(message.msgid == MAVLINK_MSG_ID_USV_CONNECT_REQUEST){
        if(mGcsSystemId != 0 && mGcsSystemId != message.sysid){
            mavlink_message_t message_t;
            mavlink_msg_usv_connect_response_pack_chan(mVehicleSystemId, 0, MAVLINK_COMM_0, &message_t, message.sysid, 0);
            mVehicleMqttLink->publish("GCS/" + QString::number(message.sysid), message_t);
        }else{
            mGcsSystemId = message.sysid;
            mavlink_message_t message_t;
            mavlink_msg_usv_connect_response_pack_chan(mVehicleSystemId, 0, MAVLINK_COMM_0, &message_t, message.sysid, 1);
            mVehicleMqttLink->publish("GCS/" + QString::number(message.sysid), message_t);
            mHeartbeat->updateConnectedUsvSystemId(mVehicleSystemId);
        }
    }else if(message.msgid == MAVLINK_MSG_ID_USV_DISCONNECT_REQUEST){
        if(mGcsSystemId != 0 && mGcsSystemId != message.sysid){
            mavlink_message_t message_t;
            mavlink_msg_usv_disconnect_response_pack_chan(mVehicleSystemId, 0, MAVLINK_COMM_0, &message_t, message.sysid, 0);
            mVehicleMqttLink->publish("GCS/" + QString::number(message.sysid), message_t);
        }else{
            mGcsSystemId = message.sysid;
            mavlink_message_t message_t;
            mavlink_msg_usv_disconnect_response_pack_chan(mVehicleSystemId, 0, MAVLINK_COMM_0, &message_t, message.sysid, 1);
            mVehicleMqttLink->publish("GCS/" + QString::number(message.sysid), message_t);
            mHeartbeat->updateConnectedUsvSystemId(0);
        }
    }
    qDebug() << "USV received msg id: " << message.msgid;
}
