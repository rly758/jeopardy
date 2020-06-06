#include "jeopardy.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Jeopardy w;
    w.show();
    return a.exec();
}
