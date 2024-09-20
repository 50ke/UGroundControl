#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include <QObject>
#include <QList>

#include <iostream>
#include <memory>

#include "Vehicle.h"
#include <UGCContext.h>
#include <UGCApplication.h>
#include <common/mavlink.h>

namespace UGC {

class VehicleManager : public UGCContext
{
    Q_OBJECT
public:
    explicit VehicleManager(UGCApplication *app);

public slots:
    void updateVehicles(const mavlink_usv_system_information_t &system);
    void connectVehicle(int systemId);
    void disconnectVehicle(int systemId);

signals:
    void vehiclesChanged(const QList<Vehicle> &vehicles);
    void connectVehicleCompleted(int systemId);
    void disconnectVehicleCompleted(int systemId);

private:
    QMap<int, Vehicle> mVehicles;
    std::unique_ptr<Vehicle> mConnectedVehiclePtr = nullptr;
};

}
#endif // VEHICLEMANAGER_H
