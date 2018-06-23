#include <opencv2/opencv.hpp> 
#include <iostream> 
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst,biimage;
	src = imread("girl.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	char input_title[] = "input image";
	char output_title[] = "blur image";
	namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow(input_title, src);

	blur(src, dst, Size(11, 11), Point(-1, -1));  //��ֵ�˲�
	imshow(output_title, dst);

	Mat gblur;
	//������������˹�˺�����X�����ϵı�׼ƫ��
	//����������˹�˺�����Y�����ϵı�׼ƫ��
	GaussianBlur(src, gblur, Size(11, 11), 1, 11);    //��˹�˲�
	imshow("gaussian blur", gblur);


	//��������������ʾ�ڹ��˹�����ÿ�����������ֱ����Χ
	//���ĸ���������ɫ�ռ��������sigmaֵ�����������ֵԽ�󣬱�����������������Խ������ɫ�ᱻ��ϵ�һ�𣬲����ϴ�İ������ɫ����
	//���������������ռ����˲�����sigmaֵ�������ֵ�ϴ�����ζ����ɫ����Ľ�Զ�����ؽ��໥Ӱ�죬�Ӷ�ʹ������������㹻���Ƶ���ɫ��ȡ��ͬ����ɫ��
	
	bilateralFilter(src, biimage, 15, 50, 5);  //˫���˲�  Ȩ���ڱ߽��к����Եķֽ磬�Ӷ�����ֻ���Լ������ı�Եһ������ص���м�Ȩ���Ǳ߽�õ��ܺõı������Ǳ߽����ƽ��
	namedWindow("BiBlur Filter Result", CV_WINDOW_AUTOSIZE);   //���Դﵽ����ȥ���Ŀ��
	imshow("BiBlur Filter Result", biimage);

	waitKey(0);
	return 0;
}