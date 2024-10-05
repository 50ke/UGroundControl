#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include <QObject>
#include <QThread>
#include <UGCContext.h>
#include <UGCApplication.h>
#include <QTimer>
#include <QRandomGenerator>

#include <link_protocol.pb.h>

namespace UGC {

class SettingManager;
class MqttLink;

class Heartbeat : public QObject
{
    Q_OBJECT
public:
    explicit Heartbeat(MqttLink *mqttLink);
    void updateConnection(int gcsSystemId, int usvSystemId);
public slots:
    void publishHeartbeat();

private:
    int mConnectedGcsSystemId{0};
    int mConnectedUsvSystemId{0};
    MqttLink *mVehicleMqttLink = nullptr;
};

}
#endif // HEARTBEAT_H
