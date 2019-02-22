#ifndef WIDGETSCROLL_H
#define WIDGETSCROLL_H

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>

class WidgetScroll : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *mainLayout;
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QVBoxLayout *scrollLayout;
public:
    WidgetScroll(QWidget *parent = nullptr);
    void addButton(QPushButton *button);
    void addWidget(QWidget *widget);
    void setBackgroundColor(QColor);
    void setBackgroundImage(QString path);
    void setButtonColor(QColor);
    void setMargins(int left, int right, int top, int bottom);
    void setSpacing(int spacing);
    void setStep(int step);
    ~WidgetScroll();
};

#endif // WIDGETSCROLL_H
