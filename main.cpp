#include <QGuiApplication>
#include <QQuickView>
#include <QScreen>
#include <QTimer>
#include "splashwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setApplicationName("SplashWindow Demo");
    QCoreApplication::setApplicationVersion("v1.2.3");
    QGuiApplication app(argc, argv);

    SplashWindow splash;
    //splash.centerInScreen(app.primaryScreen());
    splash.show();
    //QTimer::singleShot(2500, &splash, &SplashWindow::close);
    QCoreApplication::processEvents();

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QQuickView view(url);
    QCoreApplication::processEvents();
    splash.finish(&view);
    QTimer::singleShot(2000, &view, &QQuickView::show);

    return app.exec();
}
