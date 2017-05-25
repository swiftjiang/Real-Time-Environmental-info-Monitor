#ifndef QUART_H
#define QUART_H

#include <QObject>
#include <QTimer>
#include <QString>

#include "posix_qextserialport.h"
#include "qextserialbase.h"
#include "socket/chat_client.h"
#include "sqliteDatabase/databaseoperation.h"

class quart : public QObject
{
    Q_OBJECT
public:
    explicit quart(QObject *parent = 0);
    ~quart();


    //串口函数
    int setPortName(QString portName);
    int setReadTimeout(int timeout);
    int openPort();
    int setPortProperties();
    int connectPort();
    int disconnectPort();


signals:
    void showState(int major, int minor, int fire,int human,int gas,double temp);

public slots:
    void readMyCom();

private:
    Posix_QextSerialPort *myCom;
    QTimer *readTimer;

    //ChatClient  client;
};

#endif // QUART_H
