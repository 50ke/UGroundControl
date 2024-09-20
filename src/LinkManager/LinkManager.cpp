#include "LinkManager.h"
#include <SettingManager.h>

UGC::LinkManager::LinkManager(UGCApplication *app) : UGCContext{app}{
    QString networkServer = this->mApp->settingManager()->networkServer();
    mMqttLink = new MqttLink(networkServer);
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
    emit receivedMessage(message);
}
