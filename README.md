# SplashWindow

Splash window for Qt, replacing QSplashScreen

This SplashWindow class can be used instead of QSplashScreen in applications using
QGuiApplication instead of QApplication. It needs only the `gui` module, but not
the `widgets` module as QSplashScreen, so it may be useful in QML apps.

It is derived from the [Raster Window](https://doc.qt.io/qt-5/qtgui-rasterwindow-example.html) Qt example code.

## Usage

    SplashWindow w;
    w.show();
    QTimer::singleShot(2500, &w, SLOT(close()));

Or call `close()` after completing the initialization.
