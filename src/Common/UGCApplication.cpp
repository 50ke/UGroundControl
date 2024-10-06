#include "UGCApplication.h"
#include <SettingManager.h>
#include <LinkManager.h>
#include <VehicleManager.h>
#include <MockManager.h>
#include <LogManager.h>
#include <MissionManager.h>

#include <link_protocol.pb.h>
#include <msg_connect_response.pb.h>

UGC::UGCApplication::UGCApplication(){
    LogManager::installHandler();
    mSettingManagerPtr = new UGC::SettingManager(this);
    mLinkManagerPtr = new UGC::LinkManager(this);
    mVehicleManagerPtr = new UGC::VehicleManager(this);
    mMissionManagerPtr = new UGC::MissionManager(this);
    mMockManagerPtr = new UGC::MockManager(this);

    // MessagePacket packet;
    // packet.set_msg_id(1);
    // packet.set_component_id(0);
    // packet.set_target_system_id(2);
    // packet.set_target_component_id(0);
    // packet.set_time_ms();
    // packet.set_msg_src();
    // packet.set_msg_link();
    // UsvLink::ConnectResponse data;
    // data.set_ack(1);
    // data.set_allocated_err_msg(new std::string("ok"));
    // qDebug() << "---------------" << data.DebugString();
    // qDebug() << "---------------" << data.SerializeAsString();
    // qDebug() << "---------------" << data.SerializeAsString().data();
    // std::vector<uchar> buff(data.ByteSizeLong());
    // data.SerializeToArray(buff.data(), buff.size());
    // UsvLink::ConnectResponse pack;
    // pack.ParseFromString(data.SerializeAsString());
    // qDebug() << "======================" << pack.DebugString();
    // UsvLink::ConnectResponse pack1;
    // pack1.ParseFromArray(buff.data(), buff.size());
    // qDebug() << "==========000000000000: " << pack1.DebugString();
}

void UGC::UGCApplication::init(QQmlContext *context){
    context->setContextProperty("settingManager", mSettingManagerPtr);
    context->setContextProperty("vehicleManager", mVehicleManagerPtr);
    context->setContextProperty("missionManager", mMissionManagerPtr);
    mLinkManagerPtr->start();
    mMockManagerPtr->start();
}
