#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>

class UdpServer : public QObject
{
    Q_OBJECT
public:
    explicit UdpServer(QObject *parent = nullptr);

signals:

private slots:
    void readPendingDatagrams();

private:
    QUdpSocket* udpSocket;
};

#endif // UDPSERVER_H
