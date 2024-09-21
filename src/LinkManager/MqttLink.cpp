#include "MqttLink.h"

UGC::MqttLink::MqttLink(const QString &serverAddr, int gcsSystemId)
    : mServerAddr(serverAddr), mGcsTopic("GCS/" + gcsSystemId){
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

void UGC::MqttLink::publish(int targetSystemId, const mavlink_message_t &message){
    try{
        if(!mAsyncMqttClientPtr->is_connected()){
            qDebug() << "[Publish]MQTT LINK Disconnectd, try to reconnect...";
            mAsyncMqttClientPtr->connect(mConnectOptions)->wait();
        }
        std::string topic = targetSystemId == 0 ? mCommonTopic.toStdString() : ("USV/" + targetSystemId);
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        const int len = mavlink_msg_to_send_buffer(buffer, &message);
        mqtt::message_ptr pubmsg = mqtt::make_message(topic, buffer, len, 1, false);
        mAsyncMqttClientPtr->publish(pubmsg)->wait();
    } catch (const std::exception& ex) {
        qCritical() << "MQTT Send Message Error:" << ex.what();
    }
}

void UGC::MqttLink::subscribe(){
    try{
        auto subTopics  = mqtt::string_collection::create({mCommonTopic.toStdString(), mGcsTopic.toStdString()});
        const std::vector<int> qos{1, 1};
        mAsyncMqttClientPtr->subscribe(subTopics, qos)->wait();
        mqtt::const_message_ptr msg;
        while (mStartup) {
            if(!mAsyncMqttClientPtr->is_connected()){
                qDebug() << "[Subscribe]MQTT LINK Disconnectd, try to reconnect...";
                mAsyncMqttClientPtr->connect(mConnectOptions)->wait();
                mAsyncMqttClientPtr->subscribe(subTopics, qos)->wait();
            }
            if(mAsyncMqttClientPtr->try_consume_message(&msg) && msg != nullptr){
                std::string payload = msg->to_string();
                // 解析mavlink消息
                std::vector<uint8_t> buffer(payload.begin(), payload.end());
                mavlink_status_t status_t;
                mavlink_message_t message_t;
                for (int i = 0; i < buffer.size(); i++){
                    if (mavlink_parse_char(MAVLINK_COMM_0, buffer[i], &message_t, &status_t)){
                        emit receivedMessage(message_t);
                    }
                }
            }
        }
    } catch (const std::exception& ex) {
        qCritical() << "MQTT Subscribe Error:" << ex.what();
    }
}
