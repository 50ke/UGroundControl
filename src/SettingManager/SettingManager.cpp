#include "SettingManager.h"

UGC::SettingManager::SettingManager(UGCApplication *app) : UGCContext{app}{
    QFile file(QStringLiteral(":/UGroundControl.json"));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error("Cannot read UGroundControl.json");
    }
    QByteArray byteArray = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray);
    if (jsonDoc.isNull() || !jsonDoc.isObject()){
        throw std::runtime_error("Failed to Parse UGroundControl.json");
    }
    QJsonObject jsonObject = jsonDoc.object();
    this->mSystemId = jsonObject.value("systemId").toInt();
    this->mSerialPort = jsonObject.value("serialPort").toString();
    this->mNetworkServer = jsonObject.value("networkServer").toString();
    this->mBaseMap = jsonObject.value("baseMap").toString();
    this->mWaterwayLayer = jsonObject.value("waterwayLayer").toString();
    this->mNavigationMarkShipLayer = jsonObject.value("navigationMarkShipLayer").toString();
    this->mWaterwayDepthLayer = jsonObject.value("waterwayDepthLayer").toString();
    this->mWaterwayAisLayer = jsonObject.value("waterwayAisLayer").toString();
    this->mWaterwayBuildingLayer = jsonObject.value("waterwayBuildingLayer").toString();
}

void UGC::SettingManager::setSystemId(const int &systemId){
    mSystemId = systemId;
}

void UGC::SettingManager::setSerialPort(const QString &serialPort){
    mSerialPort = serialPort;
}

void UGC::SettingManager::setNetworkServer(const QString &networkServer){
    mNetworkServer = networkServer;
}

void UGC::SettingManager::setBaseMap(const QString &baseMap){
    mBaseMap = baseMap;
}

void UGC::SettingManager::setWaterwayLayer(const QString &waterwayLayer){
    mWaterwayLayer = mWaterwayLayer;
}

void UGC::SettingManager::setNavigationMarkShipLayer(const QString &navigationMarkShipLayer){
    mNavigationMarkShipLayer = navigationMarkShipLayer;
}

void UGC::SettingManager::setWaterwayDepthLayer(const QString &waterwayDepthLayer){
    mWaterwayDepthLayer = waterwayDepthLayer;
}

void UGC::SettingManager::setWaterwayAisLayer(const QString &waterwayAisLayer){
    mWaterwayAisLayer = waterwayAisLayer;
}

void UGC::SettingManager::setWaterwayBuildingLayer(const QString &waterwayBuildingLayer){
    mWaterwayBuildingLayer = waterwayBuildingLayer;
}
