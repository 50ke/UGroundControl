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
    void start();

private:
    MqttLink *mMqttLink = nullptr;
};

}
#endif // LINKMANAGER_H
