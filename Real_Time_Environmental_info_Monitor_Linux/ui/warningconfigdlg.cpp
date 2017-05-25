#include "warningconfigdlg.h"
#include "ui_warningconfigdlg.h"

WarningConfigDlg::WarningConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningConfigDlg)
{
    ui->setupUi(this);
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize( 800,480);
}

WarningConfigDlg::~WarningConfigDlg()
{
    delete ui;
}

void WarningConfigDlg::on_save_clicked()
{
    this->hide();
    this->save();
}

void WarningConfigDlg::on_cancle_clicked()
{
    this->cancle();
    this->hide();
}

void WarningConfigDlg::savedata()
{
    ;
}
