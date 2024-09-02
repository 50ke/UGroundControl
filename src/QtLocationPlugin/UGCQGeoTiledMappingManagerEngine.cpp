#include "UGCQGeoTiledMappingManagerEngine.h"
#include "UGCQGeoTileFetcher.h"

#include <QtCore/QDir>
#include <QtNetwork/QNetworkAccessManager>
#include <QtLocation/private/qgeocameracapabilities_p.h>
#include <QtLocation/private/qgeomaptype_p.h>
#include <QtLocation/private/qgeotiledmap_p.h>
#include <QtLocation/private/qgeofiletilecache_p.h>

UGCQGeoTiledMappingManagerEngine::UGCQGeoTiledMappingManagerEngine(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString)
{
    QGeoCameraCapabilities cameraCaps;
    cameraCaps.setTileSize(256);
    cameraCaps.setMinimumZoomLevel(10);
    cameraCaps.setMaximumZoomLevel(16);
    cameraCaps.setSupportsBearing(true);
    cameraCaps.setSupportsRolling(false);
    cameraCaps.setSupportsTilting(false);
    cameraCaps.setMinimumTilt(0.0);
    cameraCaps.setMaximumTilt(0.0);
    cameraCaps.setMinimumFieldOfView(45.0);
    cameraCaps.setMaximumFieldOfView(45.0);
    cameraCaps.setOverzoomEnabled(true);
    setCameraCapabilities(cameraCaps);

    setTileSize(QSize(256, 256));

    // 瓦片获取
    UGCQGeoTileFetcher *tile_fetcher = new UGCQGeoTileFetcher(parameters, this);
    setTileFetcher(tile_fetcher);
    // 瓦片缓存
    QString cache_dir;
    if(parameters.contains("mapPath")){
        cache_dir = parameters.value("mapPath").toString() + QString("/Cache");
    }else{
        cache_dir = QAbstractGeoTileCache::baseLocationCacheDirectory() + QString("Cache");
    }
    QGeoFileTileCache *tile_cache = new QGeoFileTileCache(cache_dir,this);
    const int cache_size = 512 * 1024 * 1024;
    tile_cache->setMaxDiskUsage(cache_size);
    setTileCache(tile_cache);

    m_prefetchStyle = QGeoTiledMap::NoPrefetching;
    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

UGCQGeoTiledMappingManagerEngine::~UGCQGeoTiledMappingManagerEngine()
{
    // qCDebug(QGeoTiledMappingManagerEngineQGCLog) << Q_FUNC_INFO << this;
}

QGeoMap* UGCQGeoTiledMappingManagerEngine::createMap()
{
    QGeoTiledMap *map = new QGeoTiledMap(this, nullptr);
    map->setPrefetchStyle(m_prefetchStyle);
    return map;
}
