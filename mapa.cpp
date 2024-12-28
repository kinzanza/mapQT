#include "mapa.h"
#include "ui_mapa.h"
#include <QDebug>

Mapa::Mapa(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Mapa), scaleFactor(1.0), offsetX(0), offsetY(0)
{
    ui->setupUi(this);
    mapa = new QPixmap("C:/Temp/map.jpg");  // Путь к карте
    if (mapa->isNull()) {
        qDebug() << "Failed to load image!";
    }
}

Mapa::~Mapa() {
    delete ui;
}

void Mapa::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Масштабируем карту в зависимости от scaleFactor
    QPixmap scaledMap = mapa->scaled(mapa->size() * scaleFactor, Qt::KeepAspectRatio);

    // Отображаем изображение с учетом смещения
    painter.drawPixmap(offsetX, offsetY, scaledMap);
}

void Mapa::mousePressEvent(QMouseEvent *event)
{
    lastMousePos = event->pos();  // Запоминаем начальную позицию мыши
    QPoint screenPos = event->pos();  // Координаты на экране

    // Преобразуем в координаты на карте
    int mapX = (screenPos.x() - offsetX) / scaleFactor;
    int mapY = (screenPos.y() - offsetY) / scaleFactor;

    if (mapX >= 0 && mapX < mapa->width() && mapY >= 0 && mapY < mapa->height()) {
        qDebug() << "Clicked on map at coordinates:" << mapX << mapY;
    }
}

void Mapa::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        // Вычисляем смещение мыши и сдвигаем карту
        int dx = event->x() - lastMousePos.x();
        int dy = event->y() - lastMousePos.y();
        offsetX += dx;
        offsetY += dy;
        lastMousePos = event->pos();
        update();  // Обновляем виджет, чтобы перерисовать
    }
}

void Mapa::wheelEvent(QWheelEvent *event)
{
    // Масштабируем карту при прокрутке колесика мыши
    if (event->angleDelta().y() > 0) {
        scaleFactor *= 1.1;  // Увеличиваем масштаб
    } else {
        scaleFactor *= 0.9;  // Уменьшаем масштаб
    }

    // Ограничиваем масштаб
    scaleFactor = qBound(0.1, scaleFactor, 5.0);

    update();  // Обновляем виджет, чтобы перерисовать
}
