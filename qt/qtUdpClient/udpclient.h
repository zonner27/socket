#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>

class UdpClient : public QObject
{
    Q_OBJECT
public:
    explicit UdpClient(QObject *parent = nullptr);

signals:


private slots:
    void slotSendDatagram();

private:
    QUdpSocket* udpSocket;

};

#endif // UDPCLIENT_H
