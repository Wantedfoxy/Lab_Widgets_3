// Подключение заголовочных файлов для классов Widget и Area
#include "widget.h"

Widget::Widget()
{
// Установка заголовка окна
setWindowTitle("Вращение фигур");
// Создание объектов Area и QPushButton и добавление их на форму
area = new Area( this );
btn = new QPushButton("Завершить", this);
QVBoxLayout *layout = new QVBoxLayout(this);
if(area == nullptr or btn == nullptr or layout == nullptr)
{throw std::bad_alloc();};

layout->addWidget(area);
layout->addWidget(btn);
// Установка соединения между кнопкой и слотом закрытия окна
connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};

// Деструктор класса Widget
Widget::~Widget()
{
    delete area;
    delete btn;
};
