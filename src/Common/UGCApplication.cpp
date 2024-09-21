#include "UGCApplication.h"
#include <SettingManager.h>
#include <LinkManager.h>
#include <VehicleManager.h>
#include <MockManager.h>
#include <LogManager.h>

UGC::UGCApplication::UGCApplication(){
    LogManager::installHandler();
    mSettingManagerPtr = new UGC::SettingManager(this);
    mLinkManagerPtr = new UGC::LinkManager(this);
    mVehicleManagerPtr = new UGC::VehicleManager(this);
    mMockManagerPtr = new UGC::MockManager(this);
}

void UGC::UGCApplication::init(QQmlContext *context){
    context->setContextProperty("settingManager", mSettingManagerPtr);
    context->setContextProperty("vehicleManager", mVehicleManagerPtr);
    mLinkManagerPtr->start();
    mMockManagerPtr->start();
}
