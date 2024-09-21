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
    int systemId;
    QString name;
    float longitude;
    float latitude;
    VehicleType type;
    bool connected;
    bool owner;

    QVariantMap toQVariantMap(){
        QVariantMap data;
        data["systemId"] = this->systemId;
        data["name"] = this->name;
        data["longitude"] = this->longitude;
        data["latitude"] = this->latitude;
        data["type"] = static_cast<int>(this->type);
        data["connected"] = this->connected;
        data["owner"] = this->owner;
        return data;
    }
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
    void vehiclesChanged(const QList<QVariantMap> &vehicles);
    void connectVehicleCompleted(int systemId);
    void disconnectVehicleCompleted(int systemId);

private:
    QMap<int, Vehicle> mVehicles;
    std::unique_ptr<Vehicle> mOwnerVehicleUniquePtr = nullptr;
};

}
#endif // VEHICLEMANAGER_H
