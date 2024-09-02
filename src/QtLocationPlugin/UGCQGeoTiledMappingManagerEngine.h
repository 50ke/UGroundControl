#ifndef UGCQGEOTILEDMAPPINGMANAGERENGINE_H
#define UGCQGEOTILEDMAPPINGMANAGERENGINE_H

#include <QObject>
#include <QtLocation/QGeoServiceProvider>
#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

class UGCQGeoTiledMappingManagerEngine : public QGeoTiledMappingManagerEngine
{
    Q_OBJECT
public:
    UGCQGeoTiledMappingManagerEngine(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString);
    ~UGCQGeoTiledMappingManagerEngine();

    QGeoMap* createMap() override;
};

#endif // UGCQGEOTILEDMAPPINGMANAGERENGINE_H
