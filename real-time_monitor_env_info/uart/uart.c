#include"uart.h"

bit busy;
BYTE RxData;

/*----------------------------
UART interrupt service routine
----------------------------*/
void Uart_Isr() interrupt 4 using 1
{
    if (RI)
    {
        RI = 0;             //Clear receive interrupt flag
        RxData = SBUF;          //P0 show UART data
		//SendData(RxData);				//�����յ�������
    }
    if (TI)
    {
        TI = 0;             //Clear transmit interrupt flag
        busy = 0;           //Clear transmit busy flag
    }
}
/*----------------------------
Init UART
----------------------------*/
void InitUart()
{
	SCON = 0x50;            //8-bit variable UART,���ƼĴ�����01������ʽ��1��������1������ܣ�1���͵ھ�λ��1���յھ�λ������/�����ж�
    TMOD = 0x20;            //Set Timer1 as 8-bit auto reload mode
    TH1 = TL1 = -(FOSC/12/32/BAUD); //Set auto-reload vaule
    TR1 = 1;                //Timer1 start run
    ES = 1;                 //Enable UART interrupt
    EA = 1;                 //Open master interrupt switch
}

/*----------------------------
Send a byte data to UART
Input: dat (data to be sent)
Output:None
----------------------------*/
void SendData(BYTE dat)
{
    while (busy);           //Wait for the completion of the previous data is sent

    busy = 1;
    SBUF = dat;             //Send data to UART buffer
}

/*----------------------------
Send a string to UART
Input: s (address of string)
Output:None
----------------------------*/
void SendString(char *s)
{
    while (*s)              //Check the end of the string
    {
        SendData(*s++);     //Send current char and increment string ptr
    }
}

