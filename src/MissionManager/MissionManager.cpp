#include "MissionManager.h"
#include <LinkManager.h>
#include <SettingManager.h>
#include <VehicleManager.h>

UGC::MissionManager::MissionManager(UGCApplication *app) : UGCContext{app}{

}

void UGC::MissionManager::handleMessage(const UsvLink::MessagePacket &message){
    if(this->mApp->vehicleManager()->ownVehicleSystemId() == 0 || message.system_id() != this->mApp->vehicleManager()->ownVehicleSystemId()){
        qDebug() << "[MissionManager]Vehicle System ID Cannot Match";
    }
    if(message.msg_id() == UsvLink::MsgId::MSG_ID_MISSION_CURRENT && message.mission_current().mission_id() == mCurrentMissionId){
        mCurrentMissionItemSeq = message.mission_current().mission_item().seq();
        emit currentMissionItemChanged(mCurrentMissionItemSeq);
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_MISSION_CLEAR_RESPONSE && message.mission_clear_response().ack()){
        mCurrentMissionId = 0;
        emit clearMissionCompleted();
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_MISSION_UPLOAD_RESPONSE && message.mission_upload_response().ack()){
        mCurrentMissionId = message.mission_upload_response().opaque_id();
        emit uploadMissionCompleted();
    }else if(message.msg_id() == UsvLink::MsgId::MSG_ID_MISSION_DOWNLOAD_RESPONSE && message.mission_download_response().ack()){
        mCurrentMissionItems.clear();
        for (UsvLink::MissionItem item: message.mission_download_response().mission_items()) {
            QVariantMap temp = {
                {"seq", item.seq()},
                {"latitude", item.x()},
                {"longitude", item.y()},
                {"command", "起锚"},
            };
            mCurrentMissionItems.append(temp);
        }
        emit downloadMissionCompleted(mCurrentMissionItems);
    }

}

QList<QVariantMap> UGC::MissionManager::loadMissionMetadata(){
    QList<QVariantMap> data;
    data.append({
        {"cmdId", 0},
        {"cmdName", "导航"},
        {"paramDesc1", "停留时间(秒)"},
        {"paramValue1", 0},
        {"paramEditable1", true},
        {"paramDesc2", "到达半径(米)"},
        {"paramValue2", 1},
        {"paramEditable2", true},
        {"paramDesc3", "穿越半径(米)"},
        {"paramValue3", 0.5},
        {"paramEditable3", true},
        {"paramDesc4", "偏航角(度)"},
        {"paramValue4", 0},
        {"paramEditable4", true},
        {"paramDesc5", "空"},
        {"paramValue5", 0},
        {"paramEditable5", false},
        {"paramDesc6", "空"},
        {"paramValue6", 0},
        {"paramEditable6", false},
        {"paramDesc7", "空"},
        {"paramValue7", 0},
        {"paramEditable7", false}
    });
    data.append({
        {"cmdId", 1},
        {"cmdName", "起锚"},
        {"paramValue1", -1},
        {"paramDesc1", "起锚长度(m)，-1表示收回全部锚链"},
        {"paramEditable1", true},
        {"paramValue2", 0},
        {"paramDesc2", "空"},
        {"paramEditable2", false},
        {"paramValue3", 0},
        {"paramDesc3", "空"},
        {"paramEditable3", false},
        {"paramValue4", 0},
        {"paramDesc4", "空"},
        {"paramEditable4", false},
        {"paramValue5", 0},
        {"paramDesc5", "空"},
        {"paramEditable5", false},
        {"paramValue6", 0},
        {"paramDesc6", "空"},
        {"paramEditable6", false},
        {"paramValue7", 0},
        {"paramDesc7", "空"},
        {"paramEditable7", false},
    });
    data.append({
                 {"cmdId", 2},
                 {"cmdName", "抛锚"},
                 {"paramValue1", -1},
                 {"paramDesc1", "抛锚长度(m)，-1表示抛出全部锚链"},
                 {"paramEditable1", true},
                 {"paramValue2", 0},
                 {"paramDesc2", "空"},
                 {"paramEditable2", false},
                 {"paramValue3", 0},
                 {"paramDesc3", "空"},
                 {"paramEditable3", false},
                 {"paramValue4", 0},
                 {"paramDesc4", "空"},
                 {"paramEditable4", false},
                 {"paramValue5", 0},
                 {"paramDesc5", "空"},
                 {"paramEditable5", false},
                 {"paramValue6", 0},
                 {"paramDesc6", "空"},
                 {"paramEditable6", false},
                 {"paramValue7", 0},
                 {"paramDesc7", "空"},
                 {"paramEditable7", false},
                 });
    return data;
}

QVariantMap UGC::MissionManager::getDefaultMissionItem(){
    return {
            {"cmdId", 0},
            {"cmdName", "导航"},
            {"paramValue1", 0},
            {"paramValue2", 1},
            {"paramValue3", 0.5},
            {"paramValue4", 0},
            {"paramValue5", 0},
            {"paramValue6", 0},
            {"paramValue7", 0},
    };
}

int UGC::MissionManager::getMissionTypeIdByName(QString name){
    if(name == "导航"){
        return 0;
    }else if(name == "起锚"){
        return 1;
    }else if(name == "抛锚"){
        return 2;
    }else{
        return -1;
    }
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

void UGC::MissionManager::uploadMission(const QList<QVariantMap> &missionItems){
    qDebug() << "[MissionManager]Requesting to upload mission";
    if(this->mApp->vehicleManager()->ownVehicleSystemId() == 0){
        return;
    }
    UsvLink::MissionUploadRequest *payload  = new UsvLink::MissionUploadRequest();
    for (int i = 0; i < missionItems.size(); ++i) {
        QVariantMap map = missionItems[i];
        UsvLink::MissionItem missionItem;

        missionItem.set_seq(i);
        missionItem.set_frame(UsvLink::Frame::FRAME_GLOBAL);
        missionItem.set_current(i == 0);
        missionItem.set_auto_continue(true);
        missionItem.set_x(map["latitude"].toFloat());
        missionItem.set_y(map["longitude"].toFloat());
        missionItem.set_z(0.0);

        UsvLink::Command *cmd = new UsvLink::Command();
        cmd->set_cmd_id(static_cast<UsvLink::CmdId>(map["cmdId"].toInt()));
        cmd->set_param1(map["paramValue1"].toFloat());
        cmd->set_param2(map["paramValue2"].toFloat());
        cmd->set_param3(map["paramValue3"].toFloat());
        cmd->set_param4(map["paramValue4"].toFloat());
        cmd->set_param5(map["paramValue5"].toFloat());
        cmd->set_param6(map["paramValue6"].toFloat());
        cmd->set_param7(map["paramValue7"].toFloat());
        missionItem.set_allocated_command(cmd);

        payload->add_mission_items()->CopyFrom(missionItem);
    }

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_MISSION_UPLOAD_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(this->mApp->vehicleManager()->ownVehicleSystemId());
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_mission_upload_request(payload);
    this->mApp->linkManager()->sendMessage(this->mApp->vehicleManager()->ownVehicleSystemId(), packet);
}

void UGC::MissionManager::downloadMission(){
    qDebug() << "[MissionManager]Requesting to download mission";
    if(this->mApp->vehicleManager()->ownVehicleSystemId() == 0){
        return;
    }

    UsvLink::MissionDownloadRequest *payload  = new UsvLink::MissionDownloadRequest();

    UsvLink::MessagePacket packet;
    packet.set_msg_id(UsvLink::MsgId::MSG_ID_MISSION_DOWNLOAD_REQUEST);
    packet.set_system_id(this->mApp->settingManager()->systemId());
    packet.set_component_id(0);
    packet.set_target_system_id(this->mApp->vehicleManager()->ownVehicleSystemId());
    packet.set_target_component_id(0);
    packet.set_time_ms(QDateTime::currentMSecsSinceEpoch());
    packet.set_msg_src(UsvLink::MsgSrc::MSG_SRC_GCS);
    packet.set_msg_link(UsvLink::MsgLink::MSG_LINK_MQTT);
    packet.set_allocated_mission_download_request(payload);
    this->mApp->linkManager()->sendMessage(this->mApp->vehicleManager()->ownVehicleSystemId(), packet);
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

void UGC::MissionManager::editMissionItem(int index, QVariantMap missionItem){
    emit missionItemEdited(index, missionItem);
}
