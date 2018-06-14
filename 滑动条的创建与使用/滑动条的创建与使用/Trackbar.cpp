#include<opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
using namespace cv;
int now;//滑动条初始值
double Alpha, Beta; //两幅图混合分别所占的比例
Mat Image1, Image2, Image3;
//void f() = void f(void)即无参
void on_Trackbar(void*)
{
	Alpha = (double)now / 100;
	Beta = 1 - Alpha;
	addWeighted(Image1, Alpha, Image2, Beta, 0.0, Image3);
	imshow("线性混合示例", Image3);
}

int main()
{
	Image1 = imread("2.jpg");
	Image2 = imread("3.jpg");
	now = 70;
	//创建窗体
	namedWindow("线性混合示例", 1);
	//在创建的窗体中创建一个滑动条控件
	char TrackbarName[50];
	sprintf_s(TrackbarName, "透明值100");
	//createTrackbar(轨迹条的名字，窗口的名字，指向整型的指针(表示滑块的位置)，滑块可以达到的最大位置，回调函数)
	createTrackbar(TrackbarName, "线性混合示例",&now,100 ,on_Trackbar);
	//结果在回调函数中显示
	on_Trackbar( 0);
	waitKey(0);
	return 0;
}