#ifndef JEOPARDY_H
#define JEOPARDY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Jeopardy; }
QT_END_NAMESPACE

class Jeopardy : public QMainWindow
{
    Q_OBJECT

public:
    Jeopardy(QWidget *parent = nullptr);
    ~Jeopardy();

private slots:
    void on_T1Q1_clicked();

    void on_T1Q2_clicked();

    void on_T1Q3_clicked();

    void on_T1Q4_clicked();

    void on_T1Q5_clicked();

    void on_T2Q1_clicked();

    void on_T2Q2_clicked();

    void on_T2Q3_clicked();

    void on_T2Q4_clicked();

    void on_T2Q5_clicked();

    void on_T3Q1_clicked();

    void on_T3Q2_clicked();

    void on_T3Q3_clicked();

    void on_T3Q4_clicked();

    void on_T3Q5_clicked();

    void on_T4Q1_clicked();

    void on_T4Q2_clicked();

    void on_T4Q3_clicked();

    void on_T4Q4_clicked();

    void on_T4Q5_clicked();

    void on_T5Q1_clicked();

    void on_T5Q2_clicked();

    void on_T5Q3_clicked();

    void on_T5Q4_clicked();

    void on_T5Q5_clicked();

    void on_correctBtn_clicked();

    void on_incorrectBtn_clicked();

    void on_manualComboBox_currentIndexChanged(int index);

    void on_answerBtn_clicked();

private:
    Ui::Jeopardy *ui;
};
#endif // JEOPARDY_H
