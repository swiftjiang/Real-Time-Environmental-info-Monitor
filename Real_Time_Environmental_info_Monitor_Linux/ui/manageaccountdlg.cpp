#include "manageaccountdlg.h"
#include "ui_manageaccountdlg.h"

ManageAccountDlg::ManageAccountDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageAccountDlg)
{
    ui->setupUi(this);
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize( 800,480);

    myLineEdit=NULL;
    ui->add_account->installEventFilter(this);
    ui->add_passwd->installEventFilter(this);
}

ManageAccountDlg::~ManageAccountDlg()
{
    delete ui;
}

bool ManageAccountDlg::eventFilter(QObject *watched, QEvent *event)
{
    if((ui->add_account == watched || ui->add_passwd == watched) && event->type() == QEvent::MouseButtonPress)
    {
        myLineEdit=(QLineEdit*)watched;
        keyboard_signal();
    }
    return QObject::eventFilter(watched,event);
}

void ManageAccountDlg::getData_slot(QString &str)
{
    if(myLineEdit!=NULL)
    {
        myLineEdit->setText(str);
        myLineEdit=NULL;
    }
}

void ManageAccountDlg::on_cancle_clicked()
{
    hide();
    cancle();
}

void ManageAccountDlg::on_add_clicked()
{
    AccountDatabase::setAccount(ui->add_account->text(),ui->add_passwd->text());
    AccountDatabase::addAccount();
}

void ManageAccountDlg::on_clean_clicked()
{
    ui->add_account->setText("");
    ui->add_passwd->setText("");
}
