# SplashWindow

Splash window for Qt, replacing `QSplashScreen`

This `SplashWindow` class can be used instead of `QSplashScreen` in applications using
`QGuiApplication` instead of `QApplication`. It needs only the `gui` module, but not
the `widgets` module as `QSplashScreen`, so it may be useful in QML apps.

It is derived from the [Raster Window](https://doc.qt.io/qt-5/qtgui-rasterwindow-example.html) Qt example code.

## Usage

* close after a fixed amount of time:

```
    SplashWindow splash;
    splash.show();
    QTimer::singleShot(2500, &splash, SLOT(close()));
```

* close when another window is shown:

```
    SplashWindow splash;
    splash.show();
    QQuickView *view = new QQuickView;
    splash.finish(view);
    view->show();
```

view may be an instance of any `QWindow` derived class (like `QQuickView`)

Since the splash screen is typically displayed before the event loop has started running, 
it is necessary to periodically call `QCoreApplication::processEvents()`.

You may also call `splash.close()` after completing the application initialization.
A new method `centerInScreen(QScreen *s)` has been added to control the positioning of the splash window.
