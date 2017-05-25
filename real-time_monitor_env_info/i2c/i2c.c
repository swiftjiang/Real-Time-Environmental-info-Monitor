/* i2c.c文件 */
#include<reg51.h>
#include<intrins.h>
#include"i2c.h"

#define nop() _nop_()

void start_i2c()	//启动I2C总线:SCL高电平期间，SDA由高变低
{
	SDA=1;         
	SCL=1;
	nop();nop();nop();nop();    
	SDA=0;       
	SCL=0;
}

void stop_i2c()	//停止I2C总线，SCL高电平期间，SDA由低变高
{
	SDA=0;          
	SCL=1;      
	nop();nop();nop();nop();
	SDA=1;
}

void slave_ack()	//等待从机应答信号，如果从机迟迟没有应答，则结束总线。  
{
	unsigned char i;       
	SDA = 1;	 	                    
	SCL = 1;
	i=200;       
	while(SDA&&(i--));	               
	if(!SDA)
		SCL = 0; 
	else
		stop_i2c();       			
}

void send_i2c(unsigned char c) 	//主机发送一个字节,先发送最高位
{
	unsigned char  BitCnt;
	for(BitCnt=8;BitCnt>0;BitCnt--)  
	{
		c<<=1;
		SDA=CY;
		SCL=1;               
		nop();nop();nop();nop();        
		SCL=0; 
	}
}

unsigned char receive_i2c()	//主机接收一个字节,先接收最高位
{
	unsigned char  retc=0,BitCnt;   
	SDA=1;
	for(BitCnt=8;BitCnt>0;BitCnt--)
	{           
		retc<<=1;
		SCL=1;
		nop();nop();nop();nop();
		retc|=SDA;
		SCL=0;		 
	}   
	return retc;
}

void master_ack(bit ack)	//主机非应答信号(填参数0)或应答信号(填参数1)
{  
	SDA=!ack;     
	SCL=1;
	nop();nop();nop();nop();  
	SCL=0;    
}
