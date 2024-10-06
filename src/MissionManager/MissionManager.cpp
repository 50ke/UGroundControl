#include "MissionManager.h"
#include <LinkManager.h>
#include <SettingManager.h>
#include <VehicleManager.h>

UGC::MissionManager::MissionManager(UGCApplication *app) : UGCContext{app}{

}

void UGC::MissionManager::clearMission(){
    qDebug() << "[MissionManager]Requesting to clear mission";
    if(this->mApp->vehicleManager()->ownVehicleSystemId() == 0){
        return;
    }

    UsvLink::MissionClearRequest *payload  = new UsvLink::MissionClearRequest();

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_MISSION_CLEAR_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(this->mApp->vehicleManager()->ownVehicleSystemId());
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_mission_clear_request(payload);
    this->mApp->linkManager()->sendMessage(this->mApp->vehicleManager()->ownVehicleSystemId(), packet);
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
