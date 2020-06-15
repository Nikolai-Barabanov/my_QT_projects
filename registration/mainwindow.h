#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMap>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QFormLayout>
#include <QApplication>
#include <QMessageBox>

#include "database.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void registration();
    void quit();

private:
    QMap<QString, QPushButton*> buttons;
    QMap<QString, QLineEdit*> lineEdits;
    QMap<QString, QString> fields;
    DataBase* myBase;

    void createDesign();
    void connectslots();
    void getFields();
    void validator();
    void clearFields();
};
#endif // MAINWINDOW_H
