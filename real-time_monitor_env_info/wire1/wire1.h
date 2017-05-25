#include<reg52.h>
#include<intrins.h>

sbit DQ = P1^2;	//定义总线的I/O管脚

void Delay4us();	//延时4us

void Delay(unsigned char j);		//一个循环15us

bit d18b20_qs();	//18b20 起始

void d18b20_x(unsigned char dat); //写 8 位 数 据

unsigned char d18b20_d();	//读 8 位 数 据

unsigned int wd();	//读取温度函数
