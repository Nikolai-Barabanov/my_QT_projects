#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QMap>


class AuthorizationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();   
    QMap<QString, QLineEdit*>* getLineEdits();

signals:
    void quit();
    void authorization();
    void registration();

private slots:
    void pushButtonQuit();
    void pushButtonAuthorization();
    void pushButtonRegistration();

private:
    QMap<QString, QPushButton*> buttons;
    QMap<QString, QLineEdit*> lineEdits;   

    void createDesign();
    void connectSlots();
};

#endif // AUTHORIZATIONWINDOW_H
