#ifndef LIDARMANAGER_H
#define LIDARMANAGER_H

#include <QObject>

class LidarManager : public QObject
{
    Q_OBJECT
public:
    explicit LidarManager(QObject *parent = nullptr);

signals:
};

#endif // LIDARMANAGER_H
