#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>

#include <sqliteDatabase/databaseoperation.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int check_id();
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void login();
    void exit();
    void keyboard_signal();


private slots:
    void getData_slot(QString &str);

    void on_login_clicked();

    void on_exit_clicked();


private:
    Ui::MainWindow *ui;
    QLineEdit *myLineEdit;//先初始化为空指针，作为接收数据时slot函数判断依据
};

#endif // MAINWINDOW_H
