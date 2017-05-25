/*i2c.h�ļ� */
#ifndef __I2C_H_
#define __I2C_H_


sbit SCL = P2^1;
sbit SDA = P2^0;



void start_i2c();	//����I2C���ߣ�SCL�ߵ�ƽ�ڼ䣬SDA�ɸ߱��
void stop_i2c();	//ֹͣI2C���ߣ�SCL�ߵ�ƽ�ڼ䣬SDA�ɵͱ��
void send_i2c(unsigned char c);	//��������һ���ֽ�,�ȷ������λ
unsigned char receive_i2c();	//��������һ���ֽ�,�Ƚ������λ
void master_ack(bit ack);	//������Ӧ���ź�(�����0)��Ӧ���ź�(�����1)
void slave_ack();	//�ȴ��ӻ�Ӧ���ź�


 
#endif 