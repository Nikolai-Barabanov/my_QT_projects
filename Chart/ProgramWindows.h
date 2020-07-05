#ifndef PROGRAMWINDOWS_H
#define PROGRAMWINDOWS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTableView>
#include <QtCharts>
#include <QComboBox>
#include <QLayout>
#include <QtSql>
#include <QMap>

class ProgramWindows : public QWidget
{
   Q_OBJECT
public:
    explicit ProgramWindows(QWidget* parent = nullptr);
    ~ProgramWindows();    
    void setModelQuery(QSqlQueryModel* model);
    void setChartView(QChart* chart);
    QString getTableName();    

signals:
    void quit();
    void change();
    void comboBoxActiv(QString name);

private slots:
    void onPushButtonQuit();    
    void comboBoxActivated(QString tableName);

private:
    QMap<QString, QPushButton*> myButtons;    
    QTableView* myView;
    QComboBox* comboBox;
    QChartView* myChartView;
    QString name;
    void createDesign();
    void connectSlots();
};

#endif // PROGRAMWINDOWS_H
