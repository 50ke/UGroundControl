#include "UGCApplication.h"
#include <SettingManager.h>

UGC::UGCApplication::UGCApplication(){
    mSettingManagerPtr = new UGC::SettingManager(this);
}
