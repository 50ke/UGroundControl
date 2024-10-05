#ifndef MOCKMANAGER_H
#define MOCKMANAGER_H

#include <QObject>
#include <QThread>
#include <UGCContext.h>
#include <UGCApplication.h>
#include <QTimer>
#include <QDateTime>
#include "Heartbeat.h"

#include <link_protocol.pb.h>
#include <msg_enum.pb.h>

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
    void handleReceivedMessage(const UsvLink::MessagePacket &message);

private:
    int mVehicleSystemId{2};
    int mGcsSystemId{0};
    QString mCommonTopic{"COMMON"};
    QThread mHeartbeatThread;
    QThread mMqttLinkWorkThread;
    MqttLink *mVehicleMqttLink = nullptr;
    Heartbeat *mHeartbeat = nullptr;
};

}
#endif // MOCKMANAGER_H
