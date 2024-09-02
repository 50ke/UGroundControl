#include "UGCQGeoTileFetcher.h"
#include "UGCGeoTiledMapReply.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtLocation/private/qgeotilespec_p.h>
#include <QtLocation/private/qgeotilefetcher_p_p.h>
#include <QUrl>
#include <QDebug>
#include <QFile>


UGCQGeoTileFetcher::UGCQGeoTileFetcher(
    const QVariantMap &parameters,
    QGeoMappingManagerEngine *parent)
    : QGeoTileFetcher(parent)
    , networkManager(new QNetworkAccessManager(this))
{
    //链接地址
    if(parameters.contains("mapPath")){
        mapUrl=QUrl::fromLocalFile(parameters.value("mapPath").toString()).toString();
    }
    //瓦片图片格式
    if(parameters.contains("format")){
        format=parameters.value("format").toString();
    }
}

QGeoTiledMapReply *UGCQGeoTileFetcher::getTileImage(const QGeoTileSpec &spec)
{
    QNetworkRequest request;
    request.setRawHeader("Accept", "*/*");//设置网络请求头
    //request.setHeader(QNetworkRequest::UserAgentHeader, _userAgent);
    request.setUrl(getUrl(spec));

    //qDebug()<<"GeoTileFetcherMyMap::getTileImage"<<request.url();

    QNetworkReply *reply = networkManager->get(request);
    return new UGCGeoTiledMapReply(reply, spec, format);
}

QString UGCQGeoTileFetcher::getUrl(const QGeoTileSpec &spec) const
{
    //其实小写也可以，一般系统默认是不区分大小写的
    //用的arcgis 瓦片命名格式
    int x = spec.x();
    int y = spec.y();
    int zoom = spec.zoom();

    QString path = QString("%1/osm_100-l-3-%2-%3-%4.%5")
        .arg(mapUrl)
        .arg(zoom)
        .arg(x)
        .arg(y)
        .arg(format);

    QString localFilePath = QUrl(path).toLocalFile();
    QFile file(localFilePath);
    if (!file.exists()) {
        qDebug() << "瓦片不存在：" << path;
        path = QString("%1/no-tile.%2")
            .arg(mapUrl)
            .arg(format);
    }else{
        qDebug() << "瓦片存在：" << path;
    }
    return path;
}
