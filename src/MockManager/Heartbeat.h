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
public slots:
    void publishSystemInfo();

private:
    MqttLink *mVehicleMqttLink = nullptr;
};

}
#endif // HEARTBEAT_H
