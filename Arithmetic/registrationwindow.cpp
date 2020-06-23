#include "registrationwindow.h"

RegistrationWindow::RegistrationWindow(QWidget *parent): QWidget(parent)
{
    createDesign();
    connectslots();
}

RegistrationWindow::~RegistrationWindow()
{
}

void RegistrationWindow::createDesign()
{
    this->setMaximumSize(350, 300);

    QLabel* regTitle = new QLabel("Регистрация");
    lineEdits.insert("regName",new QLineEdit());
    lineEdits.insert("regLogin",new QLineEdit());
    lineEdits.insert("regPassword",new QLineEdit());
    lineEdits.insert("passRep",new QLineEdit());
    lineEdits["regPassword"]->setEchoMode(QLineEdit::Password);
    lineEdits["passRep"]->setEchoMode(QLineEdit::Password);

    buttons.insert("reg", new QPushButton("Регистрация"));
    buttons.insert("quit", new QPushButton("Выход"));
    buttons.insert("back", new QPushButton("Назад"));

    QFormLayout* form = new QFormLayout();
    form->addRow("Имя", lineEdits["regName"]);
    form->addRow("Логин", lineEdits["regLogin"]);
    form->addRow("Пароль", lineEdits["regPassword"]);
    form->addRow("Повторите пароль", lineEdits["passRep"]);

    QHBoxLayout* title = new QHBoxLayout();
    title->setAlignment(Qt::Alignment(Qt::AlignCenter));
    title->addWidget(regTitle);

    QHBoxLayout* buttonBox = new QHBoxLayout();
    buttonBox->addWidget(buttons["back"]);
    buttonBox->addWidget(buttons["reg"]);

    QHBoxLayout* buttonBoxQuit = new QHBoxLayout();
    buttonBoxQuit->addWidget(buttons["quit"]);

    QVBoxLayout* vBox = new QVBoxLayout();
    vBox->setMargin(15);
    vBox->setSpacing(15);
    vBox->addLayout(title);
    vBox->addLayout(form);
    vBox->addLayout(buttonBox);
    vBox->addLayout(buttonBoxQuit);

    setLayout(vBox);
}

void RegistrationWindow::connectslots()
{
    connect(buttons["quit"], &QPushButton::clicked, this, &RegistrationWindow::pushButtonQuit);
    connect(buttons["reg"], &QPushButton::clicked, this, &RegistrationWindow::pushButtonReg);
    connect(buttons["back"], &QPushButton::clicked, this, &RegistrationWindow::pushButtonBack);
}

void RegistrationWindow::pushButtonReg()
{
    emit registration();
}

void RegistrationWindow::pushButtonQuit()
{
    emit quit();
}

void RegistrationWindow::pushButtonBack()
{
    this->close();
    emit back();
}

QMap<QString, QLineEdit*>* RegistrationWindow::getLineEdits()
{
    return &lineEdits;
}
