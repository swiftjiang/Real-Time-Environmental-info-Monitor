#ifndef CLOUDCONFIGDLG_H
#define CLOUDCONFIGDLG_H

#include <QDialog>

namespace Ui {
class CloudConfigDlg;
}

class CloudConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CloudConfigDlg(QWidget *parent = 0);
    ~CloudConfigDlg();

signals:
    void save();
    void cancle();

private slots:


    void on_save_clicked();

    void on_cancle_clicked();

    void savedata();

private:
    Ui::CloudConfigDlg *ui;
};

#endif // CLOUDCONFIGDLG_H
