#include "MockManager.h"
#include <LinkManager.h>
#include <SettingManager.h>

UGC::MockManager::MockManager(UGCApplication *app) : UGCContext{app}{

}

UGC::MockManager::~MockManager(){
    mVehicleThread.quit();
    mVehicleThread.wait();
}

void UGC::MockManager::start(){
    this->moveToThread(&mVehicleThread);
    connect(&mVehicleThread, &QThread::started, this, &MockManager::publishSystemInfo);
    connect(&mVehicleThread, &QThread::finished, this, &QObject::deleteLater);
    mVehicleThread.start();
}

void UGC::MockManager::publishSystemInfo(){
    while(true){
        mavlink_message_t message;
        mavlink_msg_usv_system_information_pack_chan(2, 0, MAVLINK_COMM_0, &message, "USV02", 0, 12.34, 56.78);
        this->mApp->linkManager()->sendMessage(0, message);
        QThread::msleep(3000);
    }
}
