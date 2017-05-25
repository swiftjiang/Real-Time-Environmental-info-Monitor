#ifndef SYSTEMCONFIGDLG_H
#define SYSTEMCONFIGDLG_H

#include <QDialog>
#include <QLineEdit>
#include "sqliteDatabase/databaseoperation.h"

namespace Ui {
class SystemConfigDlg;
}

class SystemConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SystemConfigDlg(QWidget *parent = 0);
    ~SystemConfigDlg();
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void save();
    void cancle();

    void keyboard_signal();


private slots:
    void getData_slot(QString &str);

    void on_save_clicked();

    void on_cancle_clicked();

    void savedata();



private:
    Ui::SystemConfigDlg *ui;
    QLineEdit *myLineEdit;
};

#endif // SYSTEMCONFIGDLG_H
