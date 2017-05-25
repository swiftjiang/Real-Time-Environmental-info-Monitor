#ifndef SaveDatabase_H
#define SaveDatabase_H

#include <QObject>

#include <QStringList>
#include <QDebug>
#include <QtSql/QSqlQuery>

#include "savedatastructure.h"
#include "databaseoperation.h"

class SaveDatabase : public QObject
{
    Q_OBJECT
public:
    explicit SaveDatabase(QObject *parent = 0);
    ~SaveDatabase();

signals:

public slots:

private:
    static SaveData newSaveData;
public:
    /*
    int majorNum;
    int minorNum;
    int fire;
    int human;
    double temperature;
    int smoke;
    QDateTime dateTime;//存储时间
    */
    static void setSaveData(const int majorNum,const int minorNum,const int fire,const int human,const double temperature,int smoke);
    static SaveData getSaveData();
    static void debug_info(QString str,SaveData data);

    static bool createTable(); //创建表
    static bool addSaveData();//添加
    static bool removeSaveData();//删除
    static bool searchSaveData(QList<SaveData> &data);//搜索

    //static bool isExistSaveData(const QString& accountNum);
    //static bool updateSaveData(const Account& account);//更新
    //static QStringList searchByBookName(const Account& account);//查找
};

#endif // SaveDatabase_H
