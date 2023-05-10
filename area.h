#ifndef AREA_H
#define AREA_H

#include <QWidget>
#include "figure.h"

class Area : public QWidget
{
    // Идентификатор таймера
    int myTimer;
    // Угол поворота
    float alpha;
public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;
    MyRect *myrect;
protected:
    // Обработчики событий
    // Вызывается при необходимости перерисовки виджета
    void paintEvent(QPaintEvent *event);
    // Вызывается при таймере
    void timerEvent(QTimerEvent *event);
    // Вызывается при показе виджета
    void showEvent(QShowEvent *event);
};

#endif // AREA_H
