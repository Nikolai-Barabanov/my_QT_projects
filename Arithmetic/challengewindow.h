#ifndef CHALLENGEWINDOW_H
#define CHALLENGEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QMap>

class ChallengeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ChallengeWindow(QWidget* parent = nullptr);
    ~ChallengeWindow();
    QMap<QString, QLineEdit*>* getLineEdits();
    QMap<QString, QLabel*>* getLabels();
    QMap<QString, QLabel*>* getResult();

signals:
    void back();
    void check();
    void refresh();

private slots:
    void pushButtonBack();
    void pushButtonCheck();
    void pushButtonRefresh();

private:
    QMap<QString, QPushButton*> buttons;
    QMap<QString, QLineEdit*> lineEdits;
    QMap<QString, QLabel*> labels;
    QMap<QString, QLabel*> results;

    void createDesign();
    void connectSlots();   
};

#endif // CHALLENGEWINDOW_H
