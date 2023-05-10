#include "area.h"

Area::Area(QWidget *parent):QWidget(parent)
{
    // Установка фиксированного размера окна
    setFixedSize(QSize(300,200));
    // Создание объектов MyLine и MyRect
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    // Установка начального значения угла поворота
    alpha=0;
}

// Обработчик события отображения окна
void Area::showEvent(QShowEvent *)
{
    // Создание таймера с интервалом 50 миллисекунд и сохранение его идентификатора
    myTimer=startTimer(50);
}

// Обработчик события перерисовки окна
void Area::paintEvent(QPaintEvent *)
{
    // Создание объекта QPainter для рисования на виджете
    QPainter painter(this);
    // Установка цвета пера на красный
    painter.setPen(Qt::red);
    // Вызов методов move объектов MyLine и MyRect для отрисовки с учетом угла поворота
    myline->move(alpha,&painter);
    myrect->move(alpha*(-0.5),&painter);
}

// Обработчик события таймера
void Area::timerEvent(QTimerEvent *event)
{
    // Если событие от нашего таймера
    if (event->timerId() == myTimer)
    {
        // Увеличение угла поворота
        alpha=alpha+0.2;
        // Обновление отображения
        update();
    }
    else
        // Передача события обработчику по умолчанию
        QWidget::timerEvent(event);
}

// деструктор класса Area
Area::~Area()
{
    // Удаление объектов MyLine и MyRect
    delete myline;
    delete myrect;
}
