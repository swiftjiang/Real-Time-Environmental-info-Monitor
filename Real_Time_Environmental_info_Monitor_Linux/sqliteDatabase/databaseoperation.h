#ifndef DATABASEOPERATION_H
#define DATABASEOPERATION_H

#include "accountdatabase.h"
#include "savedatabase.h"

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVariant>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

/* sql语句模版
判断数据库中是否存在某个表： SELECT 1 FROM sqlite_master where type = 'table' and  name = 'book';
判断表中是否存在某字段：SELECT 1 FROM sqlite_master where type = 'table' and name= 'book' and sql like '%idtest%';
建表语句：CREATE TABLE book(id VARCHAR(20) PRIMARY KEY  , name VARCHAR(100), info VARCHAR(100));
添加字段：ALTER TABLE book ADD descinfo VARCHAR(100);
创建索引：CREATE INDEX book_index1 on book(id);
添加：INSERT INTO book(id, name, info) VALUES('1111', 'Qt编程', '这是一本好书');
删除：DELETE FROM book  WHERE id = '1111';
更新：UPDATE book SET name = 'test' WHERE id = '1111';
精确搜索：SELECT * FROM book WHERE id = '111';
模糊搜索：SELECT * FROM book WHERE name like '%:strBookName%' ESCAPE '!';
*/

class DatabaseOperation : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseOperation(QObject *parent = 0);
    ~DatabaseOperation();

signals:

public slots:

public:

    static bool createDataFile(const QString& strFileName);//创建数据库文件
    static bool openDataBase(const QString& strFileName);//打开数据库文件(Sqlite,*.db文件)
    static void closeDataBase(); //关闭数据库
    static bool isExistTable(const QString& strTableName);//判断数据库中是否存在该表
    static bool isExistField(const QString& strTableName, const QString& strFieldName);//判断表中是否含有某字段(列)
    static void initDatabase();

public:
    static QSqlDatabase myDatabase; //数据库
};

#endif // DATABASEOPERATION_H
