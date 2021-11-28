#include "QtReportCompare.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath("./");
    QApplication a(argc, argv);
    QtReportCompare w;
    w.show();
    return a.exec();
}
