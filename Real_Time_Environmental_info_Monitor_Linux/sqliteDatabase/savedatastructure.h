#ifndef SAVEDATASTRUCTURE_H
#define SAVEDATASTRUCTURE_H

#include <QString>
#include <QDateTime>
//帐户
struct Account
{
    QString num;
    QString passwd;
    QDateTime dateTime;//修改时间
};

//存储信息
struct SaveData
{
    int majorNum;
    int minorNum;
    int fire;
    int human;
    double temperature;
    int smoke;
    QDateTime dateTime;//存储时间
};

//系统日志
struct System_info
{
    QString event;
    QDateTime dateTime;
};

#endif // SAVEDATASTRUCTURE_H
