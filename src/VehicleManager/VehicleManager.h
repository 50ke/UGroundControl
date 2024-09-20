#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include <QObject>
#include <QList>

#include <iostream>
#include <memory>

#include <UGCContext.h>
#include <UGCApplication.h>
#include <common/mavlink.h>

namespace UGC {

class LinkManager;
class SettingManager;

enum class VehicleType{
    navigation = 0, // 航标船
    survey = 1 // 测量船
};

struct Vehicle
{
    int mSystemId;
    QString mName;
    float mLongitude;
    float mLatitude;
    VehicleType mType;
};

class VehicleManager : public UGCContext
{
    Q_OBJECT
public:
    explicit VehicleManager(UGCApplication *app);

public slots:
    void handleMessage(const mavlink_message_t &message);
    void connectVehicle(int systemId);
    void disconnectVehicle(int systemId);

signals:
    void vehiclesChanged(const QList<Vehicle> &vehicles);
    void connectVehicleCompleted(int systemId);
    void disconnectVehicleCompleted(int systemId);

private:
    QMap<int, Vehicle> mVehicles;
    std::unique_ptr<Vehicle> mConnectedVehicleUniquePtr = nullptr;
};

}
#endif // VEHICLEMANAGER_H
