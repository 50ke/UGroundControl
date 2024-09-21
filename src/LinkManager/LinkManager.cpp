#include "LinkManager.h"
#include <SettingManager.h>

UGC::LinkManager::LinkManager(UGCApplication *app) : UGCContext{app}{
    QString networkServer = this->mApp->settingManager()->networkServer();
    int systemId = this->mApp->settingManager()->systemId();
    mMqttLink = new MqttLink(networkServer, systemId);
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

void UGC::LinkManager::sendMessage(int targetSystemId, const mavlink_message_t &message){
    mMqttLink->publish(targetSystemId, message);
}

void UGC::LinkManager::handleReceivedMessage(const mavlink_message_t &message){
    qDebug() << "LinkManager Received Msg ID: " << message.msgid << "From System ID: " << message.sysid;
    emit receivedMessage(message);
}
