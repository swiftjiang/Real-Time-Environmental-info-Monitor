#include "systemconfigdlg.h"
#include "ui_systemconfigdlg.h"

SystemConfigDlg::SystemConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemConfigDlg)
{
    ui->setupUi(this);
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize( 800,480);

    myLineEdit=NULL;
    ui->uart_name->installEventFilter(this);
    ui->uart_time->installEventFilter(this);
}

SystemConfigDlg::~SystemConfigDlg()
{
    delete ui;
}

bool SystemConfigDlg::eventFilter(QObject *watched, QEvent *event)
{
    if((ui->uart_name == watched || ui->uart_time == watched) && event->type() == QEvent::MouseButtonPress)
    {
        myLineEdit=(QLineEdit*)watched;
        keyboard_signal();
    }
    return QObject::eventFilter(watched,event);
}

void SystemConfigDlg::getData_slot(QString &str)
{
    if(myLineEdit!=NULL)
    {
        myLineEdit->setText(str);
        myLineEdit=NULL;
    }
}

void SystemConfigDlg::on_save_clicked()
{
    this->hide();
    this->save();
}

void SystemConfigDlg::on_cancle_clicked()
{
    this->cancle();
    this->hide();
}

void SystemConfigDlg::savedata()
{
    ;
}


