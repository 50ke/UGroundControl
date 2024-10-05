#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include <QObject>
#include <QList>
#include <QtPositioning/QGeoCoordinate>

#include <iostream>
#include <memory>

#include <UGCContext.h>
#include <UGCApplication.h>
#include <link_protocol.pb.h>

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
    void handleMessage(const UsvLink::MessagePacket &message);
    void clear();
    void requestVehicleParams();
    Q_INVOKABLE void connectVehicle(int systemId);
    Q_INVOKABLE void disconnectVehicle(int systemId);
    Q_INVOKABLE void getVehicles();
    Q_INVOKABLE QList<QVariantMap> readVehicleParams();
    Q_INVOKABLE void readVehicleParam(QString paramId);
    Q_INVOKABLE void writeVehicleParam(QString paramId, float paramValue);

signals:
    void vehiclesChanged(const QList<QVariantMap> &vehicles);
    void connectVehicleCompleted(int systemId, bool ack);
    void disconnectVehicleCompleted(int systemId, bool ack);
    void vehicleTrajectoryChanged(QGeoCoordinate waypoint);
    void readVehicleParamsCompleted(QList<QVariantMap> params);

private:
    QMap<int, Vehicle> mVehicles;
    int mOwnerVehicleSystemId;
    QMap<QString, QVariantMap> mOwnerVehicleParams;
    QList<QGeoCoordinate> mOwnerVehicleTrajectory;
};

}
#endif // VEHICLEMANAGER_H
