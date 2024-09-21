#ifndef MOCKMANAGER_H
#define MOCKMANAGER_H

#include <QObject>
#include <QThread>
#include <UGCContext.h>
#include <UGCApplication.h>
#include <QTimer>

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
    void publishSystemInfo();
public slots:
    void handleReceivedMessage(const mavlink_message_t &message);

private:
    int mVehicleSystemId{2};
    QString mCommonTopic{"COMMON"};
    QThread mVehicleThread;
    QThread mMqttLinkWorkThread;
    MqttLink *mVehicleMqttLink = nullptr;
};

}
#endif // MOCKMANAGER_H
