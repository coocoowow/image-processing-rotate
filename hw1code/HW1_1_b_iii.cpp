#define _CRT_SECURE_NO_DEPRECATE //去除fopen報警告
#include <stdio.h> 
#include <cv.h> 
#include <highgui.h> 
#include <iostream>
#include <fstream>
#include <string>
using namespace cv;
using namespace std;
#define size 256*256 //先定義一個矩陣的size


void HW1_1_b_iii(void)
{unsigned char *lenai;
 char FileNameOri[]="lena256.raw";

lenai = new unsigned char[size]; 
	CvMat *lenamat = cvCreateMat(256,256, CV_8UC1);
FILE *lena;
	lena = fopen(FileNameOri,"rb");
	if(lena==NULL)
	{
		puts("Loading File Error!");
	}
	else
	{
		fread(lenai,1,size,lena);
		cvSetData(lenamat,lenai,lenamat->step);
	

		cvResizeWindow("lena",256,256);
		cvMoveWindow("lena",100,100);
		cvShowImage("iii",lenamat);	
		

}


	fclose(lena);
		cvWaitKey(0);	

}