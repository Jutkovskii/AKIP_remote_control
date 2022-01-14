#include "akip.h"

akip::akip(QString IP, int port,QObject *parent) : QObject(parent)
{
telnet.connectToHost(IP,port);
  QObject::connect(&telnet, SIGNAL(newData(const char*, int)),this,SLOT(recieve(const char*, int)));
}

akip::akip(QObject *parent) : QObject(parent)
{

  QObject::connect(&telnet, SIGNAL(newData(const char*, int)),this,SLOT(recieve(const char*, int)));
}

akip::~akip()
{
disconnect();
}


void akip::disconnect()
{

    send("OUTP OFF\n");
    send("SYST:LOC\n");
    telnet.disconnectFromHost();
}

void akip::connect(QString IP, int port)
{

    telnet.connectToHost(IP,port);

}

void akip::send(QString command)
{
telnet.sendData(command.toLatin1()+"\n");
}
void akip::recieve(const char *buff, int len)
{
currentValues.clear();
for(int i=0;i<len;i++)
    currentValues.append(buff[i]);
}
QString akip::getValues()
{
send("FETC?");
Sleep(1);
return currentValues;
}
