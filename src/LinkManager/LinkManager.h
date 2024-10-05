#ifndef LINKMANAGER_H
#define LINKMANAGER_H

#include <QObject>
#include <QThread>
#include <UGCContext.h>
#include <UGCApplication.h>

#include "MqttLink.h"

namespace UGC{

class SettingManager;

class LinkManager : public UGCContext
{
    Q_OBJECT
public:
    explicit LinkManager(UGCApplication *app);
    ~LinkManager();
    void start();
    void sendMessage(int targetSystemId, const UsvLink::MessagePacket &message);

public slots:
    void handleReceivedMessage(const UsvLink::MessagePacket &message);

signals:
    void receivedMessage(const UsvLink::MessagePacket &message);

private:
    QThread mMqttLinkWorkThread;
    MqttLink *mMqttLink = nullptr;
};

}
#endif // LINKMANAGER_H
