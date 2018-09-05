#define _CRT_SECURE_NO_DEPRECATE //去除fopen報警告
#include <stdio.h> 
#include <cv.h> 
#include <highgui.h> 
#include <iostream>
#include <fstream>
#include <string>
using namespace cv;
using namespace std;

void HW1_2(void)
{unsigned char *lena512;
	int size3=512*512;
char FileNameRes[]="lena512.raw";
		char FileName2[]="lena2512.bmp";
		lena512 = new unsigned char[size3];
CvMat *lena5122 = cvCreateMat(512,512, CV_8UC1);
	CvMat *lena512mat = cvCreateMat(512,512, CV_8UC1);

FILE *le512;
	le512 = fopen(FileNameRes,"rb");
	fread(lena512,1,size3,le512);


cvSetData(lena512mat,lena512,lena512mat->step);
			

		cvSetData(lena5122,lena512,lena5122->step);
	

		CvPoint CircleCenter=cvPoint(256,256);
		CvSize EllipseAxes=cvSize(250,100);
		double RotateAngle=0;
		double StartDrawingAngle=0;
		double StopDrawingAngle=360;
		CvScalar Color=CV_RGB(255,255,255);
		int Thickness=5;
		int Shift=0;

		cvEllipse(lena512mat,CircleCenter,EllipseAxes,RotateAngle,StartDrawingAngle,StopDrawingAngle,Color,Thickness,CV_AA,Shift);

		CvFont Font1=cvFont(1,1);
		cvInitFont(&Font1,CV_FONT_HERSHEY_SIMPLEX,2,1,0.1,2,CV_AA);

		CvPoint TextPosition1=cvPoint(40,270);
		Color=CV_RGB(0,0,0);

		cvPutText(lena512mat,"1 0 5 3 1 8 0 3 2",TextPosition1,&Font1,Color);


		cvShowImage("2",lena512mat);	
	cvWaitKey(0);	
		cvSaveImage(FileName2,lena512mat);

		fclose(le512);
}
