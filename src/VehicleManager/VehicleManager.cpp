#include "VehicleManager.h"

UGC::VehicleManager::VehicleManager(UGCApplication *app) : UGCContext{app}{
    connect(this->mApp->linkManager(), &LinkManager::receivedSystemInformation, this, VehicleManager::updateVehicles);
}

void UGC::VehicleManager::updateVehicles(const mavlink_usv_system_information_t &system){

}

void UGC::VehicleManager::connectVehicle(int systemId){

}

void UGC::VehicleManager::disconnectVehicle(int systemId){

}
