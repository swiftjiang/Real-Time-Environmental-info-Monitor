#include "accountdatabase.h"

Account AccountDatabase::newAccount;

AccountDatabase::AccountDatabase(QObject *parent) : QObject(parent)
{

}

AccountDatabase::~AccountDatabase()
{

}

void AccountDatabase::setAccount(const QString &accountNum, const QString &passwd)
{
    newAccount.num=accountNum;
    newAccount.passwd=passwd;
    newAccount.dateTime=newAccount.dateTime.currentDateTime();//获取时间
}

Account AccountDatabase::getAccount()
{
    return newAccount;
}

bool AccountDatabase::createTable()
{
    QSqlQuery query(DatabaseOperation::myDatabase);

    QString strSql = "create table account(accountNum TEXT PRIMARY KEY  , passwd TEXT,datetime TEXT);";
    bool createRet=query.exec(strSql);//建表
    if(!createRet)
    {
        qDebug()<<"AccountDatabase::createTable():create table failed !";
        return false;
    }

    QString strIndexSql = "create index account_index1 on account(accountNum);";
    bool bResult = query.exec(strIndexSql); //创建索引
    if(!bResult)
    {
        qDebug()<<"AccountDatabase::createTable():create INDEX failed !";
        //删除表
        QString strDelTableSql="drop table account;";
        bool delResult=query.exec(strDelTableSql);
        if(!delResult)
        {
            qDebug()<<"AccountDatabase::createTable():delete table failed !";
        }
        return false;
    }

    return true;
}

bool AccountDatabase::addAccount()
{
    qDebug()<<"AccountDatabase::addAccount():***********************************\n-----newAccount info is-----\naccountNum="<<newAccount.num \
           <<"\npasswd="<<newAccount.passwd<<"\ndatetime="<<newAccount.dateTime.toString("yyyy-MM-dd hh:mm:ss") \
          <<"\n----------------------------";

    if(isExistAccount(newAccount.num))
    {
        qDebug()<<"AccountDatabase::addAccount():add account failed !";
        return false;
    }
    QSqlQuery query(DatabaseOperation::myDatabase);

    QString strSql("insert into account(accountNum, passwd,datetime) values (:accountNum, :passwd, :datetime)"); //需要绑定的字段
    query.prepare(strSql);
    query.bindValue(":accountNum",newAccount.num);
    query.bindValue(":passwd",newAccount.passwd);
    query.bindValue(":datetime",newAccount.dateTime.toString("yyyy-MM-dd hh:mm:ss"));

    //qDebug()<<"strSql is :"<<strSql;

    bool bResult = query.exec();
    if(!bResult)
    {
        qDebug()<<"AccountDatabase::addAccount():add account failed !";
        return false;
    }
    qDebug()<<"AccountDatabase::addAccount():add account successfully !";
    return true;
}

bool AccountDatabase::isExistAccount(const QString &accountNum)
{
    qDebug()<<"AccountDatabase::isExistAccount()***********************************";
    QSqlQuery query(DatabaseOperation::myDatabase);

    QString strSql = "select * from account where accountNum = :accountNum";
    query.prepare(strSql);
    query.bindValue(":accountNum",accountNum);
    bool bResult=query.exec();
    query.last();
    int size=query.at()+1;

    if(!bResult)
    {
        qDebug()<<"AccountDatabase::isExistAccount():check account failed !";
        return false;
    }
    if(size==1)
    {
        qDebug()<<"AccountDatabase::isExistAccount():record is exist !";
        return true;
    }
    return false;
}

bool AccountDatabase::checkAccountPasswd()
{
    qDebug()<<"AccountDatabase::checkAccountPasswd()***********************************\n-----newAccount info is-----\naccountNum=" \
           <<newAccount.num<<"\npasswd="<<newAccount.passwd<<"\ndatetime=" \
           <<newAccount.dateTime.toString("yyyy-MM-dd hh:mm:ss") \
           <<"\n----------------------------";

    QSqlQuery query(DatabaseOperation::myDatabase);

    QString strSql = "select accountNum,passwd from account where accountNum = :accountNum and passwd = :passwd";
    query.prepare(strSql);
    query.bindValue(":accountNum",newAccount.num);
    query.bindValue(":passwd",newAccount.passwd);
    bool bResult=query.exec();

    if(!bResult)
    {
        qDebug()<<"AccountDatabase::checkAccountPasswd():check accountPasswd failed !";
        return false;
    }
    qDebug()<<"AccountDatabase::checkAccountPasswd():check accountPasswd successfully !";
//    query.last();
//    int mm=query.at()+1;
//    qDebug()<<"==============="<<mm;
//    qDebug()<<"account database info"<<query.value(0) <<","<<query.value(1);
    query.first();
    QString aco=query.value(0).toString();
    QString pas=query.value(1).toString();
    qDebug()<<"account database info"<<aco<<","<<pas;
    if(aco==newAccount.num && pas==newAccount.passwd)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool AccountDatabase::getAllAccount(QList<Account> &account)
{
    QSqlQuery query(DatabaseOperation::myDatabase);
    QString strSql = "select accountNum,datetime from account;";
    bool bResult=query.exec(strSql);

    if(!bResult)
    {
        qDebug()<<"AccountDatabase::getAllAccount():get all account failed !";
        return false;
    }
    else
    {
        Account tempAccount;
        while(query.next())
        {
            tempAccount.num=query.value(0).toString();
            tempAccount.dateTime=query.value(1).toDateTime();
            account.append(tempAccount);
        }
    }

    qDebug()<<"SaveDatabase::searchSaveData():getAllAccount successfully !";
    return true;
}

bool AccountDatabase::removeAccount()
{
    qDebug()<<"AccountDatabase::removeAccount()***********************************\n-----newAccount info is-----\naccountNum=" \
           <<newAccount.num<<"\npasswd="<<newAccount.passwd<<"\ndatetime=" \
           <<newAccount.dateTime.toString("yyyy-MM-dd hh:mm:ss") \
           <<"\n----------------------------";

    QSqlQuery query(DatabaseOperation::myDatabase);

    if(isExistAccount(newAccount.num))
    {
        QString strSql = "delete from account where accountNum = :accountNum";
        query.prepare(strSql);
        query.bindValue(":accountNum",newAccount.num);
        bool bResult=query.exec();

        if(!bResult)
        {
            qDebug()<<"AccountDatabase::removeAccount():remove account failed !";
            return false;
        }
    }
    else
    {
        qDebug()<<"AccountDatabase::removeAccount():account isn't exist !";
        return false;
    }
    qDebug()<<"AccountDatabase::removeAccount():remove account successfully !";
    return true;
}

bool AccountDatabase::updateAccount()
{
    qDebug()<<"AccountDatabase::updateAccount()***********************************\n-----newAccount info is-----\naccountNum="<<newAccount.num \
           <<"\npasswd="<<newAccount.passwd<<"\ndatetime="<<newAccount.dateTime.toString("yyyy-MM-dd hh:mm:ss") \
          <<"\n----------------------------";

    QSqlQuery query(DatabaseOperation::myDatabase);

    if(isExistAccount(newAccount.num))
    {
        QString strSql = "update account set passwd = :passwd,datetime=:datetime where accountNum = :accountNum";
        query.prepare(strSql);
        query.bindValue(":passwd",newAccount.passwd);
        query.bindValue(":datetime",newAccount.dateTime.toString("yyyy-MM-dd hh:mm:ss"));
        query.bindValue(":accountNum",newAccount.num);
        bool bResult=query.exec();

        if(!bResult)
        {
            qDebug()<<"AccountDatabase::updateAccount():update account failed !";
            return false;
        }
    }
    else
    {
        qDebug()<<"AccountDatabase::removeAccount():account isn't exist !";
        return false;
    }
    qDebug()<<"AccountDatabase::updateAccount():update account successfully !";
    return true;
}
