#ifndef MISSIONMANAGER_H
#define MISSIONMANAGER_H

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
class VehicleManager;

class MissionManager : public UGCContext
{
    Q_OBJECT
public:
    explicit MissionManager(UGCApplication *app);
    void handleMessage(const UsvLink::MessagePacket &message);
    Q_INVOKABLE QList<QVariantMap> loadMissionMetadata();
    Q_INVOKABLE QVariantMap getDefaultMissionItem();
    Q_INVOKABLE int getMissionTypeIdByName(QString name);
    Q_INVOKABLE QString getMissionTypeNameById(int id);

    Q_INVOKABLE void clearMission();
    Q_INVOKABLE void uploadMission(const QList<QVariantMap> &missionItems);
    Q_INVOKABLE void downloadMission();
    // 地图操作
    Q_INVOKABLE void addWaypoint(QGeoCoordinate waypoint);
    Q_INVOKABLE void updateWaypoint(int index, QGeoCoordinate waypoint);
    Q_INVOKABLE void removeWaypoint(int index);
    Q_INVOKABLE void clearWaypoint();
    Q_INVOKABLE void editMissionItem(int index, QVariantMap missionItem);

signals:
    void clearMissionCompleted();
    void uploadMissionCompleted();
    void downloadMissionCompleted(QList<QVariantMap> missionItems);
    void currentMissionItemChanged(int currentMissionItemSeq);

    void waypointAdded(QGeoCoordinate waypoint);
    void waypointUpdated(int index, QGeoCoordinate waypoint);
    void waypointRemoved(int index);
    void waypointCleared();
    void missionItemEdited(int index, QVariantMap missionItem);

private:
    int mCurrentMissionId{0};
    int mCurrentMissionItemSeq;
    QList<QVariantMap> mCurrentMissionItems;
};

}

#endif // MISSIONMANAGER_H
