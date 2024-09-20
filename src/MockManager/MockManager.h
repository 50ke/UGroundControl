#ifndef MOCKMANAGER_H
#define MOCKMANAGER_H

#include <QObject>
#include <QThread>
#include <UGCContext.h>
#include <UGCApplication.h>

namespace UGC {

class LinkManager;
class SettingManager;

class MockManager : public UGCContext
{
    Q_OBJECT
public:
    explicit MockManager(UGCApplication *app);
    ~MockManager();
    void start();
    void publishSystemInfo();

private:
    QThread mVehicleThread;
};

}
#endif // MOCKMANAGER_H
