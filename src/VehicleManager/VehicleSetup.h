#ifndef VEHICLESETUP_H
#define VEHICLESETUP_H

#include <QObject>

class VehicleSetup : public QObject
{
    Q_OBJECT
public:
    explicit VehicleSetup(QObject *parent = nullptr);

signals:
};

#endif // VEHICLESETUP_H
