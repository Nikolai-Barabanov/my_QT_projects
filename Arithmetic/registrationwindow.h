#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>
#include <QMap>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QFormLayout>

class RegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();
    QMap<QString, QLineEdit*>* getLineEdits();

signals:
    void quit();
    void registration();
    void back();

private slots:
    void pushButtonReg();
    void pushButtonBack();
    void pushButtonQuit();

private:
    QMap<QString, QPushButton*> buttons;
    QMap<QString, QLineEdit*> lineEdits;   

    void createDesign();
    void connectslots();
};

#endif // REGISTRATIONWINDOW_H
