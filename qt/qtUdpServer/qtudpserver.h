#ifndef QTUDPSERVER_H
#define QTUDPSERVER_H

#include <QObject>
#include <QUdpSocket>

class qtUdpServer : public QObject
{
    Q_OBJECT
public:
    explicit qtUdpServer(QObject *parent = nullptr);

signals:

public slots:
    void readPendingDatagrams();

private:
    QUdpSocket* udpSocket;
};

#endif // QTUDPSERVER_H
