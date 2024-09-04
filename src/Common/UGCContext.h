#ifndef UGCCONTEXT_H
#define UGCCONTEXT_H

#include <QObject>
#include <UGCApplication.h>

namespace UGC {

/**
 * 该类作为UGC其他类的父类
 * @brief The UGCContext class
 */
class UGCContext : public QObject
{
    Q_OBJECT
public:
    explicit UGCContext(UGCApplication *app);

protected:
    UGCApplication* mApp;
};

}

#endif // UGCCONTEXT_H
