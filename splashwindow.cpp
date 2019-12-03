#include <QCoreApplication>
#include <QBackingStore>
#include <QResizeEvent>
#include <QPainter>
#include <QGradient>
#include <QFont>
#include "splashwindow.h"

SplashWindow::SplashWindow(QWindow *parent)
    : QWindow(parent)
    , m_backingStore(new QBackingStore(this))
    , m_image(":/splash.png")
    , m_message(qApp->applicationName() + " " + qApp->applicationVersion())
{
    setFlags(Qt::SplashScreen | Qt::FramelessWindowHint);
    setGeometry(0, 0, 400, 400);
}

bool SplashWindow::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

void SplashWindow::renderLater()
{
    requestUpdate();
}

void SplashWindow::resizeEvent(QResizeEvent *resizeEvent)
{
    m_backingStore->resize(resizeEvent->size());
}

void SplashWindow::exposeEvent(QExposeEvent *)
{
    if (isExposed())
        renderNow();
}

QString SplashWindow::message() const
{
    return m_message;
}

void SplashWindow::setMessage(const QString &message)
{
    m_message = message;
}

void SplashWindow::renderNow()
{
    if (!isExposed())
        return;

    QRect rect(0, 0, width(), height());
    m_backingStore->beginPaint(rect);

    QPaintDevice *device = m_backingStore->paintDevice();
    QPainter painter(device);

    painter.fillRect(rect, QGradient::SaintPetersburg);
    painter.drawImage(rect, m_image);
    painter.setFont(QFont("Arial", 20, QFont::ExtraBold));
    render(&painter);
    painter.end();

    m_backingStore->endPaint();
    m_backingStore->flush(rect);
}

void SplashWindow::render(QPainter *painter)
{
    if (!m_message.isEmpty()) {
        painter->drawText(QRectF(0, 0, width(), height()), Qt::AlignCenter | Qt::AlignBottom, m_message);
    }
}
