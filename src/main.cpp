#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngineQuick>
#include <QQuickStyle>
#include <fmt/format.h>
#include <UGCApplication.h>
int main(int argc, char *argv[])
{
    fmt::println("---------{}-----------", "Initializing UGroundControl");
    UGC::UGCApplication application;

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
    engine.addImportPath("qrc:/src");
    engine.loadFromModule("UGroundControl", "MainWindow");

    return app.exec();
}
