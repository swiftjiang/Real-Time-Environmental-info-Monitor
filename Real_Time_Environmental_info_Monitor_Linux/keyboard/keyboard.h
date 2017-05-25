#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>
#include <QString>
#include <QDebug>

namespace Ui {
class KeyBoard;
}

class KeyBoard : public QDialog
{
    Q_OBJECT

public:
    explicit KeyBoard(QWidget *parent = 0);
    ~KeyBoard();
    void resetShiftFlag();
    static QString getKeyboardInput();
signals:
    void setData_signal(QString &str);

private slots:
    void keyboard_slot();

    void on_k0_clicked();

    void on_k1_clicked();

    void on_k2_clicked();

    void on_k3_clicked();

    void on_k4_clicked();

    void on_k5_clicked();

    void on_k6_clicked();

    void on_k7_clicked();

    void on_k8_clicked();

    void on_k9_clicked();

    void on_shift_clicked();

    void on_clear_clicked();

    void on_dot_clicked();

    void on_minus_clicked();

    void on_a_clicked();

    void on_b_clicked();

    void on_c_clicked();

    void on_d_clicked();

    void on_e_clicked();

    void on_f_clicked();

    void on_g_clicked();

    void on_h_clicked();

    void on_i_clicked();

    void on_j_clicked();

    void on_k_clicked();

    void on_l_clicked();

    void on_m_clicked();

    void on_n_clicked();

    void on_o_clicked();

    void on_p_clicked();

    void on_q_clicked();

    void on_r_clicked();

    void on_s_clicked();

    void on_t_clicked();

    void on_u_clicked();

    void on_v_clicked();

    void on_w_clicked();

    void on_x_clicked();

    void on_y_clicked();

    void on_z_clicked();

    void on_enter_clicked();

    void on_cancle_clicked();

private:
    Ui::KeyBoard *ui;

    QString inputStr;
    bool shiftFlag;
    static QString mystr;
};

#endif // KEYBOARD_H
