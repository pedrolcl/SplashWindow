#include <QGuiApplication>
#include <QQuickView>
#include <QTimer>
#include "splashwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setApplicationName("SplashWindow Demo");
    QCoreApplication::setApplicationVersion("v1.2.3");
    QGuiApplication app(argc, argv);
    QQuickView *view = new QQuickView;

    SplashWindow w;
    w.show();
    QTimer::singleShot(2500, &w, SLOT(close()));

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    view->setSource(url);
    view->show();

    return app.exec();
}
