#ifndef SPLASHWINDOW_H
#define SPLASHWINDOW_H

#include <QWindow>

class SplashWindow : public QWindow
{
    Q_OBJECT
public:
    explicit SplashWindow(QWindow *parent = 0);
    virtual void render(QPainter *painter);

    QString message() const;
    void setMessage(const QString &message);

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    QBackingStore *m_backingStore;
    QImage  m_image;
    QString m_message;
};

#endif // SPLASHWINDOW_H
