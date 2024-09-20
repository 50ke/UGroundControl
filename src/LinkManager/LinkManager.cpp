#include "LinkManager.h"
#include <SettingManager.h>

UGC::LinkManager::LinkManager(UGCApplication *app) : UGCContext{app}{
    QString networkServer = this->mApp->settingManager()->networkServer();
    mMqttLink = new MqttLink(networkServer, QString::fromStdString("subTopic"), QString::fromStdString("pubTopic"));
}

UGC::LinkManager::~LinkManager(){
    mMqttLinkWorkThread.quit();
    mMqttLinkWorkThread.wait();
}

void UGC::LinkManager::start(){
    mMqttLink->moveToThread(&mMqttLinkWorkThread);
    connect(&mMqttLinkWorkThread, &QThread::started, mMqttLink, &MqttLink::subscribe);
    connect(&mMqttLinkWorkThread, &QThread::finished, mMqttLink, &QObject::deleteLater);
    connect(mMqttLink, &MqttLink::receivedMessage, this, &LinkManager::handleReceivedMessage);
    mMqttLinkWorkThread.start();
}

void UGC::LinkManager::sendMessage(const mavlink_message_t &message){
    mMqttLink->publish(message);
}

void UGC::LinkManager::handleReceivedMessage(const mavlink_message_t &message){
    qDebug() << "LinkManager received msg:" << message.sysid;
    switch (message.msgid) {
    case MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION:
        mavlink_usv_system_information_t system_information;
        mavlink_msg_usv_system_information_decode(&message, &system_information);
        emit receivedSystemInformation(system_information);
        break;
    default:
        break;
    }
}
