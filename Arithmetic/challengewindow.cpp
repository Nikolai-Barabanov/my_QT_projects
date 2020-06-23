#include "challengewindow.h"

ChallengeWindow::ChallengeWindow(QWidget* parent): QWidget(parent)
{    
    createDesign();
    connectSlots();
}

ChallengeWindow::~ChallengeWindow()
{

}

void ChallengeWindow::createDesign()
{
    this->setMinimumSize(450, 450);
    this->setMaximumSize(450, 600);

    QLabel* title = new QLabel("Решите следующие примеры");
    title->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QVBoxLayout* generalBox = new QVBoxLayout();
    generalBox->setSpacing(15);

    QVBoxLayout* tasks = new QVBoxLayout();
    QVBoxLayout* lines = new QVBoxLayout();
    QVBoxLayout* res = new QVBoxLayout();
    res->setAlignment(Qt::Alignment(Qt::AlignLeft));

    QHBoxLayout* taskForm = new QHBoxLayout();
    QHBoxLayout* buttonBox = new QHBoxLayout();

    for(int i = 0; i < 15; ++i)
    {
        QString taskNumber = QString::number(i);
        lineEdits.insert(taskNumber, new QLineEdit());
        labels.insert(taskNumber, new QLabel());
        results.insert(taskNumber, new QLabel());
        tasks->addWidget(labels[taskNumber]);
        lines->addWidget(lineEdits[taskNumber]);
        res->addWidget(results[taskNumber]);
    }

    taskForm->addLayout(tasks);
    taskForm->addLayout(lines);    
    //taskForm->addStretch(1);
    taskForm->addLayout(res);

    buttons.insert("check", new QPushButton("Проверка"));
    buttons.insert("back", new QPushButton("Назад"));
    buttons.insert("refresh", new QPushButton("Обновить"));

    buttonBox->addWidget(buttons["back"]);
    buttonBox->addWidget(buttons["refresh"]);
    buttonBox->addWidget(buttons["check"]);

    generalBox->addWidget(title);
    generalBox->addLayout(taskForm);
    generalBox->addLayout(buttonBox);
    setLayout(generalBox);
}

void ChallengeWindow::connectSlots()
{
    connect(buttons["back"], &QPushButton::clicked,
            this, &ChallengeWindow::pushButtonBack);
    connect(buttons["check"], &QPushButton::clicked,
            this, &ChallengeWindow::pushButtonCheck);
    connect(buttons["refresh"], &QPushButton::clicked,
            this, &ChallengeWindow::pushButtonRefresh);
}

void ChallengeWindow::pushButtonBack()
{
    this->close();
    emit back();
}

void ChallengeWindow::pushButtonCheck()
{    
    emit check();
}

void ChallengeWindow::pushButtonRefresh()
{
    emit refresh();
}

QMap<QString, QLineEdit*>* ChallengeWindow::getLineEdits()
{
    return &lineEdits;
}

QMap<QString, QLabel*>* ChallengeWindow::getLabels()
{
    return &labels;
}

QMap<QString, QLabel*>* ChallengeWindow::getResult()
{
    return &results;
}
