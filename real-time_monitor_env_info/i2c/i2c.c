/* i2c.c�ļ� */
#include<reg51.h>
#include<intrins.h>
#include"i2c.h"

#define nop() _nop_()

void start_i2c()	//����I2C����:SCL�ߵ�ƽ�ڼ䣬SDA�ɸ߱��
{
	SDA=1;         
	SCL=1;
	nop();nop();nop();nop();    
	SDA=0;       
	SCL=0;
}

void stop_i2c()	//ֹͣI2C���ߣ�SCL�ߵ�ƽ�ڼ䣬SDA�ɵͱ��
{
	SDA=0;          
	SCL=1;      
	nop();nop();nop();nop();
	SDA=1;
}

void slave_ack()	//�ȴ��ӻ�Ӧ���źţ�����ӻ��ٳ�û��Ӧ����������ߡ�  
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

void send_i2c(unsigned char c) 	//��������һ���ֽ�,�ȷ������λ
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

unsigned char receive_i2c()	//��������һ���ֽ�,�Ƚ������λ
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

void master_ack(bit ack)	//������Ӧ���ź�(�����0)��Ӧ���ź�(�����1)
{  
	SDA=!ack;     
	SCL=1;
	nop();nop();nop();nop();  
	SCL=0;    
}
