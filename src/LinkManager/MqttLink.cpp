#include "MqttLink.h"

/********************** ActionListener **********************/
UGC::ActionListener::ActionListener(const std::string& name) : mName(name) {}

void UGC::ActionListener::on_failure(const mqtt::token &tok){
    qDebug() << "[MqttLink]Action Listener Failure.";
}

void UGC::ActionListener::on_success(const mqtt::token &tok){
    qDebug() << "[MqttLink]Action Listener Success.";
}

/********************** MqttLinkCallback **********************/
UGC::MqttLinkCallback::MqttLinkCallback() : mSubActionListener("MQTT Link Subscription"){}

UGC::MqttLinkCallback::MqttLinkCallback(const std::string &gcsSubTopic, mqtt::async_client_ptr cli, mqtt::connect_options connOpts)
    : mGcsTopic(gcsSubTopic), mMqttClientPtr(cli), mConnectOptions(connOpts), mSubActionListener("MQTT Link Subscription"){}

void UGC::MqttLinkCallback::reconnect(){
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    try {
        mMqttClientPtr->connect(mConnectOptions, nullptr, *this);
    }catch (const mqtt::exception& exc) {
        qCritical() << "[MqttLink]Reconnect Error: " << exc.what();
    }
}

void UGC::MqttLinkCallback::on_failure(const mqtt::token &tok){
    qWarning() << "[MqttLink]Connection Attempt Failed.";
    if(++mRetryNum > mMaxRetryNum){
        exit(1);
    }
    reconnect();
}

void UGC::MqttLinkCallback::on_success(const mqtt::token &tok){}

void UGC::MqttLinkCallback::connected(const std::string &cause){
    qInfo() << "[MqttLink]Connected.";
    auto subTopics  = mqtt::string_collection::create({mCommonTopic, mGcsTopic});
    const std::vector<int> qos{1, 1};
    mMqttClientPtr->subscribe(subTopics, qos, nullptr, mSubActionListener);
}

void UGC::MqttLinkCallback::connection_lost(const std::string &cause){
    if(cause.empty()){
        qWarning() << "[MqttLink]Connection Lost.";
    }else{
        qWarning() << "[MqttLink]Connection Lost: " << cause;
    }
    qInfo() << "[MqttLink]Reconnecting.";
    mRetryNum = 0;
    reconnect();
}

void UGC::MqttLinkCallback::message_arrived(mqtt::const_message_ptr msg){
    emit messageArrived(msg->to_string());
}

void UGC::MqttLinkCallback::delivery_complete(mqtt::delivery_token_ptr token){}

/********************** MqttLink **********************/
UGC::MqttLink::MqttLink(const QString &serverAddr, int gcsSystemId)
    : mServerAddr(serverAddr), mGcsTopic("GCS/" + QString::number(gcsSystemId))
{
    QString gcsSubTopic = "GCS/" + QString::number(gcsSystemId);
    mConnectOptions = mqtt::connect_options_builder()
                          .clean_session(true)
                          .finalize();
    mAsyncMqttClientPtr = std::make_shared<mqtt::async_client>(serverAddr.toStdString(), mClientId.toStdString());
    mMqttLinkCallback = new MqttLinkCallback(gcsSubTopic.toStdString(), mAsyncMqttClientPtr, mConnectOptions);
    connect(mMqttLinkCallback, &MqttLinkCallback::messageArrived, this, &MqttLink::subscribedMessage);
}

UGC::MqttLink::MqttLink(const QString &serverAddr, const QString &subTopic, const QString &clientId)
    : mServerAddr(serverAddr), mGcsTopic(subTopic), mClientId(clientId)
{
    mConnectOptions = mqtt::connect_options_builder()
    .clean_session(true)
        .finalize();
    mAsyncMqttClientPtr = std::make_shared<mqtt::async_client>(serverAddr.toStdString(), clientId.toStdString());
    mMqttLinkCallback = new MqttLinkCallback(subTopic.toStdString(), mAsyncMqttClientPtr, mConnectOptions);
    connect(mMqttLinkCallback, &MqttLinkCallback::messageArrived, this, &MqttLink::subscribedMessage);
}

void UGC::MqttLink::subscribedMessage(const std::string &payload){
    UsvLink::MessagePacket packet;
    packet.ParseFromString(payload);
    emit receivedMessage(packet);
}

void UGC::MqttLink::publish(int targetSystemId, const UsvLink::MessagePacket &message){
    try{
        if(!mAsyncMqttClientPtr->is_connected()){
            qWarning() << "[MqttLink]Waiting for Connecting.";
            return;
        }
        QString pubTopic = "USV/" + QString::number(targetSystemId);
        std::string topic = targetSystemId == 0 ? mCommonTopic.toStdString() : pubTopic.toStdString();

        std::vector<uint8_t> buf(message.ByteSizeLong());
        message.SerializeToArray(buf.data(), buf.capacity());

        mqtt::message_ptr pubmsg = mqtt::make_message(topic, buf.data(), buf.size(), 1, false);
        mAsyncMqttClientPtr->publish(pubmsg)->wait();
    } catch (const std::exception& ex) {
        qCritical() << "[MqttLink]Publish Message Error: " << ex.what();
    }
}

void UGC::MqttLink::publish(const QString &pubTopic, const UsvLink::MessagePacket &message){
    try{
        if(!mAsyncMqttClientPtr->is_connected()){
            qWarning() << "[MqttLink]Waiting for Connecting.";
            return;
        }
        std::string topic = pubTopic.toStdString();

        std::vector<uint8_t> buf(message.ByteSizeLong());
        message.SerializeToArray(buf.data(), buf.capacity());

        mqtt::message_ptr pubmsg = mqtt::make_message(topic, buf.data(), buf.size(), 1, false);
        mAsyncMqttClientPtr->publish(pubmsg)->wait();
    } catch (const std::exception& ex) {
        qCritical() << "[MqttLink]Publish Message Error: " << ex.what();
    }
}

void UGC::MqttLink::start(){
    mAsyncMqttClientPtr->set_callback(*mMqttLinkCallback);
    mAsyncMqttClientPtr->connect(mConnectOptions, nullptr, *mMqttLinkCallback)->wait();
}
