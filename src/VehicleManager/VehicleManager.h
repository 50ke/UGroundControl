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
    Q_INVOKABLE void connectVehicle(int systemId);
    Q_INVOKABLE void disconnectVehicle(int systemId);
    Q_INVOKABLE void getVehicles();

signals:
    void vehiclesChanged(const QList<QVariantMap> &vehicles);
    void connectVehicleCompleted(int systemId, bool ack);
    void disconnectVehicleCompleted(int systemId, bool ack);

private:
    QMap<int, Vehicle> mVehicles;
    int mOwnerVehicleSystemId;
};

}
#endif // VEHICLEMANAGER_H
