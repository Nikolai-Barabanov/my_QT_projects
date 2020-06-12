#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QMap>

#include "data_base.h"
#include "nextwindow.h"

class dataBase;
class nextWindow;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString* getLogin();
    QString* getPassword();

signals:

private slots:
    void authorization();
    void quit();

private:
    QMap<QString, QPushButton*> buttons;
    QMap<QString, QLineEdit*> lineEdits;
    dataBase* data;
    nextWindow* next;
    QString login;
    QString pass;

    void createDesign();
    void connectSlots();
    QString cipher();

};
#endif // MAINWINDOW_H
