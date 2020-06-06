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

private:
    Ui::Jeopardy *ui;
};
#endif // JEOPARDY_H
