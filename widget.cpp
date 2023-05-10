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
{
    QMessageBox meesageBox(QMessageBox::Information,
                           "Счетчик",
                           "Ошибка: невозможно выделить память. Пожалуйста, перезапустите приложение!",
                           QMessageBox::Ok);
    // Запускаем диалоговое окно сообщения msgBox и блокирует дальнейшее выполнение
    // программы до тех пор, пока пользователь не закроет это окно
    meesageBox.exec();
    exit(0);
};

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
