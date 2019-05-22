#include "udpserver.h"

UdpServer::UdpServer(QObject *parent) : QObject(parent)
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(2525);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}


void UdpServer::readPendingDatagrams()
{
    QByteArray buf;
    while(udpSocket->hasPendingDatagrams())
    {
        buf.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(buf.data(), buf.size());
        qDebug() << "Recive: " << buf.data();
    }
}
