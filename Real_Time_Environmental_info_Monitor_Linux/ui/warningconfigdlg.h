#ifndef WARNINGCONFIGDLG_H
#define WARNINGCONFIGDLG_H

#include <QDialog>

namespace Ui {
class WarningConfigDlg;
}

class WarningConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WarningConfigDlg(QWidget *parent = 0);
    ~WarningConfigDlg();

signals:
    void save();
    void cancle();

private slots:
    void on_save_clicked();

    void on_cancle_clicked();

    void savedata();

private:
    Ui::WarningConfigDlg *ui;
};

#endif // WARNINGCONFIGDLG_H
