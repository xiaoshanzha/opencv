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
	int s = element_size * 2 + 1; //�˴����ȷ����Ϊ����

	//��ȡ��ͬ��״�ĽṹԪ��:��һ������������״���ڶ��������ں˵ĳߴ�
	Mat structureElement = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));

	//���ͣ��ṹԪ��B��ͼ��A�����ƶ�������B������A���������ֵ�����滻B����ê������ء�ͼƬ�����
	dilate(src, dst, structureElement, Point(-1, -1), 1);
	//��ʴ����СԪ���滻  ͼƬ��䰵
	//erode(src, dst, structureElement);
	imshow("output image", dst);
	return;
}