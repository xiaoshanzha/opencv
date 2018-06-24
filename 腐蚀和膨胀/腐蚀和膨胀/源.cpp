#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

Mat src, dst;
void CallBack(int, void*);
int element_size = 1;
int max_size = 21;
int main()
{
	src = imread("F:/picture/lena.jpg");
	if (!src.data)
	{
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	namedWindow("output image", CV_WINDOW_AUTOSIZE);
	createTrackbar("element_size", "output image", &element_size, max_size, CallBack);
	CallBack(0, 0);

	waitKey(0);
	return 0;
}

void CallBack(int, void*)
{
	int s = element_size * 2 + 1; //此处理可确保边为奇数

	//获取不同形状的结构元素:第一个参数代表形状，第二个代表内核的尺寸
	Mat structureElement = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));

	//膨胀：结构元素B在图像A上面移动，计算B覆盖下A的最大像素值用来替换B中心锚点的像素。图片会变亮
	dilate(src, dst, structureElement, Point(-1, -1), 1);
	//腐蚀，最小元素替换  图片会变暗
	//erode(src, dst, structureElement);
	imshow("output image", dst);
	return;
}