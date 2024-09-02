#ifndef UGCQGEOSERVICEPROVIDERFACTORY_H
#define UGCQGEOSERVICEPROVIDERFACTORY_H

#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include <QtLocation/QGeoServiceProviderFactory>

class UGCQGeoServiceProviderFactory : public QObject, public QGeoServiceProviderFactory
{
    Q_OBJECT
    Q_INTERFACES(QGeoServiceProviderFactory)
    Q_PLUGIN_METADATA(IID "org.qt-project.qt.geoservice.serviceproviderfactory/6.0" FILE "ugc_map.json")
public:
    UGCQGeoServiceProviderFactory();
    ~UGCQGeoServiceProviderFactory();

    QGeoCodingManagerEngine* createGeocodingManagerEngine(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const final;
    QGeoMappingManagerEngine* createMappingManagerEngine(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const final;
    QGeoRoutingManagerEngine* createRoutingManagerEngine(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const final;
    QPlaceManagerEngine* createPlaceManagerEngine(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const final;

};

#endif // UGCQGEOSERVICEPROVIDERFACTORY_H
