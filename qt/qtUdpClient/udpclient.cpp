#include "udpclient.h"

UdpClient::UdpClient(QObject *parent) : QObject(parent)
{
    udpSocket = new QUdpSocket(this);
    QTimer* mytimer = new QTimer(this);
    mytimer->setInterval(1000);
    mytimer->start();
    connect(mytimer, SIGNAL(timeout()), SLOT(slotSendDatagram()));
}

void UdpClient::slotSendDatagram()
{
    qDebug() << "Send";
    QByteArray buf;
    buf.append("Message");
    udpSocket->writeDatagram(buf, QHostAddress::LocalHost, 2525);
}

