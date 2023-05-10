#ifndef FIGURE_H
#define FIGURE_H

#include <QtGui>

// Класс родитель, который определяет виртуальные функции, которые отвечают за отрисовку
class Figure
{
protected:
    //x: координата по оси x, где расположена фигура.
    //y: координата по оси y, где расположена фигура.
    // halflen: половина длины фигуры.
    //dx: изменение координаты x после применения метода move.
    //dy: изменение координаты y после применения метода move.
    //r: радиус фигуры.
    int x,y,halflen,dx,dy,r;
    // Определение виртуальной функции для отрисовки
    virtual void draw(QPainter *Painter)=0;
public:
    Figure(int X,int Y,int Halflen):
        x(X),y(Y),halflen(Halflen){}
    // Определение метода для перемещения фигуры
    void move(float Alpha,QPainter *Painter);
};

// Класс, который наследуется от Figure и реализует метод для отрисовки линии
class MyLine:public Figure
{
protected:
    void draw(QPainter *Painter);
public:
    MyLine(int x,int y,int halflen):Figure(x,y,halflen){}
};

// Класс, который наследуется от Figure и реализует метод для отрисовки прямоугольника
class MyRect:public Figure
{
protected:
    void draw(QPainter *Painter);
public:
    MyRect(int x,int y,int halflen):Figure(x,y,halflen){}
};

#endif // FIGURE_H
