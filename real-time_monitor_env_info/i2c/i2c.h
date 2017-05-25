/*i2c.h文件 */
#ifndef __I2C_H_
#define __I2C_H_


sbit SCL = P2^1;
sbit SDA = P2^0;



void start_i2c();	//启动I2C总线：SCL高电平期间，SDA由高变低
void stop_i2c();	//停止I2C总线：SCL高电平期间，SDA由低变高
void send_i2c(unsigned char c);	//主机发送一个字节,先发送最高位
unsigned char receive_i2c();	//主机接收一个字节,先接收最高位
void master_ack(bit ack);	//主机非应答信号(填参数0)或应答信号(填参数1)
void slave_ack();	//等待从机应答信号


 
#endif 