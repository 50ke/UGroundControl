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
    void sendMessage(const QString &message);

public slots:
    void handleReceivedMessage(const QString &message);

private:
    QThread mMqttLinkWorkThread;
    MqttLink *mMqttLink = nullptr;
};

}
#endif // LINKMANAGER_H
