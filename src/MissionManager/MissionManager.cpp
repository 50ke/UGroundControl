#include "MissionManager.h"

UGC::MissionManager::MissionManager(UGCApplication *app) : UGCContext{app}{

}

void UGC::MissionManager::clearCurrentMission(){

}

void UGC::MissionManager::uploadMission(){

}

void UGC::MissionManager::downloadMission(){

}


void UGC::MissionManager::addWaypoint(QGeoCoordinate waypoint){
    qDebug() << "地图打点" << waypoint.latitude();
    emit waypointAdded(waypoint);
}

void UGC::MissionManager::updateWaypoint(int index, QGeoCoordinate waypoint){
    emit waypointUpdated(index, waypoint);
}

void UGC::MissionManager::removeWaypoint(int index){
    emit waypointRemoved(index);
}

void UGC::MissionManager::clearWaypoint(){
    emit waypointCleared();
}
