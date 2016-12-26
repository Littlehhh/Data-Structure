#include "ferrysystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FerrySystem w;
    w.show();

    return a.exec();
}
