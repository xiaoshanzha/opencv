
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
	//��ʱ����
	double time0 = getTickCount(); //cpu��ĳ�¼��������ߵ�ʱ��������
	double time1 = getTickFrequency();//cpuһ�������ߵ�ʱ��������
	//����ͼ�������صķ���
	Mat img = imread("1.jpg");
	imshow("����ǰ��", img);
	Mat img2;
	img2.create(img.rows, img.cols, img.type());

//	colorReduce(img, img2, 32);
//	ROI_AddImage();
	//imshow("�����", img2);
	//mix();
	//ROI_mix();

	srcImage = imread("1.jpg");
	dstImage = Mat::zeros(srcImage.size(), srcImage.type());
	duibidu = 80;
	liangdu = 80;
	namedWindow("[Ч��ͼ����]", 1);

	createTrackbar("�Աȶ�;", "[Ч��ͼ����]", &duibidu, 300, on_ContrastAndRight);
	createTrackbar("����;", "[Ч��ͼ����]", &liangdu, 300, on_ContrastAndRight);
	while (char(waitKey(1))!='q') //���¡�q����
	{

	}

	return 0;
}

//��ָ��������ز�����
void colorReduce(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();
	int rowNum = outputImage.rows;
	int colNum = outputImage.cols * outputImage.channels();//ÿ��Ԫ�ظ���=����*ͨ����

	for (int i = 0; i < rowNum; i++)
	{
		uchar* data = outputImage.ptr<uchar>(i); //��ȡ��i�е��׵�ַ
		for (int j = 0; j < colNum; j++)
		{
			data[j] = data[j] / div*div+div/2;  //����ÿ������,
		}
	}
}

void ROI_AddImage()
{
	Mat img3 = imread("1.jpg");
	Mat logo = imread("2.jpg");
	Mat ROI = img3(Rect(200, 200, logo.cols, logo.rows));
	Mat mask = imread("2.jpg",0); //������Ĥ�������ǻҶ�ͼ
	logo.copyTo(ROI,mask); //����Ĥ���Ƶ�ROI
	//logo.copyTo(ROI) ����logo��ӵ�ROI,��ֱ������д������Ȥ������ǰ��ͼƬ���ɼ�
	imshow("����", img3);
}
void mix()
{
	Mat zhiwu, rain, hunhe;
	zhiwu = imread("zhiwu.jpg");
	rain = imread("rain.jpg");
	addWeighted(zhiwu, 0.5, rain, 0.5, 0.0, hunhe);//ͼ���ϼ�Ȩ
	imshow("ԭͼ��", zhiwu);
	imshow("���Ի�ϣ�", hunhe);
}
void ROI_mix()
{
	Mat img3 = imread("1.jpg");
	Mat logo = imread("2.jpg");
	Mat ROI = img3(Rect(200, 200, logo.cols, logo.rows));
	addWeighted(ROI, 0.5, logo, 0.7, 0., ROI);
	imshow("������", img3);
}

//�ı�ͼ��ԱȶȺ�����ֵ�Ļص�����
static void on_ContrastAndRight(int, void *)
{
	namedWindow("[ԭʼͼ����]", 1);//��������
	for (int y = 0; y < srcImage.rows; y++)
	{
		for (int x = 0; x < srcImage.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((duibidu*0.01)*(srcImage.at<Vec3b>(y, x)[c]) + liangdu);
				//saturate_castģ�庯���������������  eg: if(data<0) data=0;else if(data>255)  data = 255;
			}
		}
	}
	imshow("ԭʼͼ", srcImage);
	imshow("Ч��ͼ", dstImage);
}

