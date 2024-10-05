#include "MockManager.h"
#include <MqttLink.h>
#include <SettingManager.h>

UGC::MockManager::MockManager(UGCApplication *app) : UGCContext{app}{
    QString networkServer = this->mApp->settingManager()->networkServer();
    mVehicleMqttLink = new MqttLink(networkServer, "USV/" + QString::number(mVehicleSystemId), "usv-mqtt-client-id");
    mHeartbeat = new Heartbeat(mVehicleMqttLink);

    paramItem1.set_allocated_param_id(new std::string("PID"));
    paramItem1.set_param_value(45);
    paramItem1.set_param_index(0);

    paramItem2.set_allocated_param_id(new std::string("最大速度(km/h)"));
    paramItem2.set_param_value(30);
    paramItem2.set_param_index(1);

    paramItem3.set_allocated_param_id(new std::string("盘旋半径(m)"));
    paramItem3.set_param_value(1.5);
    paramItem3.set_param_index(2);
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
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_PARAM_READ_REQUEST){
        UsvLink::ParamReadRequest paramReadRequest = message.param_read_request();

        UsvLink::ParamReadResponse *paramReadResponse = new UsvLink::ParamReadResponse();
        paramReadResponse->set_ack(1);
        if(paramReadRequest.param_index() == -1){
            paramReadResponse->add_param_items()->CopyFrom(paramItem1);
            paramReadResponse->add_param_items()->CopyFrom(paramItem2);
            paramReadResponse->add_param_items()->CopyFrom(paramItem3);
        }else if(paramReadRequest.param_index() == 0){
            paramReadResponse->add_param_items()->CopyFrom(paramItem1);
        }else if(paramReadRequest.param_index() == 1){
            paramReadResponse->add_param_items()->CopyFrom(paramItem2);
        }else if(paramReadRequest.param_index() == 2){
            paramReadResponse->add_param_items()->CopyFrom(paramItem3);
        }

        UsvLink::MessagePacket packet;
        packet.set_msg_id(UsvLink::MsgId::MSG_ID_PARAM_READ_RESPONSE);
        packet.set_system_id(mVehicleSystemId);
        packet.set_component_id(0);
        packet.set_target_system_id(message.system_id());
        packet.set_target_component_id(0);
        packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
        packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_USV);
        packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
        packet.set_allocated_param_read_response(paramReadResponse);
        mVehicleMqttLink->publish("GCS/" + QString::number(message.system_id()), packet);
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_PARAM_WRITE_REQUEST){
        UsvLink::ParamWriteRequest paramWriteRequest = message.param_write_request();
        for (UsvLink::ParamItem param: paramWriteRequest.param_items()) {
            if(param.param_index() == 0){
                paramItem1.set_param_value(param.param_value());
            }else if(param.param_index() == 1){
                paramItem2.set_param_value(param.param_value());
            }else if(param.param_index() == 2){
                paramItem3.set_param_value(param.param_value());
            }
        }

        UsvLink::ParamWriteResponse *paramWriteResponse = new UsvLink::ParamWriteResponse();
        paramWriteResponse->set_ack(1);

        UsvLink::MessagePacket packet;
        packet.set_msg_id(UsvLink::MsgId::MSG_ID_PARAM_WRITE_RESPONSE);
        packet.set_system_id(mVehicleSystemId);
        packet.set_component_id(0);
        packet.set_target_system_id(message.system_id());
        packet.set_target_component_id(0);
        packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
        packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_USV);
        packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
        packet.set_allocated_param_write_response(paramWriteResponse);
        mVehicleMqttLink->publish("GCS/" + QString::number(message.system_id()), packet);
    }
}
