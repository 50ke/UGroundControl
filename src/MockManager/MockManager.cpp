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
    connect(&mMqttLinkWorkThread, &QThread::started, mVehicleMqttLink, &MqttLink::start);
    connect(&mMqttLinkWorkThread, &QThread::finished, mVehicleMqttLink, &QObject::deleteLater);
    connect(mVehicleMqttLink, &MqttLink::receivedMessage, this, &MockManager::handleReceivedMessage);
    mMqttLinkWorkThread.start();

    mHeartbeat->moveToThread(&mHeartbeatThread);
    connect(&mHeartbeatThread, &QThread::started, mHeartbeat, &Heartbeat::publishHeartbeat);
    connect(&mHeartbeatThread, &QThread::finished, mHeartbeat, &QObject::deleteLater);
    mHeartbeatThread.start();
}

void UGC::MockManager::handleReceivedMessage(const UsvLink::MessagePacket &message){
    qDebug().noquote() << "[MockManager]USV Received Message ID" << UsvLink::MsgId_Name(message.msg_id());
    if(message.msg_id() == UsvLink::MsgId::MSG_ID_CONNECT_REQUEST){
        if(mGcsSystemId == 0){
            mGcsSystemId = message.system_id();
            mHeartbeat->updateConnection(message.system_id(), mVehicleSystemId);
        }

        UsvLink::ConnectResponse *connectResponse = new UsvLink::ConnectResponse;
        connectResponse->set_ack(mGcsSystemId == message.system_id() ? 1 : 0);
        connectResponse->set_allocated_err_msg(mGcsSystemId == message.system_id() ? new std::string("success") : new std::string("failed"));

        UsvLink::MessagePacket packet;
        packet.set_msg_id(UsvLink::MsgId::MSG_ID_CONNECT_RESPONSE);
        packet.set_system_id(mVehicleSystemId);
        packet.set_component_id(0);
        packet.set_target_system_id(message.system_id());
        packet.set_target_component_id(0);
        packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
        packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_USV);
        packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
        packet.set_allocated_connect_response(connectResponse);
        mVehicleMqttLink->publish("GCS/" + QString::number(message.system_id()), packet);

    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_DISCONNECT_REQUEST){
        if(mGcsSystemId == message.system_id()){
            mGcsSystemId = 0;
            mHeartbeat->updateConnection(0, 0);
        }

        UsvLink::DisconnectResponse *disconnectResponse = new UsvLink::DisconnectResponse();
        disconnectResponse->set_ack(mGcsSystemId == 0 ? 1 : 0);
        disconnectResponse->set_allocated_err_msg(mGcsSystemId == 0 ? new std::string("success") : new std::string("failed"));

        UsvLink::MessagePacket packet;
        packet.set_msg_id(UsvLink::MsgId::MSG_ID_CONNECT_RESPONSE);
        packet.set_system_id(mVehicleSystemId);
        packet.set_component_id(0);
        packet.set_target_system_id(message.system_id());
        packet.set_target_component_id(0);
        packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
        packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_USV);
        packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
        packet.set_allocated_disconnect_response(disconnectResponse);
        mVehicleMqttLink->publish("GCS/" + QString::number(message.system_id()), packet);
    }
}
