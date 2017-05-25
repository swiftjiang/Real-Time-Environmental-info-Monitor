#include<reg52.h>
#include<intrins.h>
#include<stdio.h>
#include"../uart/uart.h"
#include"../wire1/wire1.h"
#include"../lcd1602/lcd1602.h"

#define MAJORNUM  12
#define MINORNUM  34


sbit fire = P1^0;
sbit human = P1^1;
unsigned int temp_int;
float temp_float;
char temp_str[10];

//�������ֽ�����
unsigned char sendData[11];
/*************************
sendData[0]				ǰ���ֽ�
sendData[1]				���豸��MSB
sendData[2]				���豸��LSB
sendData[3]				���豸��MSB
sendData[4]				���豸��LSB
sendData[5]				����
sendData[6]				����
sendData[7]				�¶�MSB
sendData[8]				�¶�LSB
sendData[9]				����
sendData[10]			�����	
*************************/

void init_byte()
{
	sendData[0]  =00;				//ǰ���ֽ�
	
	sendData[1]  =MAJORNUM;				//���豸��MSB
	sendData[2]  =MINORNUM;				//���豸��LSB
	
	sendData[3]  =00;				//���豸��MSB
	sendData[4]  =00;				//���豸��LSB
	
	sendData[5]  =00;				//����
	sendData[6]  =00;				//����
	sendData[7]  =00;				//�¶�MSB
	sendData[8]  =00;				//�¶�LSB
	sendData[9]  =00;				//����
	
	sendData[10] =sendData[1] | sendData[2];			//�����
}

int main()
{
	int i;
	
	/*��ʼ��LCD1602*/
	LCD_Init(); 
  LCD_Clear();//����

	InitUart();//��ʼ������
	for(i=0;i<100;i++)
	Delay(200);
	SendString("Welcome to using Real-Time env info monitor !\n\n");
	
	init_byte();//��ʼ������
	
	fire=1;
	human=1;
	
	
	
	while(1)
	{
		/*��ȡ�������ݣ��͵�ƽ��������*/
		if(fire)
		{
			//SendString("No fire");
			sendData[5]=0x00;
			LCD_Write_String(0,0,"No fire,");
		}
		else
		{
			//SendString("get fire");
			sendData[5]=0x01;
			LCD_Write_String(0,0,"Getfire,");
		}
		//for(i=0;i<150;i++)
		//Delay(200);
		/*��ȡ�������ݣ��ߵ�ƽ����*/
		if(human)
		{
			//SendString("have human");
			sendData[6]=0x01;
			LCD_Write_String(8,0," Yhuman");
		}
		else
		{
			//SendString("no human");
			sendData[6]=0x00;
			LCD_Write_String(8,0," Nhuman");
		}
		//for(i=0;i<150;i++)
		//Delay(200);
		
		/*��ȡ�¶�*/
		temp_int = wd();
		sendData[7]=(temp_int>>8);
		sendData[8]=temp_int;
		
		temp_float=(float)temp_int;
		temp_float=temp_float*0.0625;
		sprintf(temp_str, "%f", temp_float);
		//SendString(temp_str);
		
		//
		LCD_Write_String(0,1,"T=");
		LCD_Write_String(2,1,temp_str);
		//for(i=0;i<150;i++)
		//Delay(200);
		
		//У���
		sendData[10]=sendData[0] | sendData[1] | sendData[2] | sendData[3] | sendData[4] | sendData[5] | sendData[6] | sendData[7] | sendData[8] | sendData[9];
		//��������
		//SendString(sendData);
		for(i=0;i<11;i++)
		SendData(sendData[i]);
		
		for(i=0;i<200;i++)
		Delay(200);
		LCD_Clear();//����
		
	}
	
	return 0;
}