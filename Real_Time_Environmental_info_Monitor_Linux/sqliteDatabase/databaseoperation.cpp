#include "databaseoperation.h"




QSqlDatabase DatabaseOperation::myDatabase;

DatabaseOperation::DatabaseOperation(QObject *parent) : QObject(parent)
{

}

DatabaseOperation::~DatabaseOperation()
{

}

bool DatabaseOperation::createDataFile(const QString &strFileName)
{
    if(!QFile::exists(strFileName))//文件不存在，则创建
    {
        QDir fileDir = QFileInfo(strFileName).absoluteDir();
        QString strFileDir = QFileInfo(strFileName).absolutePath();
        if(!fileDir.exists()) //路径不存在，创建路径
        {
            fileDir.mkpath(strFileDir);
        }
        QFile dbFile(strFileName);
        if(!dbFile.open(QIODevice::WriteOnly))//未成功打开
        {
            dbFile.close();
            return false;
        }
        dbFile.close();
    }
    return true;
}

bool DatabaseOperation::openDataBase(const QString &strFileName)
{
    myDatabase = QSqlDatabase::addDatabase("QSQLITE");
    myDatabase.setDatabaseName(strFileName);
    if(myDatabase.open())
    {
        return true;
    }
    return false;
}

void DatabaseOperation::closeDataBase()
{
    myDatabase.close();
}

bool DatabaseOperation::isExistTable(const QString &strTableName)
{
    QSqlQuery query(myDatabase);
    QString strSql = QString("SELECT 1 FROM sqlite_master where type = 'table' and  name = '%1'").arg(strTableName);
    query.exec(strSql);
    if(query.next())
    {
        int nResult = query.value(0).toInt();//有表时返回1，无表时返回null
        if(nResult)
        {
            return true;
        }
    }
    return false;
}

bool DatabaseOperation::isExistField(const QString &strTableName, const QString &strFieldName)
{
    QSqlQuery query(myDatabase);
    QString strSql = QString("SELECT 1 FROM sqlite_master where type = 'table'"
                             " and name= '%1' and sql like '%%2%'").arg(strTableName).arg(strFieldName);
    query.exec(strSql);
    if(query.next())
    {
        int nResult = query.value(0).toInt();//有此字段时返回1，无字段时返回null
        if(nResult)
        {
            return true;
        }
    }
    return false;
}

void DatabaseOperation::initDatabase()
{
    //初始化数据库
    QString strDbFile = "mydata.db";
    createDataFile(strDbFile); //在程序目录创建data.db文件
    if(!openDataBase(strDbFile))
    {
        qDebug()<<"DatabaseOperation::dbTest():open database failed !";
    }

    //***********************************************初始化accountdatabase

    if(!isExistTable("account"))
    {
        AccountDatabase::createTable();
        qDebug() << "create account table.";
        if(!isExistField("account","accountNum"))
        {
            qDebug() <<  "accountNum not exist";
        }
    }

    //*************************************************初始化savedatabase

    if(!isExistTable("savedata"))
    {
        SaveDatabase::createTable();
        qDebug() << "create savedata table.";
        if(!isExistField("savedata","major"))
        {
            qDebug() <<  "major not exist";
        }
    }
    qDebug()<<"init database over!";
}

