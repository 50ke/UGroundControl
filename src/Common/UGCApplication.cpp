#include "UGCApplication.h"
#include <SettingManager.h>
#include <LinkManager.h>
#include <VehicleManager.h>

UGC::UGCApplication::UGCApplication(){
    mSettingManagerPtr = new UGC::SettingManager(this);
    mLinkManagerPtr = new UGC::LinkManager(this);
    mVehicleManagerPtr = new UGC::VehicleManager(this);
}

void UGC::UGCApplication::init(QQmlContext *context){
    context->setContextProperty("settingManager", mSettingManagerPtr);
    mLinkManagerPtr->start();
}
