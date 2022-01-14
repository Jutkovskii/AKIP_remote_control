#ifndef AKIP_H
#define AKIP_H

#include <QObject>
#include <QTelnet.h>
#pragma comment ( lib, "ws2_32.lib" )
#include <winsock2.h>


class akip : public QObject
{
    Q_OBJECT
public:
    QTelnet telnet;
    explicit akip(QObject *parent = nullptr);
      explicit akip(QString IP, int port,QObject *parent = nullptr);
    ~akip();
    //строка с сохранением текущих значений тока и напряжкения
QString currentValues;
private slots:
//слот для приема данных от источника питания
void recieve(const char *buff, int len);


public slots:
//соединение с источником питания с указанным адресом и портом
void connect(QString IP, int port);
//разъединение
void disconnect();
//отправить команду
void send(QString command);
//запрос текущих значений  тока и напряжения
QString getValues();
};

#endif // AKIP_H
