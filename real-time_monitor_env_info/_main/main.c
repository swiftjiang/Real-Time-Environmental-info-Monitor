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

//待发送字节描述
unsigned char sendData[11];
/*************************
sendData[0]				前导字节
sendData[1]				主设备号MSB
sendData[2]				主设备号LSB
sendData[3]				次设备号MSB
sendData[4]				次设备号LSB
sendData[5]				火焰
sendData[6]				人体
sendData[7]				温度MSB
sendData[8]				温度LSB
sendData[9]				烟雾
sendData[10]			检验和	
*************************/

void init_byte()
{
	sendData[0]  =00;				//前导字节
	
	sendData[1]  =MAJORNUM;				//主设备号MSB
	sendData[2]  =MINORNUM;				//主设备号LSB
	
	sendData[3]  =00;				//次设备号MSB
	sendData[4]  =00;				//次设备号LSB
	
	sendData[5]  =00;				//火焰
	sendData[6]  =00;				//人体
	sendData[7]  =00;				//温度MSB
	sendData[8]  =00;				//温度LSB
	sendData[9]  =00;				//烟雾
	
	sendData[10] =sendData[1] | sendData[2];			//检验和
}

int main()
{
	int i;
	
	/*初始化LCD1602*/
	LCD_Init(); 
  LCD_Clear();//清屏

	InitUart();//初始化串口
	for(i=0;i<100;i++)
	Delay(200);
	SendString("Welcome to using Real-Time env info monitor !\n\n");
	
	init_byte();//初始化数据
	
	fire=1;
	human=1;
	
	
	
	while(1)
	{
		/*获取火焰数据，低电平触发火焰*/
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
		/*获取人体数据，高电平触发*/
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
		
		/*获取温度*/
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
		
		//校验和
		sendData[10]=sendData[0] | sendData[1] | sendData[2] | sendData[3] | sendData[4] | sendData[5] | sendData[6] | sendData[7] | sendData[8] | sendData[9];
		//发送数据
		//SendString(sendData);
		for(i=0;i<11;i++)
		SendData(sendData[i]);
		
		for(i=0;i<200;i++)
		Delay(200);
		LCD_Clear();//清屏
		
	}
	
	return 0;
}