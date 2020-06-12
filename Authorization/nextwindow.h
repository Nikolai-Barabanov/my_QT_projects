#ifndef NEXTWINDOW_H
#define NEXTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QLayout>

class nextWindow : public QWidget
{
    Q_OBJECT
public:
    explicit nextWindow(QWidget* parent = 0);
    ~nextWindow();
private slots:
    void exit();
};

#endif // NEXTWINDOW_H
