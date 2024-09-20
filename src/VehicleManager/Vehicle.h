#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>

namespace UGC {

enum class VehicleType{
    navigation = 0, // 航标船
    survey = 1 // 测量船
};

class Vehicle : public QObject
{
    Q_OBJECT
public:
    explicit Vehicle(int systemId, QString name, VehicleType type);

private:
    int mSystemId;
    QString mName;
    VehicleType mType;
};

}
#endif // VEHICLE_H
