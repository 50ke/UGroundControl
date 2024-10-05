#ifndef MQTTLINK_H
#define MQTTLINK_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <memory>
#include <QThread>
#include <mqtt/async_client.h>
#include <link_protocol.pb.h>

namespace UGC {

class ActionListener : public virtual mqtt::iaction_listener{

private:
    std::string mName;
public:
    ActionListener(const std::string& name);
    void on_failure(const mqtt::token& tok) override;
    void on_success(const mqtt::token& tok) override;

};

class MqttLinkCallback : public QObject, public virtual mqtt::callback, public virtual mqtt::iaction_listener
{
    Q_OBJECT
private:
    int mRetryNum{0};
    int mMaxRetryNum{10};
    std::string mCommonTopic{"COMMON"};
    std::string mGcsTopic{""};
    mqtt::async_client_ptr mMqttClientPtr{nullptr};
    mqtt::connect_options mConnectOptions;
    ActionListener mSubActionListener;
signals:
    void messageArrived(const std::string &payload);
public:
    MqttLinkCallback();
    MqttLinkCallback(const std::string &gcsSubTopic, mqtt::async_client_ptr cli, mqtt::connect_options connOpts);
    void reconnect();
    void on_failure(const mqtt::token& tok) override;
    void on_success(const mqtt::token& tok) override;
    void connected(const std::string& cause) override;
    void connection_lost(const std::string& cause) override;
    void message_arrived(mqtt::const_message_ptr msg) override;
    void delivery_complete(mqtt::delivery_token_ptr token) override;
};

class MqttLink : public QObject
{
    Q_OBJECT

public:
    MqttLink(const QString &serverAddr, int gcsSystemId);
    MqttLink(const QString &serverAddr, const QString &subTopic, const QString &clientId);
    void publish(int targetSystemId, const UsvLink::MessagePacket &message);
    void publish(const QString &pubTopic, const UsvLink::MessagePacket &message);

public slots:
    void start();
    void subscribedMessage(const std::string &payload);

signals:
    void receivedMessage(const UsvLink::MessagePacket &message);

private:
    bool mStartup{true};
    QString mServerAddr{};
    QString mCommonTopic{"COMMON"};
    QString mGcsTopic{""};
    QString mClientId{"gcs-mqtt-client-id"};
    MqttLinkCallback *mMqttLinkCallback = nullptr;
    mqtt::connect_options mConnectOptions;
    mqtt::async_client_ptr mAsyncMqttClientPtr = nullptr;
};

}
#endif // MQTTLINK_H
