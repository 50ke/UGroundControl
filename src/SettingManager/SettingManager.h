#ifndef SETTINGMANAGER_H
#define SETTINGMANAGER_H

#include <QObject>
#include <UGCContext.h>
#include <UGCApplication.h>

namespace UGC {

struct Setting{
    QString serialPort;
    QString networkProtocol;
    QString networkAddress;
    QString baseMapType;
    QString baseMapPath;
    QString waterwayLayerType;
    QString waterwayLayerPath;
    QString navigationMarkShipLayerType;
    QString navigationMarkShipLayerPath;
    QString waterwayDepthLayerType;
    QString waterwayDepthLayerPath;
    QString waterwayAisLayerType;
    QString waterwayAisLayerPath;
    QString waterwayBuildingLayerType;
    QString waterwayBuildingLayerPath;
};

class SettingManager : public UGCContext
{
    Q_OBJECT
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString network READ network NOTIFY networkChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)
    // Q_PROPERTY(QString serialPort READ serialPort NOTIFY serialPortChanged)

public:
    explicit SettingManager(UGCApplication *app);

// signals:
//     void loadSettingCompleted();
// public slots:
//     void loadSetting();

private:
    std::unique_ptr<Setting> mSettingUniquePtr;
};

}
#endif // SETTINGMANAGER_H
