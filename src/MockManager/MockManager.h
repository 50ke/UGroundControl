#ifndef MOCKMANAGER_H
#define MOCKMANAGER_H

#include <QObject>
#include <QThread>
#include <UGCContext.h>
#include <UGCApplication.h>
#include <QTimer>
#include "Heartbeat.h"

#include <common/mavlink.h>

namespace UGC {

class SettingManager;
class MqttLink;

class MockManager : public UGCContext
{
    Q_OBJECT
public:
    explicit MockManager(UGCApplication *app);
    ~MockManager();
    void start();
public slots:
    void handleReceivedMessage(const mavlink_message_t &message);
    void publishSystemInfo();

private:
    int mVehicleSystemId{2};
    QString mCommonTopic{"COMMON"};
    QThread mHeartbeatThread;
    QThread mMqttLinkWorkThread;
    MqttLink *mVehicleMqttLink = nullptr;
    Heartbeat *mHeartbeat = nullptr;
};

}
#endif // MOCKMANAGER_H
