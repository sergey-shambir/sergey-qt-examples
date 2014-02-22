
#include "UrlGetTask.h"
#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    UrlGetTask *task = new UrlGetTask();
    QObject::connect(task, SIGNAL(finished()), &a, SLOT(quit()));
    QTimer::singleShot(0, task, SLOT(run()));

    return a.exec();
}
