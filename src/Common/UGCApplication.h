#ifndef UGCAPPLICATION_H
#define UGCAPPLICATION_H

#include <QObject>
#include <QQmlContext>

namespace UGC {

class SettingManager;
class LinkManager;
class VehicleManager;

/**
 * 该类用于启动初始化
 * @brief The UGCApplication class
 */
class UGCApplication : public QObject
{
    Q_OBJECT
public:
    UGCApplication();
    void init(QQmlContext *context);
    SettingManager *settingManager(){ return mSettingManagerPtr; }
    LinkManager *linkManager(){ return mLinkManagerPtr; }
    VehicleManager *vehicleManager(){ return mVehicleManagerPtr; }

private:
    SettingManager *mSettingManagerPtr;
    LinkManager *mLinkManagerPtr;
    VehicleManager *mVehicleManagerPtr;
};

}

#endif // UGCAPPLICATION_H
