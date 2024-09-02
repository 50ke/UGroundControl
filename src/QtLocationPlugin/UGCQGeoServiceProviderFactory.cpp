#include "UGCQGeoServiceProviderFactory.h"
#include "UGCQGeoTiledMappingManagerEngine.h"

// extern "C" Q_DECL_EXPORT QT_PREPEND_NAMESPACE(QPluginMetaData) qt_plugin_query_metadata_v2();
// extern "C" Q_DECL_EXPORT QT_PREPEND_NAMESPACE(QObject) *qt_plugin_instance();

// const QT_PREPEND_NAMESPACE(QStaticPlugin) qt_static_plugin_UGCQGeoServiceProviderFactory()
// {
//     QT_PREPEND_NAMESPACE(QStaticPlugin) plugin = { qt_plugin_instance, qt_plugin_query_metadata_v2};
//     return plugin;
// }

UGCQGeoServiceProviderFactory::UGCQGeoServiceProviderFactory()
{

}

UGCQGeoServiceProviderFactory::~UGCQGeoServiceProviderFactory()
{

}

QGeoCodingManagerEngine* UGCQGeoServiceProviderFactory::createGeocodingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters);
    if (error) {
        *error = QGeoServiceProvider::NotSupportedError;
    }
    if (errorString) {
        *errorString = "Geocoding Not Supported";
    }
    return nullptr;
}

QGeoMappingManagerEngine* UGCQGeoServiceProviderFactory::createMappingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    if (error) {
        *error = QGeoServiceProvider::NoError;
    }
    if (errorString) {
        *errorString = "";
    }
    // TODO: m_engine->networkAccessManager();
    return new UGCQGeoTiledMappingManagerEngine(parameters, error, errorString);
}

QGeoRoutingManagerEngine* UGCQGeoServiceProviderFactory::createRoutingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters);
    if (error) {
        *error = QGeoServiceProvider::NotSupportedError;
    }
    if (errorString) {
        *errorString = "Routing Not Supported";
    }
    return nullptr;
}

QPlaceManagerEngine* UGCQGeoServiceProviderFactory::createPlaceManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters);
    if (error) {
        *error = QGeoServiceProvider::NotSupportedError;
    }
    if (errorString) {
        *errorString = "Place Not Supported";
    }
    return nullptr;
}
