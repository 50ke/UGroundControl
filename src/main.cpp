#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngineQuick>
#include <QQuickStyle>
#include <fmt/format.h>
int main(int argc, char *argv[])
{
    fmt::println("---------{}-----------", "abcdfdf");
    QQuickStyle::setStyle("Basic");
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QtWebEngineQuick::initialize();
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.addImportPath("qrc:/");
    engine.loadFromModule("UGroundControl", "Main");

    return app.exec();
}
