#include <QScrollBar>
#include <QPalette>
#include <QSizePolicy>
#include <QPixmap>
#include "widgetscroll.h"

WidgetScroll::WidgetScroll(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QGridLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->verticalScrollBar()->setSingleStep(5);
    mainLayout->addWidget(scrollArea);
    scrollWidget = new QWidget(scrollArea);
    scrollLayout = new QVBoxLayout(scrollWidget);
    scrollLayout->setContentsMargins(0, 0, 0, 0);
    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);
    scrollLayout->setAlignment(Qt::AlignTop);
}

void WidgetScroll::addButton(QPushButton *button)
{
    scrollLayout->addWidget(button);
}

void WidgetScroll::addWidget(QWidget *widget)
{
    scrollLayout->addWidget(widget);
}


void WidgetScroll::setBackgroundColor(QColor color)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, color);
    setPalette(pal);
}

void WidgetScroll::setBackgroundImage(QString path)
{
    QString css = "background-image : url(";
    css.append(path); css.append("); background-position : center center");
    setStyleSheet(css);
    //Check this function
}

void WidgetScroll::setButtonColor(QColor color)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Button, color);
    setPalette(pal);
}

void WidgetScroll::setMargins(int left, int right, int top, int bottom)
{
    scrollLayout->setContentsMargins(left, top, right, bottom);
}

void WidgetScroll::setSpacing(int spacing)
{
    scrollLayout->setSpacing(spacing);
}

void WidgetScroll::setStep(int step)
{
    scrollArea->verticalScrollBar()->setSingleStep(step);
}

WidgetScroll::~WidgetScroll()
{

}
