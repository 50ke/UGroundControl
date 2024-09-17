#include "SettingManager.h"

UGC::SettingManager::SettingManager(UGCApplication *app) : UGCContext{app}{
    QFile file("UGroundControl.json");
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
    if(systemId != mSystemId){
        mSystemId = systemId;
        emit systemIdChanged();
    }
}

void UGC::SettingManager::setSerialPort(const QString &serialPort){
    if(serialPort != mSerialPort){
        mSerialPort = serialPort;
        emit serialPortChanged();
    }
}

void UGC::SettingManager::setNetworkServer(const QString &networkServer){
    if(networkServer != mNetworkServer){
         mNetworkServer = networkServer;
        emit networkServerChanged();
    }
}

void UGC::SettingManager::setBaseMap(const QString &baseMap){
    if(baseMap != mBaseMap){
        mBaseMap = baseMap;
        emit baseMapChanged();
    }
}

void UGC::SettingManager::setWaterwayLayer(const QString &waterwayLayer){
    if(waterwayLayer != mWaterwayLayer){
        mWaterwayLayer = waterwayLayer;
        emit waterwayLayerChanged();
    }
}

void UGC::SettingManager::setNavigationMarkShipLayer(const QString &navigationMarkShipLayer){
    if(navigationMarkShipLayer != mNavigationMarkShipLayer){
        mNavigationMarkShipLayer = navigationMarkShipLayer;
        emit navigationMarkShipLayerChanged();
    }
}

void UGC::SettingManager::setWaterwayDepthLayer(const QString &waterwayDepthLayer){
    if(waterwayDepthLayer != mWaterwayDepthLayer){
        mWaterwayDepthLayer = waterwayDepthLayer;
        emit waterwayDepthLayerChanged();
    }
}

void UGC::SettingManager::setWaterwayAisLayer(const QString &waterwayAisLayer){
    if(waterwayAisLayer != mWaterwayAisLayer){
        mWaterwayAisLayer = waterwayAisLayer;
        emit waterwayAisLayerChanged();
    }
}

void UGC::SettingManager::setWaterwayBuildingLayer(const QString &waterwayBuildingLayer){
    if(waterwayBuildingLayer != mWaterwayBuildingLayer){
        mWaterwayBuildingLayer = waterwayBuildingLayer;
        emit waterwayBuildingLayerChanged();
    }
}

bool UGC::SettingManager::save(const QVariantMap newSetting){
    QFile file("UGroundControl.json");
    try{
        setSerialPort(newSetting.value("serialPort").toString());
        setNetworkServer(newSetting.value("networkServer").toString());
        setBaseMap(newSetting.value("baseMap").toString());
        setWaterwayLayer(newSetting.value("waterwayLayer").toString());
        setNavigationMarkShipLayer(newSetting.value("navigationMarkShipLayer").toString());
        setWaterwayDepthLayer(newSetting.value("waterwayDepthLayer").toString());
        setWaterwayAisLayer(newSetting.value("waterwayAisLayer").toString());
        setWaterwayBuildingLayer(newSetting.value("waterwayBuildingLayer").toString());
        // 保存
        QJsonObject jsonObject = QJsonObject::fromVariantMap(newSetting);
        jsonObject["systemId"] = mSystemId;
        QJsonDocument jsonDocument(jsonObject);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QString jsonString = jsonDocument.toJson();
            file.write(jsonString.toUtf8());
            file.close();
            return true;
        }
    } catch (const std::exception& ex) {
        qCritical() << "Setting Manager Save Error:" << ex.what();
    }
    return false;
}
