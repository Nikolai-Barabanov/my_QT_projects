#include "authorizationwindow.h"

AuthorizationWindow::AuthorizationWindow(QWidget *parent) : QWidget(parent)
{
    createDesign();
    connectSlots();
}

AuthorizationWindow::~AuthorizationWindow()
{
}

void AuthorizationWindow::createDesign()
{
    this->setMaximumSize(350, 250);

    QLabel* title = new QLabel("Добро пожаловать!");
    QHBoxLayout* titleBox = new QHBoxLayout();
    QFormLayout* form = new QFormLayout();
    QVBoxLayout* vBox = new QVBoxLayout();
    QHBoxLayout* hBox = new QHBoxLayout();
    QHBoxLayout* hRegBox = new QHBoxLayout();

    buttons.insert("auth", new QPushButton("Авторизация"));
    buttons.insert("exit", new QPushButton("Выход"));
    buttons.insert("registr", new QPushButton("Регистрация"));

    lineEdits.insert("authLogin", new QLineEdit());
    lineEdits.insert("authPassword", new QLineEdit());


    title->setAlignment(Qt::Alignment(Qt::AlignCenter));
    lineEdits["authPassword"]->setEchoMode(QLineEdit::Password);
    vBox->setMargin(20);
    vBox->setSpacing(20);
    titleBox->addWidget(title);

    form->addRow("Логин", lineEdits["authLogin"]);
    form->addRow("Пароль", lineEdits["authPassword"]);

    hBox->addWidget(buttons["registr"]);
    hBox->addWidget(buttons["auth"]);

    hRegBox->addWidget(buttons["exit"]);

    vBox->addLayout(titleBox);
    vBox->addLayout(form);
    vBox->addLayout(hBox);
    vBox->addLayout(hRegBox);

    setLayout(vBox);
}

void AuthorizationWindow::connectSlots()
{
    connect(buttons["exit"], &QPushButton::clicked,
            this, &AuthorizationWindow::pushButtonQuit);
    connect(buttons["auth"], &QPushButton::clicked,
            this, &AuthorizationWindow::pushButtonAuthorization);
    connect(buttons["registr"], &QPushButton::clicked,
            this, &AuthorizationWindow::pushButtonRegistration);
}

void AuthorizationWindow::pushButtonQuit()
{
    emit quit();
}

void AuthorizationWindow::pushButtonAuthorization()
{
    emit authorization();
}

void AuthorizationWindow::pushButtonRegistration()
{
    this->close();
    emit registration();
}

QMap<QString, QLineEdit*>* AuthorizationWindow::getLineEdits()
{
    return &lineEdits;
}
