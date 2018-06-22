
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void colorReduce(Mat& inputImage, Mat& outputImage, int div);
void ROI_AddImage();
void mix();
void ROI_mix();
static void on_ContrastAndRight(int, void *);


int duibidu, liangdu;
Mat srcImage, dstImage;
int main()
{
	//计时函数
	double time0 = getTickCount(); //cpu自某事件以来所走的时钟周期数
	double time1 = getTickFrequency();//cpu一秒钟所走的时钟周期数
	//访问图像中像素的方法
	Mat img = imread("1.jpg");
	imshow("处理前：", img);
	Mat img2;
	img2.create(img.rows, img.cols, img.type());

//	colorReduce(img, img2, 32);
//	ROI_AddImage();
	//imshow("处理后：", img2);
	//mix();
	//ROI_mix();

	srcImage = imread("1.jpg");
	dstImage = Mat::zeros(srcImage.size(), srcImage.type());
	duibidu = 80;
	liangdu = 80;
	namedWindow("[效果图窗口]", 1);

	createTrackbar("对比度;", "[效果图窗口]", &duibidu, 300, on_ContrastAndRight);
	createTrackbar("亮度;", "[效果图窗口]", &liangdu, 300, on_ContrastAndRight);
	while (char(waitKey(1))!='q') //按下‘q’退
	{

	}

	return 0;
}

//用指针访问像素并处理
void colorReduce(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();
	int rowNum = outputImage.rows;
	int colNum = outputImage.cols * outputImage.channels();//每行元素个数=列数*通道数

	for (int i = 0; i < rowNum; i++)
	{
		uchar* data = outputImage.ptr<uchar>(i); //获取第i行的首地址
		for (int j = 0; j < colNum; j++)
		{
			data[j] = data[j] / div*div+div/2;  //处理每个像素,
		}
	}
}

void ROI_AddImage()
{
	Mat img3 = imread("1.jpg");
	Mat logo = imread("2.jpg");
	Mat ROI = img3(Rect(200, 200, logo.cols, logo.rows));
	Mat mask = imread("2.jpg",0); //加载掩膜，必须是灰度图
	logo.copyTo(ROI,mask); //将掩膜复制到ROI
	//logo.copyTo(ROI) 即将logo添加到ROI,若直接这样写，感兴趣区域以前的图片不可见
	imshow("叠加", img3);
}
void mix()
{
	Mat zhiwu, rain, hunhe;
	zhiwu = imread("zhiwu.jpg");
	rain = imread("rain.jpg");
	addWeighted(zhiwu, 0.5, rain, 0.5, 0.0, hunhe);//图像混合加权
	imshow("原图：", zhiwu);
	imshow("线性混合：", hunhe);
}
void ROI_mix()
{
	Mat img3 = imread("1.jpg");
	Mat logo = imread("2.jpg");
	Mat ROI = img3(Rect(200, 200, logo.cols, logo.rows));
	addWeighted(ROI, 0.5, logo, 0.7, 0., ROI);
	imshow("区域混合", img3);
}

//改变图像对比度和亮度值的回调函数
static void on_ContrastAndRight(int, void *)
{
	namedWindow("[原始图窗口]", 1);//创建窗口
	for (int y = 0; y < srcImage.rows; y++)
	{
		for (int x = 0; x < srcImage.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((duibidu*0.01)*(srcImage.at<Vec3b>(y, x)[c]) + liangdu);
				//saturate_cast模板函数：用于溢出保护  eg: if(data<0) data=0;else if(data>255)  data = 255;
			}
		}
	}
	imshow("原始图", srcImage);
	imshow("效果图", dstImage);
}

