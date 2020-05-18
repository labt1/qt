#include "inteface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inteface w;
    w.show();
    return a.exec();
}
