#define _CRT_SECURE_NO_DEPRECATE //去除fopen報警告
#include <stdio.h> 
#include <cv.h> 
#include <highgui.h> 
#include <iostream>
#include <fstream>
#include <string>
using namespace cv;
using namespace std;
# define size 256*256


void HW1_1_c_1(void)
{unsigned char *lenai , *lenacc , *lenacco;
char FileNameOri[]="lena256.raw";
char FileNamec[]="c.raw";

lenai = new unsigned char[size]; 
lenacco = new unsigned char[size]; 
lenacc = new unsigned char[size]; 
	CvMat *lenac = cvCreateMat(256,256, CV_8UC1);
FILE *lena;
	lena = fopen(FileNameOri,"rb");
	FILE *c;
	c = fopen(FileNamec,"wb");
	if(lena==NULL)
	{
		puts("Loading File Error!");
	}
	else
	{
		fread(lenai,1,size,lena);

		for(int y=0;y<256;y++)
			for(int x=0;x<256;x++)
		{
		lenacc[256*x+y] = lenai[256*x+y]; 
		
	}

		for(int x=0;x<256;x++)
		{
			for(int y=0;y<256;y++)
			{
				int depth = lenacc[256*x+y]+80;
				if(depth >=255)
				{
					lenacco[256*x+y] = 255;
				}
				else
				{
					lenacco[256*x+y] = depth;
				}
		
			}
			
		}
		cvSetData(lenac,lenacco,lenac->step);
			cvShowImage("(c)",lenac);	
			cvWaitKey(0);	
			fwrite (lenacco,1,size,c);

}

		fclose(lena);
	fclose(c);

	delete lenai;


}