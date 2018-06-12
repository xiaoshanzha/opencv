//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2\opencv.hpp>

using namespace cv;
int main()
{
	/*
	Mat picture = imread("big.jpg");//ͼƬ������ӵ�����Ŀ¼��									  //Ҳ���Ǻ�test.cpp�ļ�����һ���ļ����£�����
	imshow("ԭͼ", picture);
	*/

	/* ͼ��ʴ
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(picture, dstImage, element);
	imshow("��ʴ��", dstImage);*/

	/*ͼ��ģ��
	Mat dstImage;
	blur(picture, dstImage, Size(7, 7));
	imshow("ģ��:", dstImage);*/

	/*��Ե���
	Mat dsImage, edge, grayImage;
	dsImage.create(picture.size(), picture.type());
	//��ԭͼת���ɻҶ�ͼ��
	cvtColor(picture, grayImage,COLOR_BGR2GRAY);//ת��BGR��ɫͼΪ�Ҷ�ͼ
	blur(grayImage, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("��Ե���", edge);*/

	//��ȡ��������Ƶ
	VideoCapture capture;
	//capture.open("cg.avi");��ȡavi�ļ�
	capture.open(0);//������ͷ
	Mat edges;
	while (1)
	{
		Mat frame;
		capture >> frame;  //��ȡ��ǰ֡
		cvtColor(frame, edges, CV_BGR2GRAY);
		//ʹ��3*3�ں������루2*3+1=7��,����ģ��
		blur(edges, edges, Size(7, 7));
		Canny(edges, edges, 0, 30, 3);
		imshow("��ȡ��Ƶ", edges);
		if (waitKey(30) >= 0)
		{
			break;
		}
	}
	waitKey(0);
	return 0;
}