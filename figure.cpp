#include <math.h>
#include "figure.h"

void Figure::move(float Alpha,QPainter *Painter)
{
    // Вычисляем изменение координат по осям x и y на основе угла поворота Alpha
    dx=halflen*cos(Alpha);
    dy=halflen*sin(Alpha);
    // Вызываем метод draw, который определяется в классах-наследниках
    draw(Painter);
}
void MyLine::draw(QPainter *Painter)
{
    // Отрисовываем линию с помощью метода drawLine класса QPainter
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);
}
void MyRect::draw(QPainter *Painter)
{
    // Отрисовываем прямоугольник из четырех линий с помощью метода drawLine класса QPainter
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
