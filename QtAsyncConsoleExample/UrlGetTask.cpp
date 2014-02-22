#include "UrlGetTask.h"
#include <QNetworkReply>
#include <QCoreApplication>
#include <QStringList>
#include <stdio.h>

UrlGetTask::UrlGetTask(QObject *parent) :
    QObject(parent)
{
    connect(&m_network, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(printUrl(QNetworkReply *)));
}

void UrlGetTask::run()
{
    QStringList args = QCoreApplication::arguments();
    if (args.size() != 2) {
        fprintf(stdout, "Usage: QtAsyncConsoleExample <url_to_get>\n");
        emit finished();
    } else {
        QNetworkRequest request(args[1]);
        m_network.get(request);
    }
}

void UrlGetTask::printUrl(QNetworkReply *reply)
{
    QByteArray content = reply->readAll();
    fprintf(stdout, "%s\n", content.data());
    emit finished();
}
