#include <QGuiApplication>
#include <QQuickView>
#include "splashwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setApplicationName("SplashWindow Demo");
    QCoreApplication::setApplicationVersion("v1.2.3");
    QGuiApplication app(argc, argv);

    SplashWindow splash;
    splash.show();
    //QTimer::singleShot(2500, &splash, SLOT(close()));
    QCoreApplication::processEvents();

    QQuickView *view = new QQuickView;
    splash.finish(view);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    view->setSource(url);
    view->show();

    return app.exec();
}
