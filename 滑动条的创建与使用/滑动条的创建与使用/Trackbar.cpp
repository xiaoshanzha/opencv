#include<opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
using namespace cv;
int now;//��������ʼֵ
double Alpha, Beta; //����ͼ��Ϸֱ���ռ�ı���
Mat Image1, Image2, Image3;
//void f() = void f(void)���޲�
void on_Trackbar(void*)
{
	Alpha = (double)now / 100;
	Beta = 1 - Alpha;
	addWeighted(Image1, Alpha, Image2, Beta, 0.0, Image3);
	imshow("���Ի��ʾ��", Image3);
}

int main()
{
	Image1 = imread("2.jpg");
	Image2 = imread("3.jpg");
	now = 70;
	//��������
	namedWindow("���Ի��ʾ��", 1);
	//�ڴ����Ĵ����д���һ���������ؼ�
	char TrackbarName[50];
	sprintf_s(TrackbarName, "͸��ֵ100");
	//createTrackbar(�켣�������֣����ڵ����֣�ָ�����͵�ָ��(��ʾ�����λ��)��������Դﵽ�����λ�ã��ص�����)
	createTrackbar(TrackbarName, "���Ի��ʾ��",&now,100 ,on_Trackbar);
	//����ڻص���������ʾ
	on_Trackbar( 0);
	waitKey(0);
	return 0;
}