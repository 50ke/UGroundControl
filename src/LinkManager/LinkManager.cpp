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
    connect(&mMqttLinkWorkThread, &QThread::started, mMqttLink, &MqttLink::start);
    connect(&mMqttLinkWorkThread, &QThread::finished, mMqttLink, &QObject::deleteLater);
    connect(mMqttLink, &MqttLink::receivedMessage, this, &LinkManager::handleReceivedMessage);
    mMqttLinkWorkThread.start();
}

void UGC::LinkManager::sendMessage(int targetSystemId, const UsvLink::MessagePacket &message){
    mMqttLink->publish(targetSystemId, message);
}

void UGC::LinkManager::handleReceivedMessage(const UsvLink::MessagePacket &message){
    qDebug() << "LinkManager Received Message: " << message.SerializeAsString();
    emit receivedMessage(message);
}
