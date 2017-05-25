#ifndef MANAGEACCOUNTDLG_H
#define MANAGEACCOUNTDLG_H

#include <QDialog>
#include <QLineEdit>
#include "sqliteDatabase/accountdatabase.h"

namespace Ui {
class ManageAccountDlg;
}

class ManageAccountDlg : public QDialog
{
    Q_OBJECT

signals:
    void cancle();
    void keyboard_signal();
public:
    explicit ManageAccountDlg(QWidget *parent = 0);
    ~ManageAccountDlg();
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void getData_slot(QString &str);

    void on_cancle_clicked();

    void on_add_clicked();

    void on_clean_clicked();

private:
    Ui::ManageAccountDlg *ui;
    QLineEdit *myLineEdit;
};

#endif // MANAGEACCOUNTDLG_H
