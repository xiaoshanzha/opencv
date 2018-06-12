//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2\opencv.hpp>

using namespace cv;
int main()
{
	/*
	Mat picture = imread("big.jpg");//图片必须添加到工程目录下									  //也就是和test.cpp文件放在一个文件夹下！！！
	imshow("原图", picture);
	*/

	/* 图像腐蚀
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(picture, dstImage, element);
	imshow("腐蚀后", dstImage);*/

	/*图像模糊
	Mat dstImage;
	blur(picture, dstImage, Size(7, 7));
	imshow("模糊:", dstImage);*/

	/*边缘检测
	Mat dsImage, edge, grayImage;
	dsImage.create(picture.size(), picture.type());
	//将原图转换成灰度图像
	cvtColor(picture, grayImage,COLOR_BGR2GRAY);//转化BGR彩色图为灰度图
	blur(grayImage, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("边缘检测", edge);*/

	//读取并播放视频
	VideoCapture capture;
	//capture.open("cg.avi");读取avi文件
	capture.open(0);//打开摄像头
	Mat edges;
	while (1)
	{
		Mat frame;
		capture >> frame;  //读取当前帧
		cvtColor(frame, edges, CV_BGR2GRAY);
		//使用3*3内核来降噪（2*3+1=7）,进行模糊
		blur(edges, edges, Size(7, 7));
		Canny(edges, edges, 0, 30, 3);
		imshow("读取视频", edges);
		if (waitKey(30) >= 0)
		{
			break;
		}
	}
	waitKey(0);
	return 0;
}