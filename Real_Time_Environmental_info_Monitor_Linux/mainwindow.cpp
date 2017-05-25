#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize( 800,480);

    ui->account->installEventFilter(this);
    ui->password->installEventFilter(this);

    myLineEdit=NULL;

    //connect(ui->account,SIGNAL(LineEditClicked()),this,SLOT(slotKeyboard()));

    /******************/
    ui->account->setText("123456");
    ui->password->setText("123456");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::check_id()
{
    //return 1;
    qDebug()<<"get info from ui"<<ui->account->text()<<","<<ui->password->text();
    if(ui->account->text().isEmpty() || ui->password->text().isEmpty())
    {
        return 0;
    }
    DatabaseOperation::initDatabase();
    AccountDatabase::setAccount(ui->account->text(),ui->password->text());
    ;
    if(AccountDatabase::checkAccountPasswd())
    {
        return 1;
    }
    else return 0;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if((ui->account  == watched ||
        ui->password == watched) && event->type() == QEvent::MouseButtonPress)
    {
        myLineEdit=(QLineEdit*)watched;
        keyboard_signal();
    }
    return QObject::eventFilter(watched,event);
}

void MainWindow::getData_slot(QString &str)
{

    if(myLineEdit!=NULL)
    {
        myLineEdit->setText(str);
        myLineEdit=NULL;
    }
}


void MainWindow::on_login_clicked()
{
    if(check_id())
    {
        this->close();
        this->login();
    }
    else
        QMessageBox::warning(this,NULL,"account or password is wrong !",0,0);
}

void MainWindow::on_exit_clicked()
{
    this->close();
}

