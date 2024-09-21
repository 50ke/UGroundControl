#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include <QObject>
#include <QThread>
#include <UGCContext.h>
#include <UGCApplication.h>
#include <QTimer>

#include <common/mavlink.h>

namespace UGC {

class SettingManager;
class MqttLink;

class Heartbeat : public QObject
{
    Q_OBJECT
public:
    explicit Heartbeat(MqttLink *mqttLink);
    void updateConnectedUsvSystemId(int systemId);
public slots:
    void publishSystemInfo();

private:
    int mconnectedUsvSystemId{0};
    MqttLink *mVehicleMqttLink = nullptr;
};

}
#endif // HEARTBEAT_H
