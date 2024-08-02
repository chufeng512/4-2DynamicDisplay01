#include <STC89C5xRC.H>
#include <Intrins.h>
//�����Զ������ͣ��򻯴����д
typedef unsigned char u8;
typedef unsigned int u16;

//���󣺾�̬�������ʾ,�õ��ĸ��������ʾ5
//�ֲ���Ϣ��DIG5��ӦY4,P15 P14 P13 1 0 0
//��װ��ʾ״̬

//��ʱ����
void Delay1ms(u8 ms)		//@11.0592MHz
{
	unsigned char i, j;
	while(ms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}

}

//�������飬��װ����
u8 NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

//�������ʾ
void NixieDisPlay(u8 Location,DisplayNum)
{
	switch(Location)
	{
		case 1:P15 = 0;P14 = 0;P13 = 0;break;
		case 2:P15 = 0;P14 = 0;P13 = 1;break;
		case 3:P15 = 0;P14 = 1;P13 = 0;break;
		case 4:P15 = 0;P14 = 1;P13 = 1;break;
		case 5:P15 = 1;P14 = 0;P13 = 0;break;
		case 6:P15 = 1;P14 = 0;P13 = 1;break;
		case 7:P15 = 1;P14 = 1;P13 = 0;break;
		case 8:P15 = 1;P14 = 1;P13 = 1;break;
	}
	P0 = NixieTable[DisplayNum];
	Delay1ms(1);
	P0 = 0x00;
}

void main()
{


	while(1)
	{
		NixieDisPlay(1,1);
		
		NixieDisPlay(2,2);

		NixieDisPlay(3,3);

	}	
}
//ע����Ƭ��ֱ��ɨ�裬�����Ĵ����ĵ�Ƭ��CPUʱ��