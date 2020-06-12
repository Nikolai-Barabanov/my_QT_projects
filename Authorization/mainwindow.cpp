#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    createDesign();
    data = new dataBase();
    data->createDataBase();
    data->createTable();
    data->insertData();
    connectSlots();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createDesign()
{
    QLabel* title = new QLabel("Добро пожаловать!");
    QHBoxLayout* titleBox = new QHBoxLayout();
    QFormLayout* form = new QFormLayout();
    QVBoxLayout* vBox = new QVBoxLayout();
    QHBoxLayout* hBox = new QHBoxLayout();

    buttons.insert("auth", new QPushButton("Авторизация"));
    buttons.insert("exit", new QPushButton("Выход"));

    lineEdits.insert("login", new QLineEdit());
    lineEdits.insert("pass", new QLineEdit());


    title->setAlignment(Qt::Alignment(Qt::AlignCenter));
    lineEdits["pass"]->setEchoMode(QLineEdit::Password);
    vBox->setMargin(20);
    vBox->setSpacing(20);
    titleBox->addWidget(title);

    form->addRow("Логин", lineEdits["login"]);
    form->addRow("Пароль", lineEdits["pass"]);

    hBox->addWidget(buttons["exit"]);
    hBox->addWidget(buttons["auth"]);

    vBox->addLayout(titleBox);
    vBox->addLayout(form);
    vBox->addLayout(hBox);

    setLayout(vBox);
}

void MainWindow::connectSlots()
{
    connect(buttons["exit"], &QPushButton::clicked, this, &MainWindow::quit);
    connect(buttons["auth"], &QPushButton::clicked, this, &MainWindow::authorization);
}

void MainWindow::authorization()
{
    if(!data->authorisation(getLogin(), getPassword()))
    {        
        QMessageBox msgBox;
        msgBox.setText("Login or password not correct");
        msgBox.exec();
    }
    else
    {
        next = new nextWindow();
        this->close();
        next->show();
    }
}

void MainWindow::quit()
{
    QApplication::quit();
}

QString* MainWindow::getLogin()
{
    login = lineEdits["login"]->text();
    return &login;
}

QString* MainWindow::getPassword()
{
    pass = lineEdits["pass"]->text();
    return &pass;
}
