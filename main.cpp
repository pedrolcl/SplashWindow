#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include "splashwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setApplicationName("SplashWindow Demo");
    QCoreApplication::setApplicationVersion("v1.2.3");
    QGuiApplication app(argc, argv);

    SplashWindow w;
    w.show();
    QTimer::singleShot(2500, &w, SLOT(close()));

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [&](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) {
            QCoreApplication::exit(-1);
        } /*else {
            w.close();
        }*/
    }, Qt::QueuedConnection);
    QObject::connect(&engine, &QQmlApplicationEngine::exit, &app, &QCoreApplication::exit);
    QObject::connect(&engine, &QQmlApplicationEngine::quit, &app, &QCoreApplication::quit);
    engine.load(url);

    return app.exec();
}
