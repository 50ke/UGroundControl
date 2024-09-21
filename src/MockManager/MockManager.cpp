#include "MockManager.h"
#include <MqttLink.h>
#include <SettingManager.h>

UGC::MockManager::MockManager(UGCApplication *app) : UGCContext{app}{
    QString networkServer = this->mApp->settingManager()->networkServer();
    mVehicleMqttLink = new MqttLink(networkServer, "USV/" + QString::number(mVehicleSystemId), "usv-mqtt-client-id");
}

UGC::MockManager::~MockManager(){
    mVehicleThread.quit();
    mVehicleThread.wait();

    mMqttLinkWorkThread.quit();
    mMqttLinkWorkThread.wait();
}

void UGC::MockManager::start(){
    mVehicleMqttLink->moveToThread(&mMqttLinkWorkThread);
    connect(&mMqttLinkWorkThread, &QThread::started, mVehicleMqttLink, &MqttLink::subscribe);
    connect(&mMqttLinkWorkThread, &QThread::finished, mVehicleMqttLink, &QObject::deleteLater);
    connect(mVehicleMqttLink, &MqttLink::receivedMessage, this, &MockManager::handleReceivedMessage);
    mMqttLinkWorkThread.start();

    // mVehicleMqttLink->moveToThread(&mMqttLinkWorkThread);
    // connect(&mMqttLinkWorkThread, &QThread::started, this, &MockManager::publishSystemInfo);
    // connect(&mMqttLinkWorkThread, &QThread::finished, this, &QObject::deleteLater);
    // connect(mVehicleMqttLink, &MqttLink::receivedMessage, this, &MockManager::handleReceivedMessage);

    // mMqttLinkWorkThread.start();

    // this->moveToThread(&mVehicleThread);
    // connect(&mVehicleThread, &QThread::started, this, &MockManager::publishSystemInfo);
    // connect(&mVehicleThread, &QThread::finished, this, &QObject::deleteLater);
    // mVehicleThread.start();
}

void UGC::MockManager::publishSystemInfo(){
    while(true){
        mavlink_message_t message;
        mavlink_msg_usv_system_information_pack_chan(2, 0, MAVLINK_COMM_0, &message, "USV02", 0, 12.34, 56.78);
        mVehicleMqttLink->publish(0, message);

        mavlink_msg_usv_system_information_pack_chan(3, 0, MAVLINK_COMM_0, &message, "USV03", 0, 34.34, 56.56);
        mVehicleMqttLink->publish(0, message);
        QThread::msleep(30000);
    }
}

void UGC::MockManager::handleReceivedMessage(const mavlink_message_t &message){
    qDebug() << "USV received msg id: " << message.msgid;
}
