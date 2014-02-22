#ifndef URLGETTASK_H
#define URLGETTASK_H

#include <QObject>
#include <QNetworkAccessManager>

class UrlGetTask : public QObject
{
    Q_OBJECT
public:
    explicit UrlGetTask(QObject *parent = 0);

signals:
    void finished();

public slots:
    void run();
    void printUrl(QNetworkReply *reply);

private:
    QNetworkAccessManager m_network;
};

#endif // URLGETTASK_H
