#ifndef UGCAPPLICATION_H
#define UGCAPPLICATION_H

#include <QObject>
#include <QQmlContext>

namespace UGC {

class SettingManager;
class LinkManager;
class VehicleManager;
class MockManager;
class LogManager;
class MissionManager;

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
    MissionManager *missionManager(){ return mMissionManagerPtr; }
    MockManager *mockManager(){ return mMockManagerPtr; }

private:
    SettingManager *mSettingManagerPtr;
    LinkManager *mLinkManagerPtr;
    VehicleManager *mVehicleManagerPtr;
    MissionManager *mMissionManagerPtr;
    MockManager *mMockManagerPtr;
};

}

#endif // UGCAPPLICATION_H
