#ifndef MAINDLG_H
#define MAINDLG_H

#include <QDialog>
#include <QLineEdit>
#include "uart/quart.h"

namespace Ui {
class MainDlg;
}

class MainDlg : public QDialog
{
    Q_OBJECT

public:
    explicit MainDlg(QWidget *parent = 0);
    ~MainDlg();
    bool eventFilter(QObject *watched, QEvent *event);
    void showList();

signals:
    void warningcfg();
    void syscfg();
    void cloudcfg();
    void logout();
    void manageaccount();
    void keyboard_signal();

private slots:
    void showRealTime();

    void showState(int major,int minor,int fire,int human,int gas,double temp);

    void getData_slot(QString &str);



    void on_warningcfg_clicked();

    void on_syscfg_clicked();

    void on_cloudcfg_clicked();

    void on_logout_clicked();

    void on_exit_clicked();

    void on_start_clicked();

    void on_end_clicked();

    void on_manageaccount_clicked();

    void on_screenLock_clicked();

    void on_clean_clicked();

    void on_check_clicked();


    void on_next_list_clicked();


private:
    Ui::MainDlg *ui;
    quart myuart;
    QLineEdit *myLineEdit;
    bool screenLockFlag;

    QList<SaveData> data;
    int sumSize;
    bool nextFlag;

};

#endif // MAINDLG_H
