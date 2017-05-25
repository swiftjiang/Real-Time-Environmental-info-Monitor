#include "savedatabase.h"

SaveData SaveDatabase::newSaveData;

SaveDatabase::SaveDatabase(QObject *parent) : QObject(parent)
{

}

SaveDatabase::~SaveDatabase()
{

}

void SaveDatabase::setSaveData(const int majorNum, const int minorNum, const int fire, const int human, const double temperature, int smoke)
{
    newSaveData.majorNum=majorNum;
    newSaveData.minorNum=minorNum;
    newSaveData.fire=fire;
    newSaveData.human=human;
    newSaveData.temperature=temperature;
    newSaveData.smoke=smoke;
    newSaveData.dateTime=newSaveData.dateTime.currentDateTime();
}

SaveData SaveDatabase::getSaveData()
{
    return newSaveData;
}

void SaveDatabase::debug_info(QString str, SaveData data)
{
    qDebug()<<str<<":***********************************\n-----newSaveData info is-----" \
    <<"\nmajor="<<data.majorNum \
    <<"\nminor="<<data.minorNum \
    <<"\nfire="<<data.fire \
    <<"\nhuman="<<data.human \
    <<"\ntemperature="<<data.temperature \
    <<"\nsmoke="<<data.smoke \
    <<"\ndatetime="<<data.dateTime.toString("yyyy-MM-dd hh:mm:ss") \
    <<"\n----------------------------";
}

bool SaveDatabase::createTable()
{
    QSqlQuery query(DatabaseOperation::myDatabase);

    QString strSql = "create table savedata(id integer PRIMARY KEY,major INTEGER,minor INTEGER,fire INTEGER,human INTEGER,temperature REAL,smoke INTEGER,datetime TEXT);";
    bool createRet=query.exec(strSql);//建表
    if(!createRet)
    {
        qDebug()<<"SaveDatabase::createTable():create table failed !";
        return false;
    }

    return true;
}

bool SaveDatabase::addSaveData()
{
    debug_info("SaveDatabase::addSaveData()",newSaveData);
    QSqlQuery query(DatabaseOperation::myDatabase);

    QString strSql("insert into savedata(major,minor,fire,human,temperature,smoke,datetime) values (:major,:minor,:fire,:human,:temperature,:smoke,:datetime)"); //需要绑定的字段
    query.prepare(strSql);
    query.bindValue(":major",newSaveData.majorNum);
    query.bindValue(":minor",newSaveData.minorNum);
    query.bindValue(":fire",newSaveData.fire);
    query.bindValue(":human",newSaveData.human);
    query.bindValue(":temperature",newSaveData.temperature);
    query.bindValue(":smoke",newSaveData.smoke);
    query.bindValue(":datetime",newSaveData.dateTime.toString("yyyy-MM-dd hh:mm:ss"));

    bool bResult = query.exec();
    if(!bResult)
    {
        qDebug()<<"SaveDatabase::addSaveData():add savedata failed !";
        return false;
    }
    qDebug()<<"SaveDatabase::addSaveData():add savedata successfully !";
    return true;

}

bool SaveDatabase::removeSaveData()
{
    int flag=-1;//0-majorNum;1-minorNum;2-同时查
    if(newSaveData.majorNum!=-1)
    {
        flag=0;
    }
    if(newSaveData.minorNum!=-1)
    {
        flag=1;
    }
    if(newSaveData.majorNum!=-1 && newSaveData.minorNum!=-1)
    {
        flag=2;
    }
    QSqlQuery query(DatabaseOperation::myDatabase);
    QString strSql = "";


    if(flag==0)
    {
        strSql+="delete from savedata where major = :major";
        query.prepare(strSql);
        query.bindValue(":major",newSaveData.majorNum);
        bool bResult=query.exec();

        if(!bResult)
        {
            qDebug()<<"SaveDatabase::removeSaveData():remove data failed !";
            return false;
        }
    }

    else if(flag==1)
    {
        strSql+="delete from savedata where minor = :minor";
        query.prepare(strSql);
        query.bindValue(":minor",newSaveData.minorNum);
        bool bResult=query.exec();

        if(!bResult)
        {
            qDebug()<<"SaveDatabase::removeSaveData():remove data failed !";
            return false;
        }
    }

    else if(flag==2)
    {
        strSql+="delete from savedata where major = :major and minor = :minor";
        query.prepare(strSql);
        query.bindValue(":major",newSaveData.majorNum);
        query.bindValue(":minor",newSaveData.minorNum);
        bool bResult=query.exec();

        if(!bResult)
        {
            qDebug()<<"SaveDatabase::removeSaveData():remove data failed !";
            return false;
        }
    }

    qDebug()<<"SaveDatabase::removeSaveData():remove data successfully !";
    return true;
}

bool SaveDatabase::searchSaveData(QList<SaveData> &data)
{
    debug_info("SaveDatabase::searchSaveData()",newSaveData);
    QSqlQuery query(DatabaseOperation::myDatabase);
    QString strSql = "";
    strSql+="select * from savedata where major = :major and minor = :minor";
    query.prepare(strSql);
    query.bindValue(":major",newSaveData.majorNum);
    query.bindValue(":minor",newSaveData.minorNum);
    bool bResult=query.exec();

    if(!bResult)
    {
        qDebug()<<"SaveDatabase::searchSaveData():search data failed !";
        return false;
    }
    else
    {
        SaveData tempData;
        while(query.next())
        {
            tempData.majorNum=query.value(1).toInt();
            tempData.minorNum=query.value(2).toInt();
            tempData.fire=query.value(3).toInt();
            tempData.human=query.value(4).toInt();
            tempData.temperature=query.value(5).toDouble();
            tempData.smoke=query.value(6).toInt();
            //qDebug()<<"get time "<<query.value(7);
            //QString time=query.value(7).toString("");
            tempData.dateTime=query.value(7).toDateTime();

            data.append(tempData);
        }
    }

    qDebug()<<"SaveDatabase::searchSaveData():search data successfully !";
    return true;
}
