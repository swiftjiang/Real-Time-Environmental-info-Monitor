#include "quart.h"

#include<QString>
#include<QDebug>



quart::quart(QObject *parent) : QObject(parent)
{
    readTimer = new QTimer(this);

}

quart::~quart()
{
    //client.Close();
}

int quart::setPortName(QString portName)
{
    QString port="/dev/ttyS2";
    if(!portName.isEmpty())
        port=portName;

    //define uart port by the way of polling
    myCom = new Posix_QextSerialPort(port,QextSerialBase::Polling);
    return 0;
}

int quart::setReadTimeout(int timeout)
{
    readTimer->start(timeout);//control read data time
    return 0;
}

int quart::setPortProperties()
{
    //config uart port
    myCom->setBaudRate(BAUD9600);          //波特率设置，我们设置为9600
    myCom->setDataBits(DATA_8);            //数据位设置，我们设置为8位数据位
    myCom->setParity(PAR_NONE);           //奇偶校验设置，我们设置为无校验
    myCom->setStopBits(STOP_1);            //停止位设置，我们设置为1位停止位
    myCom->setFlowControl(FLOW_OFF);      //控制流

    long timeout=100;//don't too big ,100 is best
    myCom->setTimeout(timeout);              //设置时间间隔

    return 0;
}

int quart::openPort()
{
    //uart port mode
    myCom ->open(QIODevice::ReadWrite);
    return 0;
}

int quart::connectPort()
{
    connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));  //Polling模式定时器触发timeout（）信号
    /**************socket*************/
    //QString ip="118.89.101.111";
    //quint16     port=20006;
    //client.ConnectToServer( ip, port );
    //client.waitForConnected( -1 );

    return 0;
}

int quart::disconnectPort()
{
    disconnect(readTimer,0,this,0);
    return 0;
}

void quart::readMyCom()
{
//    qDebug()<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
//    SaveDatabase::setSaveData(1,1,1,1,1.0,1);
//    SaveDatabase::addSaveData();




    QByteArray temp = myCom->readAll();    //返回读取的字节

    int majo;
    int mino;
    int fire;
    int human;
    double temperature;
    int smoke;

    //int byteLen = myCom->bytesAvailable(); //返回串口缓冲区字节数
    if(!temp.isEmpty())
    {
        majo=(int)temp[1]*256+(int)temp[2];
        mino=(int)temp[3]*256+(int)temp[4];
        if(temp[5])
        {
            fire=1;
            qDebug()<<"Get fire";
        }
        else
        {
            fire=0;
            qDebug()<<"No fire";
        }

        if(temp[6])
        {
            human=1;
            qDebug()<<"Have human";
        }
        else
        {
            human=0;
            qDebug()<<"No people";
        }

        //qDebug()<<"temp 7 8 "<<(int)temp[7]<<"  "<<(int)temp[8];
        temperature=((double)((int)temp[7]*256+(int)temp[8]))*0.0625;
        qDebug()<<"temperature is "<<temperature;

        if(temp[9])
        {
            smoke=1;
            qDebug()<<"Get smoke";
        }
        else
        {
            smoke=0;
            qDebug()<<"No smoke";
        }

        showState(majo,mino, fire,human,smoke,temperature);//通知主界面更改状态


        /*********************************database**********************/
        //DatabaseOperation::initDatabase();
        SaveDatabase::setSaveData(majo,mino,fire,human,temperature,smoke);
        SaveDatabase::addSaveData();



        /*********************************tcp通信***********************/

//        qDebug()<<"--------------Socket--------------";


//        if( !client.WriteData(temp) )
//        {
//            qDebug()<<"WriteData failed !\n";
//        }
//        client.waitForConnected( -1 );

//        qDebug()<<"----------------------------------";
    }

}
