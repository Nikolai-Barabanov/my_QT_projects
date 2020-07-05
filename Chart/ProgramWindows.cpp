#include "ProgramWindows.h"

ProgramWindows::ProgramWindows(QWidget* parent)
    : QWidget(parent)
{        
    myChartView = new QChartView();
    createDesign();
    connectSlots();
}

ProgramWindows::~ProgramWindows()
{

}

void ProgramWindows::createDesign()
{
    this->setMinimumSize(800, 600);    

    QHBoxLayout* generalBox = new QHBoxLayout();
    QHBoxLayout* buttonBox = new QHBoxLayout();
    QVBoxLayout* box1 = new QVBoxLayout();
    QVBoxLayout* box2 = new QVBoxLayout();   

    QLabel* title = new QLabel("Выберете отображаемые данные");
    title->setAlignment(Qt::Alignment(Qt::AlignCenter));
    comboBox = new QComboBox();
    myView = new QTableView();
    myButtons.insert("quit", new QPushButton("Выход"));    

    comboBox->addItem("data12");
    comboBox->addItem("data253");    

    box1->addWidget(title);
    box1->addWidget(comboBox);
    box1->addWidget(myView);
    buttonBox->addWidget(myButtons["quit"]);    
    box1->addLayout(buttonBox);
    box1->setSpacing(30);

    box2->addWidget(myChartView);

    generalBox->addLayout(box1);
    generalBox->addLayout(box2);

    setLayout(generalBox);
    connectSlots();
}

void ProgramWindows::connectSlots()
{
    connect(myButtons["quit"], &QPushButton::clicked, this, &ProgramWindows::onPushButtonQuit);    
    connect(comboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated),
            this, &ProgramWindows::comboBoxActivated);
}

void ProgramWindows::onPushButtonQuit()
{
    emit quit();
}

void ProgramWindows::comboBoxActivated(QString tableName)
{
    name = tableName;
    emit comboBoxActiv(name);
}

void ProgramWindows::setModelQuery(QSqlQueryModel* model)
{
    myView->setModel(model);
    myView->show();
}

void ProgramWindows::setChartView(QChart *chart)
{
    myChartView->setChart(chart);
    myChartView->setRenderHint(QPainter::Antialiasing);
}

QString ProgramWindows::getTableName()
{
    return comboBox->currentText();
}
