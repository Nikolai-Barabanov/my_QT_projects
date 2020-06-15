#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    createDesign();
    myBase = new DataBase();
    myBase->createDataBase();
    myBase->createTable();
    connectslots();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createDesign()
{
    QLabel* regTitle = new QLabel("Регистрация");
    lineEdits.insert("name",new QLineEdit());
    lineEdits.insert("login",new QLineEdit());
    lineEdits.insert("surname",new QLineEdit());
    lineEdits.insert("email",new QLineEdit());
    lineEdits.insert("phone",new QLineEdit());
    lineEdits.insert("pass",new QLineEdit());
    lineEdits.insert("passRep",new QLineEdit());
    lineEdits["pass"]->setEchoMode(QLineEdit::Password);
    lineEdits["passRep"]->setEchoMode(QLineEdit::Password);

    buttons.insert("reg", new QPushButton("Регистрация"));
    buttons.insert("quit", new QPushButton("Выход"));

    QFormLayout* form = new QFormLayout();
    form->addRow("Имя", lineEdits["name"]);
    form->addRow("Логин", lineEdits["login"]);
    form->addRow("Фамилия", lineEdits["surname"]);
    form->addRow("Почта", lineEdits["email"]);
    form->addRow("Телефон", lineEdits["phone"]);
    form->addRow("Пароль", lineEdits["pass"]);
    form->addRow("Повторите пароль", lineEdits["passRep"]);

    QHBoxLayout* title = new QHBoxLayout();
    title->setAlignment(Qt::Alignment(Qt::AlignCenter));
    title->addWidget(regTitle);

    QHBoxLayout* buttonBox = new QHBoxLayout();
    buttonBox->addWidget(buttons["quit"]);
    buttonBox->addWidget(buttons["reg"]);

    QVBoxLayout* vBox = new QVBoxLayout();
    vBox->setMargin(15);
    vBox->setSpacing(15);
    vBox->addLayout(title);
    vBox->addLayout(form);
    vBox->addLayout(buttonBox);

    setLayout(vBox);
}

void MainWindow::connectslots()
{
    connect(buttons["quit"], &QPushButton::clicked, this, &MainWindow::quit);
    connect(buttons["reg"], &QPushButton::clicked, this, &MainWindow::registration);
}

void MainWindow::registration()
{
    getFields();
    if(!myBase->insertData(fields))
        qDebug() << "Cannot insert data " << endl;
    else
    {
        QMessageBox* message = new QMessageBox();
        clearFields();
        message->setText("Registration was complete");
        message->show();
    }
}

void MainWindow::quit()
{
    QApplication::quit();
}

void MainWindow::getFields()
{
    fields.insert("name", lineEdits["name"]->text());
    fields.insert("login", lineEdits["login"]->text());
    fields.insert("surname", lineEdits["surname"]->text());
    fields.insert("email", lineEdits["email"]->text());
    fields.insert("phone", lineEdits["phone"]->text());
    fields.insert("password", lineEdits["pass"]->text());
    validator();
}

void MainWindow::validator()
{
    QMessageBox* box = new QMessageBox();
    QString message;
    QMap<QString, QString>::iterator iter;

    for(iter = fields.begin(); iter != fields.end(); ++iter)
    {
        if(iter.value().size() == 0)
        {
            message.append("Field " + iter.key() + " is not fill \n");
        }

        if(iter.key() == "login")
        {
            if(myBase->findData(iter.key(), iter.value()))
                message.append("There is login into database \n");
        }

        if(iter.key() == "email")
        {
            if(myBase->findData(iter.key(), iter.value()))
                message.append("There is email into database \n");
        }

        if(iter.key() == "phone")
        {
            if(iter.value().size() != 11)
                message.append("Phone number is not correct. Need 11 characters \n");
            if(myBase->findData(iter.key(), iter.value()))
                message.append("There is phone number into database \n");
        }

        if(iter.key() == "password")
        {
            if(iter.value() != lineEdits["passRep"]->text())
                message.append("Passwords is not match \n");
            if(iter.value().size() <= 7)
                message.append("Password is short. Need greater then 7 characters \n");
        }
    }
    if(message.size() != 0)
    {
        box->setText(message);
        box->show();
    }
}

void MainWindow::clearFields()
{
    QMap<QString, QLineEdit*>::iterator lineIter;
    for(lineIter = lineEdits.begin(); lineIter != lineEdits.end(); ++lineIter)
        lineIter.value()->clear();
}

