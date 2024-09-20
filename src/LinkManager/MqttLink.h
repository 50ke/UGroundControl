#ifndef MQTTLINK_H
#define MQTTLINK_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <memory>
#include <mqtt/async_client.h>
#include <common/mavlink.h>

namespace UGC {

class MqttLink : public QObject
{
    Q_OBJECT

public:
    explicit MqttLink(const QString &serverAddr);
    void publish(const mavlink_message_t &message);

public slots:
    void subscribe();

signals:
    void receivedMessage(const mavlink_message_t &message);

private:
    bool mStartup{true};
    QString mServerAddr{};
    QString mSubTopic{"COMMON"};
    mqtt::connect_options mConnectOptions;
    mqtt::async_client_ptr mAsyncMqttClientPtr = nullptr;
};

}
#endif // MQTTLINK_H
