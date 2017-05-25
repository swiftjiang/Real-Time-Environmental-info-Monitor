#include "keyboard.h"
#include "ui_keyboard.h"

QString KeyBoard::mystr;

KeyBoard::KeyBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize( 800,480);
}

KeyBoard::~KeyBoard()
{
    delete ui;
}


void KeyBoard::resetShiftFlag()
{
    shiftFlag=false;
}

QString KeyBoard::getKeyboardInput()
{
    return mystr;
}

void KeyBoard::on_k0_clicked()
{
    resetShiftFlag();
    inputStr+="0";
    ui->input->setText(inputStr);
}

void KeyBoard::on_k1_clicked()
{
    resetShiftFlag();
    inputStr+="1";
    ui->input->setText(inputStr);
}

void KeyBoard::on_k2_clicked()
{
    resetShiftFlag();
    inputStr+="2";
    ui->input->setText(inputStr);
}

void KeyBoard::on_k3_clicked()
{
    resetShiftFlag();
    inputStr+="3";
    ui->input->setText(inputStr);
}

void KeyBoard::on_k4_clicked()
{
    resetShiftFlag();
    inputStr+="4";
    ui->input->setText(inputStr);
}

void KeyBoard::on_k5_clicked()
{
    resetShiftFlag();
    inputStr+="5";
    ui->input->setText(inputStr);
}

void KeyBoard::on_k6_clicked()
{
    resetShiftFlag();
    inputStr+="6";
    ui->input->setText(inputStr);
}

void KeyBoard::on_k7_clicked()
{
    resetShiftFlag();
    inputStr+="7";
    ui->input->setText(inputStr);
}

void KeyBoard::on_k8_clicked()
{
    resetShiftFlag();
    inputStr+="8";
    ui->input->setText(inputStr);
}

void KeyBoard::on_k9_clicked()
{
    resetShiftFlag();
    inputStr+="9";
    ui->input->setText(inputStr);
}

void KeyBoard::on_shift_clicked()
{
    shiftFlag=!shiftFlag;
}

void KeyBoard::on_clear_clicked()
{
    inputStr="";
    ui->input->setText(inputStr);
}

void KeyBoard::on_dot_clicked()
{
    resetShiftFlag();
    inputStr+=".";
    ui->input->setText(inputStr);
}

void KeyBoard::on_minus_clicked()
{
    resetShiftFlag();
    inputStr+="-";
    ui->input->setText(inputStr);
}

void KeyBoard::on_a_clicked()
{
    if(shiftFlag)
    {
        inputStr+="A";
    }
    else
    {
        inputStr+="a";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_b_clicked()
{
    if(shiftFlag)
    {
        inputStr+="B";
    }
    else
    {
        inputStr+="b";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_c_clicked()
{
    if(shiftFlag)
    {
        inputStr+="C";
    }
    else
    {
        inputStr+="c";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_d_clicked()
{
    if(shiftFlag)
    {
        inputStr+="D";
    }
    else
    {
        inputStr+="d";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_e_clicked()
{
    if(shiftFlag)
    {
        inputStr+="E";
    }
    else
    {
        inputStr+="e";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_f_clicked()
{
    if(shiftFlag)
    {
        inputStr+="F";
    }
    else
    {
        inputStr+="f";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_g_clicked()
{
    if(shiftFlag)
    {
        inputStr+="G";
    }
    else
    {
        inputStr+="g";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_h_clicked()
{
    if(shiftFlag)
    {
        inputStr+="H";
    }
    else
    {
        inputStr+="h";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_i_clicked()
{
    if(shiftFlag)
    {
        inputStr+="I";
    }
    else
    {
        inputStr+="i";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_j_clicked()
{
    if(shiftFlag)
    {
        inputStr+="J";
    }
    else
    {
        inputStr+="j";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_k_clicked()
{
    if(shiftFlag)
    {
        inputStr+="K";
    }
    else
    {
        inputStr+="k";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_l_clicked()
{
    if(shiftFlag)
    {
        inputStr+="L";
    }
    else
    {
        inputStr+="l";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_m_clicked()
{
    if(shiftFlag)
    {
        inputStr+="M";
    }
    else
    {
        inputStr+="m";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_n_clicked()
{
    if(shiftFlag)
    {
        inputStr+="N";
    }
    else
    {
        inputStr+="n";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_o_clicked()
{
    if(shiftFlag)
    {
        inputStr+="O";
    }
    else
    {
        inputStr+="o";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_p_clicked()
{
    if(shiftFlag)
    {
        inputStr+="P";
    }
    else
    {
        inputStr+="p";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_q_clicked()
{
    if(shiftFlag)
    {
        inputStr+="Q";
    }
    else
    {
        inputStr+="q";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_r_clicked()
{
    if(shiftFlag)
    {
        inputStr+="R";
    }
    else
    {
        inputStr+="r";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_s_clicked()
{
    if(shiftFlag)
    {
        inputStr+="S";
    }
    else
    {
        inputStr+="s";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_t_clicked()
{
    if(shiftFlag)
    {
        inputStr+="T";
    }
    else
    {
        inputStr+="t";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_u_clicked()
{
    if(shiftFlag)
    {
        inputStr+="U";
    }
    else
    {
        inputStr+="u";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_v_clicked()
{
    if(shiftFlag)
    {
        inputStr+="V";
    }
    else
    {
        inputStr+="v";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_w_clicked()
{
    if(shiftFlag)
    {
        inputStr+="W";
    }
    else
    {
        inputStr+="w";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_x_clicked()
{
    if(shiftFlag)
    {
        inputStr+="Xx";
    }
    else
    {
        inputStr+="x";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_y_clicked()
{
    if(shiftFlag)
    {
        inputStr+="Y";
    }
    else
    {
        inputStr+="y";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::on_z_clicked()
{
    if(shiftFlag)
    {
        inputStr+="Z";
    }
    else
    {
        inputStr+="z";
    }
    resetShiftFlag();
    ui->input->setText(inputStr);
}

void KeyBoard::keyboard_slot()
{
    inputStr="";
    shiftFlag=false;
    this->show();
    //raise();
}

void KeyBoard::on_enter_clicked()
{
    this->hide();
    setData_signal(inputStr);

    if(this->isActiveWindow())
        qDebug()<<"after signal";
    inputStr="";
    ui->input->setText(inputStr);
}

void KeyBoard::on_cancle_clicked()
{
    this->hide();
}
