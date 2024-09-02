#ifndef UGCQGEOTILEFETCHER_H
#define UGCQGEOTILEFETCHER_H

#include <QObject>
#include <QtLocation/private/qgeotilefetcher_p.h>
#include <QtNetwork/QNetworkRequest>
#include <QNetworkAccessManager>

class UGCQGeoTileFetcher : public QGeoTileFetcher
{
    Q_OBJECT
public:
    UGCQGeoTileFetcher(const QVariantMap &parameters, QGeoMappingManagerEngine  *parent = nullptr);

private:
    QGeoTiledMapReply* getTileImage(const QGeoTileSpec &spec) override;
    QString getUrl(const QGeoTileSpec &spec) const;

private:
    QString mapUrl;
    QString format{"png"};
    QNetworkAccessManager* networkManager;
};

#endif // UGCQGEOTILEFETCHER_H
