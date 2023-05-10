#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "area.h"
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget();
    ~Widget();

protected:
    Area * area; // область отображения рисунка
    QPushButton * btn;

};
#endif // WIDGET_H
