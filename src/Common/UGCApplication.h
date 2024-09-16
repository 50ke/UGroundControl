#ifndef UGCAPPLICATION_H
#define UGCAPPLICATION_H

#include <QObject>
#include <QQmlContext>

namespace UGC {

class SettingManager;

/**
 * 该类用于启动初始化
 * @brief The UGCApplication class
 */
class UGCApplication : public QObject
{
    Q_OBJECT
public:
    UGCApplication();
    void init(QQmlContext *context);
    SettingManager *settingManager(){ return mSettingManagerPtr; }


private:
    SettingManager *mSettingManagerPtr;

};

}

#endif // UGCAPPLICATION_H
