#include<reg52.h>
#include<intrins.h>

sbit DQ = P1^2;	//�������ߵ�I/O�ܽ�

void Delay4us();	//��ʱ4us

void Delay(unsigned char j);		//һ��ѭ��15us

bit d18b20_qs();	//18b20 ��ʼ

void d18b20_x(unsigned char dat); //д 8 λ �� ��

unsigned char d18b20_d();	//�� 8 λ �� ��

unsigned int wd();	//��ȡ�¶Ⱥ���
