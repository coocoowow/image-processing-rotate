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
void HW1_1_b_iv(void)
{
unsigned char *lenai,*lena90 , *lena990,*lenacc,*lenao;
char FileNameOri[]="lena256.raw";
char FileNameiva[]="iva.raw";
char FileNameivb[]="ivb.raw";

lenai = new unsigned char[size]; 
lenacc = new unsigned char[size]; 
lena90 = new unsigned char[size];
lena990 = new unsigned char[size];
lenao = new unsigned char[size];
CvMat *lenamat = cvCreateMat(256,256, CV_8UC1);
CvMat *newlena = cvCreateMat(256,256, CV_8UC1);
CvMat *newlena90 = cvCreateMat(256,256, CV_8UC1);
Mat lena1(128,128,CV_8U);
Mat lena2(128,128,CV_8U);
Mat lena3(128,128,CV_8U);
Mat lena4(128,128,CV_8U);
Mat lenacut(256,256,CV_8U); 


FILE *lena;
FILE *lena_out ;
FILE *ivb;
lena_out = fopen(FileNameiva,"wb");
ivb = fopen(FileNameivb,"wb");
	lena = fopen(FileNameOri,"rb");
	if(lena==NULL)
	{
		puts("Loading File Error!");
	}
	else
	{
		fread(lenai,1,size,lena);
		cvSetData(lenamat,lenai,lenamat->step);

			

		for(int y=0;y<256;y++)
			for(int x=0;x<256;x++)
		{
		lena90[256*y+x] = lenai[256*x+y]; 

	}
			for(int y=0;y<256;y++)
			for(int x=0;x<256;x++)
			{
		lena990[256*y+x] = lena90[256*(255-x)+y]; 
			}

			for(int y=0;y<256;y++)
			for(int x=0;x<256;x++)
			{
		lenao[256*y+x] = lena990[256*(255-x)+y]; 
			}

		cvSetData(newlena,lena90,newlena->step);
		cvSetData(newlena90,lenao,newlena90->step);
		cvShowImage("iva",newlena90);	
		cvWaitKey(0);	
cv::Mat dst;
dst = Mat(newlena->rows,newlena ->cols,newlena->type,newlena->data.fl);//轉換格式


	for(int y=0;y<128;y++)
{
	for(int x=0;x<128;x++)

	{
	lenacut.at<uchar>(y+128,x+128)=dst.at<uchar>(y,x);

	}
}



		for(int y=0;y<128;y++)
{
	for(int x=0;x<128;x++)

	{
	lenacut.at<uchar>(y+128,x)=dst.at<uchar>(y,x+128);

	}
}


		for(int y=0;y<128;y++)
{
	for(int x=0;x<128;x++)

	{
	lenacut.at<uchar>(y,x+128)=dst.at<uchar>(y+128,x);

	}
}


		for(int y=0;y<128;y++)
{
	for(int x=0;x<128;x++)

	{

	lenacut.at<uchar>(y,x)=dst.at<uchar>(y+128,x+128);

	}
}


imshow("ivb",lenacut);
cvWaitKey(0);	
uchar *data= lenacut.data;//轉換格式




fwrite (lenao,1,size,lena_out);
fwrite (data,1,size,ivb);

}


	fclose(lena);
	fclose(lena_out);
	fclose(ivb);
	delete lenai;
    cvReleaseMatHeader(&lenamat);

}