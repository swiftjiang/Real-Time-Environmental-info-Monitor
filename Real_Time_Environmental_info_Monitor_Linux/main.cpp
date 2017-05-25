#include "uimanage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    /************************/
//    DatabaseOperation::initDatabase();
//    DatabaseOperation::closeDataBase();

//    QList<Account> ac;
//    AccountDatabase ad;
//    ad.getAllAccount(ac);
//    QListIterator<Account> ret(ac);
//    while(ret.hasNext())
//    {
//        Account temp=ret.next();
//        qDebug()<<temp.num<<","<<temp.dateTime.toString("yy-MM-dd hh:mm:ss");
//    }


    /************************/


    UIManage uimanage;
    uimanage.mainwinshow();

    return a.exec();
}
