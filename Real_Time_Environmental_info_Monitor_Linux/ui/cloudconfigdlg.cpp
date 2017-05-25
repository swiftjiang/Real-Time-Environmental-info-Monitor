#include "cloudconfigdlg.h"
#include "ui_cloudconfigdlg.h"

CloudConfigDlg::CloudConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CloudConfigDlg)
{
    ui->setupUi(this);
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize( 800,480);

}

CloudConfigDlg::~CloudConfigDlg()
{
    delete ui;
}



void CloudConfigDlg::on_save_clicked()
{
    this->hide();
    this->save();
}

void CloudConfigDlg::on_cancle_clicked()
{
    this->hide();
    this->cancle();
}

void CloudConfigDlg::savedata()
{
    ;
}
