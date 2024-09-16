#include "UGCApplication.h"
#include <SettingManager.h>

UGC::UGCApplication::UGCApplication(){
    mSettingManagerPtr = new UGC::SettingManager(this);
}

void UGC::UGCApplication::init(QQmlContext *context){
    context->setContextProperty("settingManager", mSettingManagerPtr);
}
