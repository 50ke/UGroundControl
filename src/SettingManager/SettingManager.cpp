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
    UGC::serialize(jsonObject, mSetting);
    qDebug() << "aaaaaaaaa";
}

void UGC::serialize(const QJsonObject &jsonObject, Setting &setting){
    setting.serialPort = jsonObject.value("serialPort").toString();
}

void UGC::deserialize(QJsonObject &jsonObject, const Setting &setting){
    QJsonObject object{
        {"serialPort", setting.serialPort},
    };
}
