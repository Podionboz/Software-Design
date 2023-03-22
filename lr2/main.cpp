#include "lr2.h"
#include "lr1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    lr2 w;
    w.show();

    return a.exec();
}
