#ifndef MAPA_H
#define MAPA_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>

namespace Ui {
class Mapa;
}

class Mapa : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mapa(QWidget *parent = nullptr);
    ~Mapa();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::Mapa *ui;
    QPixmap *mapa;  // Картинка карты
    float scaleFactor;  // Масштаб
    int offsetX, offsetY;  // Смещение карты
    QPoint lastMousePos;  // Для отслеживания положения мыши
};

#endif // MAPA_H
