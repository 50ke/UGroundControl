#ifndef SETTINGMANAGER_H
#define SETTINGMANAGER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <UGCContext.h>
#include <UGCApplication.h>

namespace UGC {

class SettingManager : public UGCContext
{
    Q_OBJECT

public:
    Q_PROPERTY(int systemId READ systemId WRITE setSystemId NOTIFY systemIdChanged)
    Q_PROPERTY(QString serialPort READ serialPort WRITE setSerialPort NOTIFY serialPortChanged)
    Q_PROPERTY(QString networkServer READ networkServer WRITE setNetworkServer NOTIFY networkServerChanged)
    Q_PROPERTY(QString baseMap READ baseMap WRITE setBaseMap NOTIFY baseMapChanged)
    Q_PROPERTY(QString waterwayLayer READ waterwayLayer WRITE setWaterwayLayer NOTIFY waterwayLayerChanged)
    Q_PROPERTY(QString navigationMarkShipLayer READ navigationMarkShipLayer WRITE setNavigationMarkShipLayer NOTIFY navigationMarkShipLayerChanged)
    Q_PROPERTY(QString waterwayDepthLayer READ waterwayDepthLayer WRITE setWaterwayDepthLayer NOTIFY waterwayDepthLayerChanged)
    Q_PROPERTY(QString waterwayAisLayer READ waterwayAisLayer WRITE setWaterwayAisLayer NOTIFY waterwayAisLayerChanged)
    Q_PROPERTY(QString waterwayBuildingLayer READ waterwayBuildingLayer WRITE setWaterwayBuildingLayer NOTIFY waterwayBuildingLayerChanged)

    int systemId() const { return mSystemId; }
    QString serialPort() const { return mSerialPort; }
    QString networkServer() const { return mNetworkServer; }
    QString baseMap() const { return mBaseMap; }
    QString waterwayLayer() const { return mWaterwayLayer; }
    QString navigationMarkShipLayer() const { return mNavigationMarkShipLayer; }
    QString waterwayDepthLayer() const { return mWaterwayDepthLayer; }
    QString waterwayAisLayer() const { return mWaterwayAisLayer; }
    QString waterwayBuildingLayer() const { return mWaterwayBuildingLayer; }

    void setSystemId (const int &systemId);
    void setSerialPort (const QString &serialPort);
    void setNetworkServer (const QString &networkServer);
    void setBaseMap (const QString &baseMap);
    void setWaterwayLayer (const QString &waterwayLayer);
    void setNavigationMarkShipLayer (const QString &navigationMarkShipLayer);
    void setWaterwayDepthLayer (const QString &waterwayDepthLayer);
    void setWaterwayAisLayer (const QString &waterwayAisLayer);
    void setWaterwayBuildingLayer (const QString &waterwayBuildingLayer);

    explicit SettingManager(UGCApplication *app);

signals:
    void systemIdChanged();
    void serialPortChanged();
    void networkServerChanged();
    void baseMapChanged();
    void waterwayLayerChanged();
    void navigationMarkShipLayerChanged();
    void waterwayDepthLayerChanged();
    void waterwayAisLayerChanged();
    void waterwayBuildingLayerChanged();

private:
    int mSystemId;
    QString mSerialPort{};
    QString mNetworkServer{};
    QString mBaseMap{};
    QString mWaterwayLayer{};
    QString mNavigationMarkShipLayer{};
    QString mWaterwayDepthLayer{};
    QString mWaterwayAisLayer{};
    QString mWaterwayBuildingLayer{};
};

}
#endif // SETTINGMANAGER_H
