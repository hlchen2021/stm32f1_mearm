#include "floatturn.h"
#define EPISON 1e-7                             //float����ֱ����0�Ƚϴ�С

void floatturn(float *a, unsigned char *p, float *z)	    //a[]��������pitch roll yaw �Ƕ�ֵ��p[]���ڴ洢pitch yaw roll���ݣ���0λ���ڴ洢��������Ϣ�����������˻�Ϊָ��
{
    int b[3];                                   //b[]�����洢 pitch roll yaw ת���ɷǸ���������
    int s;				                        			//���ڴ洢b[i]������
		int i,j;

    if(a[0]>EPISON && a[1]>EPISON && a[3]>EPISON)
        p[0] = '1';
    if(a[0]>EPISON && a[1]>EPISON && a[3]<EPISON)
        p[0] = '2';
    if(a[0]>EPISON && a[1]<EPISON && a[3]<EPISON)
        p[0] = '3';
    if(a[0]<EPISON && a[1]<EPISON && a[3]<EPISON)
        p[0] = '4';
    if(a[0]<EPISON && a[1]<EPISON && a[3]>EPISON)
        p[0] = '5';
    if(a[0]<EPISON && a[1]>EPISON && a[3]>EPISON)
        p[0] = '6';
    if(a[0]>EPISON && a[1]<EPISON && a[3]>EPISON)
        p[0] = '7';
    if(a[0]<EPISON && a[1]>EPISON && a[3]<EPISON)
        p[0] = '8';

    for(i=0; i<3; i++)
    {
        b[i] = a[i]*10;
        if(b[i] < 0)
            b[i] = -b[i];
    }

    for(i=0; i<3; i++)
    {
        for(j=4*i+1; j<=4*i+4; j++)
        {
            s = b[i]%10;
            p[j] = s;		//�洢ÿһλ,�ɵ�λ���λ
            b[i] = b[i]/10;
        }
    }
		
		z[0]=p[1]*0.1+p[2]+p[3]*10+p[4]*100;
		z[1]=p[5]*0.1+p[6]+p[7]*10+p[8]*100;
		z[2]=p[9]*0.1+p[10]+p[11]*10+p[12]*100;
}
