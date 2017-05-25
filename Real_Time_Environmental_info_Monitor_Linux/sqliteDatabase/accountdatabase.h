#ifndef ACCOUNTDATABASE_H
#define ACCOUNTDATABASE_H

#include <QObject>
#include <QStringList>
#include <QDebug>
#include <QtSql/QSqlQuery>

#include "savedatastructure.h"
#include "databaseoperation.h"


class AccountDatabase : public QObject
{
    Q_OBJECT
public:
    explicit AccountDatabase(QObject *parent = 0);
    ~AccountDatabase();

signals:

public slots:

private:
    static Account newAccount;
public:
    static void setAccount(const QString& accountNum,const QString& passwd);
    static Account getAccount();

    static bool createTable(); //创建表
    static bool addAccount();//添加帐户
    static bool isExistAccount(const QString& accountNum);
    static bool checkAccountPasswd();//验证账号密码
    static bool getAllAccount(QList<Account> &account);//获取所有帐号和修改时间的信息
    static bool removeAccount();//删除帐户,flag标识条件
    static bool updateAccount();//更新帐户
    //static QStringList searchByBookName(const Account& account);//查找
};

#endif // ACCOUNTDATABASE_H
