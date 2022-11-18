/// @file fenetre.h
/// @version 5.15.2 qt
/// @author M.Bulcke
#include "fenetre.h"
#include <QtNetwork>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fenetre w;
    w.show();
    return a.exec();
}
