#include "jeopardy.h"
#include "ui_jeopardy.h"

Jeopardy::Jeopardy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Jeopardy)
{
    ui->setupUi(this);
}

Jeopardy::~Jeopardy()
{
    delete ui;
}

