#include "programactions.h"

ProgramActions::ProgramActions(QObject* parent): QObject(parent)
{
    myDatabase = new ProgramModel();
}

ProgramActions::~ProgramActions()
{

}

bool ProgramActions::validator(QMap<QString, QLineEdit *> *lineEdits)
{
    QMessageBox* box = new QMessageBox();
    QString message;
    QMap<QString, QLineEdit*>::iterator iter;
    bool flag = true;

    for(iter = lineEdits->begin(); iter != lineEdits->end(); ++iter)
    {        
        if(iter.value()->text() == "" && flag)
        {
            message.append(" Присутствуют не заполненные поля \n");
            flag = !flag;
        }

        if(iter.key() == "regLogin" && iter.value()->text().size() > 0 )
        {
            if(myDatabase->findData("login", iter.value()->text()))
                message.append("Логин уже занят, пожалуйста введите новый логин \n");
        }

        if(iter.key() == "regPassword" && iter.value()->text().size() > 0 )
        {
            if(iter.value()->text().size() <= 7)
                message.append("Короткий пароль. Пароль должен содержать больше 7 символов \n");
            if(iter.value()->text() != lineEdits->find("passRep").value()->text())
                message.append("Пароли не совпадают \n");
        }
    }
    if(message.size() != 0)
    {
        box->setText(message);
        box->show();
        return false;
    }
    return true;
}

bool ProgramActions::authorization(QMap<QString, QLineEdit*>* lineEdits)
{
    if(validator(lineEdits))
    {        
        if(myDatabase->authorization(getFields(lineEdits)))
        {
            return true;
        }
    }
    return false;
}

bool ProgramActions::registration(QMap<QString, QLineEdit*>* lineEdits)
{
    if(validator(lineEdits))
    {
        if(myDatabase->registration(getFields(lineEdits)))
        {
           return true;
        }
        else
        {
            QMessageBox* box = new QMessageBox();
            box->setText("Неверный логин или пароль!");
            box->show();
        }
    }
    return false;
}

QMap<QString, QString> ProgramActions::getFields(QMap<QString, QLineEdit*>* lineEdits)
{
    QMap<QString, QString> fields;
    QMap<QString, QLineEdit*>::iterator iter;

    for(iter = lineEdits->begin(); iter != lineEdits->end(); ++iter)
    {
        if(iter.key() == "authLogin" || iter.key() == "regLogin")
            fields.insert("login", iter.value()->text());
        if(iter.key() == "authPassword" || iter.key() == "regPassword")
            fields.insert("password", iter.value()->text());
        if(iter.key() == "regName")
            fields.insert("name", iter.value()->text());
    }
    return fields;
}

void ProgramActions::clearFields(QMap<QString, QLineEdit*>* lineEdits)
{
    QMap<QString, QLineEdit*>::iterator iter;
    for(iter = lineEdits->begin(); iter != lineEdits->end(); ++iter)
        iter.value()->clear();
}

void ProgramActions::clearTaskList(QMap<QString, QLabel*>* labels)
{
    QMap<QString, QLabel*>::iterator iter;
    for(iter = labels->begin(); iter != labels->end(); ++iter)
        iter.value()->clear();
}

void ProgramActions::clearAnswers()
{
    answers.clear();
    myResult.clear();
}

void ProgramActions::setTasks(QMap<QString, QLabel*>* labels)
{
    QMap<QString, QLabel*>::iterator iter;
    for(iter = labels->begin(); iter != labels->end(); ++iter)
        iter.value()->setText(getTasks());
}

QString ProgramActions::getTasks()
{
    std::random_device rd;
    std::mt19937 mersenne(rd());
    srand(static_cast<unsigned int>(time(0)));

    int answer = 0;
    char symbol = ' ';
    int firstNumber = (mersenne() + 100) % 100;
    int secondNumber = (mersenne() + 10) % 10;

    int mySymbols = (mersenne() + 2) % 2;
    if(mySymbols == 1)
    {
        symbol = '+';
        answer = firstNumber + secondNumber;
    }
    else
    {
        symbol = '-';
        answer = firstNumber - secondNumber;
    }
    QString task = QStringLiteral("%1 %2 %3 = ").arg(firstNumber)
                                                .arg(symbol)
                                                .arg(secondNumber);
    setAnswer(task, answer);
    myResult.insert(task, false);
    return task;
}

void ProgramActions::setAnswer(QString task, int answer)
{
    answers.insert(task, answer);
}

void ProgramActions::checkAnswers(QMap<QString, QLineEdit*>* lineEdits, QMap<QString, QLabel*>* labels)
{
    QMap<QString, QLabel*>::iterator iter;

    for( iter = labels->begin(); iter != labels->end(); ++iter)
    {
        QString task = iter.value()->text();
        if(answers[task] == lineEdits->find(iter.key()).value()->text().toInt())
        {
            myResult[task] = true;
        }
        else
        {
            myResult[task] = false;
        }
    }
}

void ProgramActions::setResult(QMap<QString, QLabel*>* results, QMap<QString, QLabel*>* labels)
{
    QMap<QString, QLabel*>::iterator iter;

    for( iter = labels->begin(); iter != labels->end(); ++iter)
    {
        QString task = iter.value()->text();
        if(myResult[task])
        {
            results->find(iter.key()).value()->setText("Правильный ответ");
        }
        else
        {
            results->find(iter.key()).value()->setText("Неправильный ответ");
        }
    }
}

