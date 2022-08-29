#include <stdio.h>
#include "receieveturn.h"

/********************************************************************
*��    ��:turn_charinto_float
*��    ��:���ڽ�NRF24L01���յ�������ת����float���͵����ݣ�����д��������OLED����ʾ
*��ڲ���:unsigned char p ΪNRF24L01���յ������ݣ�flaot zz���ڴ洢ת�����float���ݣ�char sign_plus���ڴ洢������Ϣ
*���ڲ���:��
*˵    ��:��
*���÷���:��
********************************************************************/

void turn_charinto_float(unsigned char* p, float* zz, char* sign_plus) //p[]Ϊnrf24l01 ���յ������ݣ�xx1,yy1,zz1 ���ڴ洢 pitch��roll��yaw �ĸ���λ; zz ���ڴ洢float���͵�����
{
    int i;
		unsigned int xx1[4];
		unsigned int yy1[4];
		unsigned int zz1[4];

    switch(p[0])
    {
    case 1:
        sign_plus[0] = '+';
        sign_plus[1] = '+';
        sign_plus[2] = '+';
        break;
    case 2:
        sign_plus[0] = '+';
        sign_plus[1] = '+';
        sign_plus[2] = '-';
        break;
    case 3:
        sign_plus[0] = '+';
        sign_plus[1] = '-';
        sign_plus[2] = '-';
    case 4:
        sign_plus[0] = '+';
        sign_plus[1] = '+';
        sign_plus[2] = '+';
        break;
    case 5:
        sign_plus[0] = '-';
        sign_plus[1] = '-';
        sign_plus[2] = '-';
    case 6:
        sign_plus[0] = '-';
        sign_plus[1] = '+';
        sign_plus[2] = '+';
        break;
    case 7:
        sign_plus[0] = '+';
        sign_plus[1] = '-';
        sign_plus[2] = '+';
        break;
    case 8:
        sign_plus[0] = '-';
        sign_plus[1] = '+';
        sign_plus[2] = '-';
        break;
    }

    for(i=3; i>=0; i--)                                         //��unsigned char��������ת����unsigned int����
    {
        xx1[i] = p[i+1];
        yy1[i] = p[i+5];
        zz1[i] = p[i+9];
    }

    zz[0] = xx1[3]*100 + xx1[2]*10 + xx1[1] + xx1[0]*0.1;       //�����յ���unsigned cahr ���͵�����ת����float����
    zz[1] = yy1[3]*100 + yy1[2]*10 + yy1[1] + yy1[0]*0.1;
    zz[2] = zz1[3]*100 + zz1[2]*10 + zz1[1] + zz1[0]*0.1;
}

