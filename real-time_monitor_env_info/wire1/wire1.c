
#include"wire1.h"


void Delay4us()	//延时4us
{
	;
}
void Delay(unsigned char j)		//一个循环15us
{
	unsigned char i;
	while(j--)
	{
		i = 5;
		while (--i);
	}
}
bit d18b20_qs()	//18b20 起始
{
	bit dat;
	DQ = 1;	//DQ复位
	Delay4us();
	DQ = 0;	//拉低总线
	Delay(35);	//这里延时大概 525us
	DQ = 1;	//拉高总线
	Delay(2); 	//这里延时大概 30us
	dat = DQ;	//读取返回值（0：有18b20存在 1：是没有）
	Delay(2);
	return dat;	//返回数值
}

void d18b20_x(unsigned char dat) //写 8 位 数 据
{
	unsigned char i;
	for(i=0;i<8;i++)	//8位计数器
	{
		DQ = 0;	//拉低总线
		DQ = dat & 0x01;	//取最低位赋值给总线
		Delay(3);	//延时45us
		DQ = 1;	//拉过总线准备写下一个数据（或者总线复位）
		dat >>= 1;	//数据右移一位
	}
}
unsigned char d18b20_d()	//读 8 位 数 据
{
	unsigned char i,dat=0;
	for(i=0;i<8;i++)	//8位计数器
	{
		DQ = 0;	//拉低总线
		dat >>= 1;	//数据右移一位
		DQ = 1;	//拉过总线（准备读取数据）
		if(DQ)	//判断是否是 1 如果是就把数据赋值给变量的高位
			dat |= 0x80;
		Delay(4);
	}
	return dat; //返回读取到数据数据
}


unsigned int wd()	//读取温度函数
{
	unsigned char i = 0;	//低8位数据
	unsigned char j = 0;	//高8位数据
	unsigned int k = 0;	//无符号16整形用来存储读回来的 16位温度数据（j和i组合后的数据）

	d18b20_qs();	//初始化
	d18b20_x(0xCC);	//跳过序列号的操作(因为18b20在总线上可以挂很多个，这个序列号和网卡MAC地址类似)
	d18b20_x(0x44);	//开启温度转换
	Delay(200);			//开启温度转换需要时间这里延时一下
	
	d18b20_qs();	//初始化
	d18b20_x(0xCC);	//跳过序列号的操作(因为18b20在总线上可以挂很多个，这个序列号和网卡MAC地址类似)
	d18b20_x(0xBE);	//读取温度寄存器等（共可读9个寄存器） 前两个就是温度
	i = d18b20_d();	//读取低8位
	j = d18b20_d();	//读取高8位

	k = j;		
	k <<= 8;
	k = k |i;
	return k;	//返回读取到的16位数据
}
