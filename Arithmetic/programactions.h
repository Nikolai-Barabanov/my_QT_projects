#ifndef PROGRAMACTIONS_H
#define PROGRAMACTIONS_H

#include <QObject>
#include <random>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QMap>
#include "programmodel.h"

class ProgramActions : public QObject
{
    Q_OBJECT
public:
    explicit ProgramActions(QObject* parent = nullptr);
    ~ProgramActions();
    bool authorization(QMap<QString, QLineEdit*>* lineEdits);
    bool registration(QMap<QString, QLineEdit*>* lineEdits);
    void clearFields(QMap<QString, QLineEdit*>* lineEdits);
    void checkAnswers(QMap<QString, QLineEdit*>* lineEdits, QMap<QString, QLabel*>* labels);
    void clearTaskList(QMap<QString, QLabel*>* labels);
    void setTasks(QMap<QString, QLabel*>* labels);
    void setResult(QMap<QString, QLabel*>* results, QMap<QString, QLabel*>* labels);
    void clearAnswers();

private:
    bool validator(QMap<QString, QLineEdit*>* lineEdits);
    QString getTasks();
    QMap<QString, QString> getFields(QMap<QString, QLineEdit*>* lineEdits);
    void setAnswer(QString task, int answer);

    ProgramModel* myDatabase;
    QMap<QString, int> answers;
    QMap<QString, bool> myResult;
};

#endif // PROGRAMACTIONS_H
