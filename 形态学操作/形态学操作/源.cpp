#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("F:/picture/chars.jpg");
	if (!src.data) {
		printf("could not load image...\n");
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);


	char output_title[] = "morphology demo";
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);

	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);
	imshow("gray image", gray_src);

	Mat binImg;
	adaptiveThreshold(~gray_src, binImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	imshow("binary image", binImg);

	// ˮƽ�ṹԪ��
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 16, 1), Point(-1, -1));
	// ��ֱ�ṹԪ��
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16), Point(-1, -1));
	// ���νṹ
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3), Point(-1, -1));


	//���������ȸ�ʴ�����͡���������ϸС���壬����ϸ�����������ƽ���ϴ�����߽�����á�
//	morphologyEx(src, dst, CV_MOP_OPEN, kernel);


	//�ղ����������ͺ�ʴ���������������ϸС�ն��������ڽ������ƽ���߽�����á�
	//morphologyEx(src, dst, CV_MOP_CLOSE, kernel);

	//��̬ѧ�ݶ�=�����ݶȣ������ͺ��ͼ���ȥ��ʴ���ͼ��õ���ֵͼ�񣬿�������̬ѧ�ݶ���ͻ����Ե����������ı�Ե������
	morphologyEx(src, dst, CV_MOP_GRADIENT, kernel);

	//��ñ��ԭͼ�뿪������ͼ֮�������Ŵ����ѷ���߾ֲ������ȵ��������ԣ���ԭͼ�м�ȥ��������ͼ���õ��Ľ��ͻ���˱�ԭͼ������Χ�����������������
//	morphologyEx(src, dst, CV_MOP_TOPHAT, kernel);

	//��ñ���㣺������Ľ����ԭͼ֮�ͻ���˱�ԭͼ������Χ����������������Ժ�ñ��������������ڽ��㰵һЩ�İ߿�
	//morphologyEx(src, dst, CV_MOP_BLACKHAT, kernel);

	imshow(output_title, dst);

	//��ȡˮƽ�봹ֱ�ߣ�1.����ͼ���ɫͼ�� 2.ת��Ϊ�Ҷ�ͼ�� 3.ת��Ϊ��ֵͼ�� 4.����ṹԪ�� 5.��������ȡˮƽ�봹ֱ��

	//���þ��νṹԪ�� ���Է���� ϸ�߸����µĽϴ�����

	Mat temp;
	erode(binImg, temp,kernel);
	dilate(temp, dst, kernel);
	// morphologyEx(binImg, dst, CV_MOP_OPEN, vline);
	//bitwise_not(dst, dst);
	//blur(dst, dst, Size(3, 3), Point(-1, -1));
	imshow("Final Result", dst);
	
	

	waitKey(0);
	return 0;
}