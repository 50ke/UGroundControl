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
    qDebug().noquote() << QString("[LinkManager]Received Message, SrcSystemID=%1, TargetSystemID=%2, MsgID=%3, MsgSrc=%4, MsgLink=%5")
                    .arg(message.system_id())
                    .arg(message.target_system_id())
                    .arg(QString::fromStdString(UsvLink::MsgId_Name(message.msg_id())))
                    .arg(QString::fromStdString(UsvLink::MsgSrc_Name(message.msg_src())))
                    .arg(QString::fromStdString(UsvLink::MsgLink_Name(message.msg_link())));
    emit receivedMessage(message);
}
