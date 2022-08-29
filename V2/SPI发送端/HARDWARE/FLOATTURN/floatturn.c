#include "floatturn.h"

void floatturn(float *a, unsigned char *p, float *z)	    //a[]用于输入pitch roll yaw 角度值；p[]用于存储pitch yaw roll数据,从p[1]开始；数组输入退化为指针
{
    int b[4];                                   //b[]用来存储 pitch roll yaw 转换成非负的整数型
    int s;				                        			//用于存储b[i]的余数
		int i,j;


    for(i=0; i<3; i++)
    {
        b[i] = a[i]*10+900;
				if(b[i]<0)
					b[i]=0;
				if(b[i]>1800)
					b[i]=180;
    }
		
		b[3] = a[3]*10;

    for(i=0; i<4; i++)
    {
        for(j=4*i+1; j<=4*i+4; j++)
        {
            s = b[i]%10;
            p[j] = s;		//存储每一位,由低位向高位
            b[i] = b[i]/10;
        }
    }
		
		z[0]=p[1]*0.1+p[2]+p[3]*10+p[4]*100;
		z[1]=p[5]*0.1+p[6]+p[7]*10+p[8]*100;
		z[2]=p[9]*0.1+p[10]+p[11]*10+p[12]*100;
		z[3]=p[13]*0.1+p[14]+p[15]*10+p[16]*100;
}
