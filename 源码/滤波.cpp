#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>


using namespace std;
using namespace cv;

Mat src;
int main()
{
	src = imread("F:/picture/gao.jpg");
	if (!src.data)
	{
		printf("could not load image...\n");
		return -1;
	}

	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);
	
	Mat blur_dst;
	blur(src, blur_dst, Size(11, 11), Point(-1, -1));
	imshow("blur image", blur_dst);

	Mat gblur;
	GaussianBlur(src, gblur, Size(11, 11), 0, 0);
	imshow("gaussian blur", gblur);
	
	Mat bilateral_dst;
	bilateralFilter(src, bilateral_dst, 3, 50, 5);
	imshow("bil", bilateral_dst);

	Mat  med_dst;
	medianBlur(src, med_dst, 3);
	imshow("med", med_dst);
	

	Mat highdst,lowdst,linedst;
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);//¸ßÍ¨ÂË²¨Ä£°å
	filter2D(src, highdst, src.depth(), kernel); 
	imshow("highpass", highdst);
	
	waitKey(0);
	return 0;
}