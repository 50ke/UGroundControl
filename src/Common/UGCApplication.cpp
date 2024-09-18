#include "UGCApplication.h"
#include <SettingManager.h>
#include <LinkManager.h>

UGC::UGCApplication::UGCApplication(){
    mSettingManagerPtr = new UGC::SettingManager(this);
    mLinkManagerPtr = new UGC::LinkManager(this);
}

void UGC::UGCApplication::init(QQmlContext *context){
    context->setContextProperty("settingManager", mSettingManagerPtr);
    mLinkManagerPtr->start();
    mLinkManagerPtr->sendMessage("I AM UGC.");
}
