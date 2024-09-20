#include "UGCApplication.h"
#include <SettingManager.h>
#include <LinkManager.h>
#include <VehicleManager.h>
#include <MockManager.h>

UGC::UGCApplication::UGCApplication(){
    mSettingManagerPtr = new UGC::SettingManager(this);
    mLinkManagerPtr = new UGC::LinkManager(this);
    mVehicleManagerPtr = new UGC::VehicleManager(this);
    mMockManagerPtr = new UGC::MockManager(this);
}

void UGC::UGCApplication::init(QQmlContext *context){
    context->setContextProperty("settingManager", mSettingManagerPtr);
    mLinkManagerPtr->start();
    mMockManagerPtr->start();
}
