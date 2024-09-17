#ifndef MQTTLINK_H
#define MQTTLINK_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <memory>
#include <mqtt/async_client.h>

namespace UGC {

class MqttLink : public QObject
{
    Q_OBJECT

public:
    MqttLink(std::string serverAddr, std::string subTopic, std::string pubTopic);
    void stop();
    void sendMessage(std::string payload);

public slots:
    void doWork();

private:
    bool mStartup{true};
    std::string mServerAddr{};
    std::string mSubTopic{};
    std::string mPubTopic{};
    mqtt::connect_options mConnectOptions;
    mqtt::async_client_ptr mAsyncMqttClientPtr = nullptr;
};

}
#endif // MQTTLINK_H
