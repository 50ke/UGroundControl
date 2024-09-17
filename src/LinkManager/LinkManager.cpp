#include "LinkManager.h"
#include <SettingManager.h>

UGC::LinkManager::LinkManager(UGCApplication *app) : UGCContext{app}{
    QString networkServer = this->mApp->settingManager()->networkServer();
    mMqttLink = new MqttLink(networkServer.toStdString(), "subTopic", "pubTopic");
}

void UGC::LinkManager::start(){
    QThread *mqttLinkThread = new QThread();
    mMqttLink->moveToThread(mqttLinkThread);
    QObject::connect(mqttLinkThread, &QThread::started, mMqttLink, &MqttLink::doWork);
    mqttLinkThread->start();
}
