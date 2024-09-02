#ifndef UGCGEOTILEDMAPREPLY_H
#define UGCGEOTILEDMAPREPLY_H

#include <QObject>
#include <QtLocation/private/qgeotiledmapreply_p.h>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

class UGCGeoTiledMapReply : public QGeoTiledMapReply
{
    Q_OBJECT
public:
    UGCGeoTiledMapReply(QNetworkReply *reply, const QGeoTileSpec &spec, const QString &imageFormat, QObject *parent = nullptr);

private Q_SLOTS:
    void networkReplyFinished();
    void networkReplyError(QNetworkReply::NetworkError error);
};

#endif // UGCGEOTILEDMAPREPLY_H
