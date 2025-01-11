#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDataStream>
#include <QByteArray>
#include <QHostAddress>
#include <QNetworkInterface>




class Socket
{
public:
    Socket();
    QTcpSocket *socket;
    QTcpServer *server;
    QDataStream *dataStream;
    QByteArray *byteArray;
    QHostAddress *hostAddress;
    QNetworkInterface *networkInterface;
    void connectToServer();
    void connectToClient();
    void sendData();
    void receiveData();
    void closeConnection();
    void setHostAddress(QHostAddress *hostAddress);
    void setNetworkInterface(QNetworkInterface *networkInterface);
    void setByteArray(QByteArray *byteArray);
    void setDataStream(QDataStream *dataStream);
    void setSocket(QTcpSocket *socket);
    void setServer(QTcpServer *server);
    QHostAddress *getHostAddress();
    QNetworkInterface *getNetworkInterface();
    QByteArray *getByteArray();
    QDataStream *getDataStream();
    QTcpSocket *getSocket();
    QTcpServer *getServer();
    ~Socket();
};

#endif // SOCKET_H
