#include "MqttLink.h"

UGC::MqttLink::MqttLink(const QString &serverAddr, const QString &subTopic, const QString &pubTopic)
    : mServerAddr(serverAddr), mSubTopic(subTopic), mPubTopic(pubTopic){
    try{
        mConnectOptions = mqtt::connect_options_builder()
        .keep_alive_interval(std::chrono::seconds(10))
            .automatic_reconnect(std::chrono::seconds(5), std::chrono::seconds(10))
            .clean_session(true)
            .finalize();
        mAsyncMqttClientPtr = std::make_shared<mqtt::async_client>(serverAddr.toStdString(), "ugc-mqtt-client-id");
        mAsyncMqttClientPtr->start_consuming();
        mAsyncMqttClientPtr->connect(mConnectOptions)->wait();
    } catch (const std::exception& ex) {
        qCritical() << "MQTT INIT Error:" << ex.what();
    }
}

void UGC::MqttLink::publish(const QString &message){
    try{
        if(!mAsyncMqttClientPtr->is_connected()){
            mAsyncMqttClientPtr->connect(mConnectOptions)->wait();
        }
        mqtt::message_ptr pubmsg = mqtt::make_message(mPubTopic.toStdString(), message.toStdString(), 1, false);
        mAsyncMqttClientPtr->publish(pubmsg)->wait();
    } catch (const std::exception& ex) {
        qCritical() << "MQTT Send Message Error:" << ex.what();
    }
}

void UGC::MqttLink::subscribe(){
    try{
        mAsyncMqttClientPtr->subscribe(mSubTopic.toStdString(), 1)->wait();
        while (mStartup) {
            auto msg = mAsyncMqttClientPtr->consume_message();
            emit receivedMessage(QString::fromStdString(msg->to_string()));
        }
    } catch (const std::exception& ex) {
        qCritical() << "MQTT Do Work Error:" << ex.what();
    }
}
