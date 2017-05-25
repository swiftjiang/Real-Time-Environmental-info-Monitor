#include "maindlg.h"
#include "ui_maindlg.h"

MainDlg::MainDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDlg)
{
    ui->setupUi(this);
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize( 800,480);

    /****************************///时间计时器
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showRealTime()));
    timer->start(1000);

    //锁屏状态初始化
    screenLockFlag=false;
    //输入空间初始化
    myLineEdit=NULL;
    //状态标记初始化
    ui->state_major->setText("Major Number");
    ui->state_minor->setText("Minor Number");
    ui->state_fire->setText("State Fire");
    ui->state_gas->setText("State Gas");
    ui->state_huamn->setText("State Human");
    ui->state_temp->setText("Temperature");
    //输入控件安装过滤器
    ui->major->installEventFilter(this);
    ui->minor->installEventFilter(this);

    //查询表格设置
    ui->checkList->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑
    ui->checkList->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->checkList->setColumnCount(7);//设置列数
    ui->checkList->setRowCount(500);//设置行数
    ui->checkList->setHorizontalHeaderLabels(QStringList() << tr("major")<<tr("minor")<<tr("fire")
                                             <<tr("man")<<tr("tempera")<<tr("gas")<<tr("datetime"));//设置表头
    //设置列大小
    ui->checkList->resizeRowsToContents();
    ui->checkList->resizeColumnsToContents();
    //int width=ui->checkList->get
    ui->checkList->setColumnWidth(6,135);
    ui->next_list->setEnabled(0);
    //next_list=0;

    //状态表刷新通信连接
    connect(&myuart,SIGNAL(showState(int,int,int,int,int,double)),this,SLOT(showState(int,int,int,int,int,double)));

    /****************************************************/
    /****************************************************/
    /********************应该删除*************************/
    //打开串口
//    myuart.setPortName("");
//    myuart.setReadTimeout(1000);
//    myuart.setPortProperties();
//    myuart.openPort();
//    myuart.connectPort();
    /***************************************************/
}

MainDlg::~MainDlg()
{
    delete ui;
}

bool MainDlg::eventFilter(QObject *watched, QEvent *event)
{
    if((ui->major == watched || ui->minor == watched) && event->type() == QEvent::MouseButtonPress)
    {
        myLineEdit=(QLineEdit*)watched;
        keyboard_signal();
    }
    return QObject::eventFilter(watched,event);
}

void MainDlg::showList()
{
    QListIterator<SaveData> it(data);
    sumSize=data.size();
    qDebug()<<"size is *********"<<sumSize;

    ui->checkList->clearContents();
    if(sumSize>500)
    {
        ui->next_list->setEnabled(1);
    }
    else
    {
        ui->next_list->setEnabled(0);
        ui->checkList->setRowCount(sumSize);//设置行数
    }

    int row=0;
    while(it.hasNext() && row < 500 )
    {
        SaveData mydata=it.next();

        QString ma=QString("%1").arg(mydata.majorNum);
        QString mi=QString("%1").arg(mydata.minorNum);
        QString fire=QString("%1").arg(mydata.fire);
        QString human=QString("%1").arg(mydata.human);
        QString temp=QString("%1").arg(mydata.temperature);
        QString smoke=QString("%1").arg(mydata.smoke);
        QString dtime=mydata.dateTime.toString("yyyy-MM-dd hh:mm:ss");

        QString dataStr[7]={ma,mi,fire,human,temp,smoke,dtime};
        for(int j=0;j<7;j++)
        {
            //qDebug()<<"dataStr["<<j<<"]="<<dataStr[j];
            ui->checkList->setItem(row,j,new QTableWidgetItem(dataStr[j]));
        }
        row++;
        data.removeFirst();
        //data.removeAt(4);
    }
}

void MainDlg::showRealTime()
{
    QDateTime dateTime=QDateTime::currentDateTime();
    QString date=dateTime.toString("yy-MM-dd");
    QString time=dateTime.toString("hh:mm:ss");
    ui->time->setAlignment(Qt::AlignCenter);
    ui->date->setAlignment(Qt::AlignCenter);

    ui->time->setFont(QFont("Timers" , 20 ,  QFont::Bold));
    ui->date->setFont(QFont("Timers" , 20 ,  QFont::Bold));

    ui->time->setText(time);
    ui->date->setText(date);
}

void MainDlg::showState(int major, int minor, int fire, int human, int gas, double temp)
{
//    if((fire || human || gas))
//    {
        ui->state_major->setText(QString("%1").arg(major));
        ui->state_minor->setText(QString("%1").arg(minor));
        ui->state_fire->setText(QString("%1").arg(fire));
        ui->state_huamn->setText(QString("%1").arg(human));
        ui->state_gas->setText(QString("%1").arg(gas));
        ui->state_temp->setText(QString("%1").arg(temp));
//    }
//    else
//    {
//        ui->state_major->setText("Major Number");
//        ui->state_minor->setText("Minor Number");
//        ui->state_fire->setText("State Fire");
//        ui->state_gas->setText("State Gas");
//        ui->state_huamn->setText("State Human");
//        ui->state_temp->setText("Temperature");
//    }
}

void MainDlg::getData_slot(QString &str)
{
    if(myLineEdit!=NULL)
    {
        myLineEdit->setText(str);
        myLineEdit=NULL;
    }
}

void MainDlg::on_warningcfg_clicked()
{
    this->hide();
    this->warningcfg();
}

void MainDlg::on_syscfg_clicked()
{
    this->hide();
    this->syscfg();
}

void MainDlg::on_cloudcfg_clicked()
{
    this->hide();
    this->cloudcfg();
}

void MainDlg::on_logout_clicked()
{
    this->close();
    this->logout();
}

void MainDlg::on_exit_clicked()
{
    exit(0);
}

void MainDlg::on_start_clicked()
{
    //打开串口
    myuart.setPortName("");
    myuart.setReadTimeout(1000);
    myuart.setPortProperties();
    myuart.openPort();
    myuart.connectPort();

}

void MainDlg::on_end_clicked()
{
    myuart.disconnectPort();
    ui->state_major->setText("Major Number");
    ui->state_minor->setText("Minor Number");
    ui->state_fire->setText("State Fire");
    ui->state_gas->setText("State Gas");
    ui->state_huamn->setText("State Human");
    ui->state_temp->setText("Temperature");
}

void MainDlg::on_manageaccount_clicked()
{
    //跳转到管理帐户页面
    hide();
    manageaccount();
}

void MainDlg::on_screenLock_clicked()
{
    screenLockFlag=!screenLockFlag;

    ui->syscfg->setEnabled(!screenLockFlag);
    ui->cloudcfg->setEnabled(!screenLockFlag);
    ui->warningcfg->setEnabled(!screenLockFlag);
    ui->manageaccount->setEnabled(!screenLockFlag);
    ui->logout->setEnabled(!screenLockFlag);
    ui->exit->setEnabled(!screenLockFlag);

    ui->major->setEnabled(!screenLockFlag);
    ui->minor->setEnabled(!screenLockFlag);
    ui->clean->setEnabled(!screenLockFlag);
    ui->check->setEnabled(!screenLockFlag);
    ui->checkList->setEnabled(!screenLockFlag);
    ui->next_list->setEnabled(0);
    ui->major->setText("");
    ui->minor->setText("");

    ui->start->setEnabled(!screenLockFlag);
    ui->end->setEnabled(!screenLockFlag);


    ui->screenLock->setFocus();
}

void MainDlg::on_clean_clicked()
{
    ui->major->setText("");
    ui->minor->setText("");
}

void MainDlg::on_check_clicked()
{
    QString major=ui->major->text();
    QString minor=ui->minor->text();

    data.clear();
    SaveDatabase::setSaveData(major.toInt(),minor.toInt(),0,0,0,0);
    SaveDatabase::searchSaveData(data);
    //用checkList将data中的数据显示出来
    showList();

//    ui->checkList->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑
//    ui->checkList->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
//    ui->checkList->setColumnCount(7);//设置列数
//    ui->checkList->setHorizontalHeaderLabels(QStringList() << tr("major")<<tr("minor")<<tr("fire")
//                                             <<tr("human")<<tr("temperature")<<tr("smoke")<<tr("datetime"));//设置表头

//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑
//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
//    ui->tableWidget->setRowCount(2);//设置行数
//    ui->tableWidget->setColumnCount(2);//设置列数
//    ui->tableWidget->setItem(0,0,new QTableWidgetItem("1"));//设置单元格数据



}

void MainDlg::on_next_list_clicked()
{
    showList();
//    data.
//    next_list+=500;
//    showNextList();
//    if(next_list>sumSize)
//    {
//        ui->next_list->setEnabled(0);
//        next_list=0;
//    }
}
