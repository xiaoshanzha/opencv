#include   <iostream>   
#include<opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
using namespace cv;
using   namespace   std;
#define WINDOW_WIDTH 600

void Drawtuo(Mat img,double angle)  //������Բ
{
	int thickness = 2; //�߿�
	int lineType = 8;  //8��ͨ����,����һ����������һ����ı߻��

	ellipse(
		img,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),//��Բ���ĵ�
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),//λ�ڴ˾�����,�غ������ε���״�����һ�����Բ
		angle,//��Բ��ת�Ƕ�
		0,//��չ�Ļ��ȴ�0-360��  ������0-90��ֻ��1/4����Բ��
		360,
		Scalar(12, 23, 54),
		thickness,
		lineType
	);
}


void Drawcircle(Mat img,Point center)
{
	int thickness = -1;  //�ߴ�Ϊ-1�����Ի��Ƶ�ԲΪʵ��Բ
	int  lineType = 8;
	circle(
		img,
		center,  //Բ��
		WINDOW_WIDTH / 32,  //Բ�뾶
		Scalar(0, 0, 255),
		thickness,
		lineType
	);
}

void DrawPolygon(Mat img)  //���ư������
{
	int lineType = 8;
	Point rookPoints[2][8];  //��������ϵ��£�������
	//��һ������θ�����
	rookPoints[0][0] = Point(100, 100);
	rookPoints[0][1] = Point(150, 100);
	rookPoints[0][2] = Point(150, 150);
	rookPoints[0][3] = Point(200, 150);
	rookPoints[0][4] = Point(200, 100);
	rookPoints[0][5] = Point(250, 100);
	rookPoints[0][6] = Point(250, 200);
	rookPoints[0][7] = Point(100, 200);
	//�ڶ�������θ�����
	rookPoints[1][0] = Point(400, 400);
	rookPoints[1][1] = Point(500, 400);
	rookPoints[1][2] = Point(450, 450);
	const Point* ppt[1] = {  rookPoints[0]};  //ָ�����ζ��������ָ��ppt
	const Point* ppt2[1] = { rookPoints[1] };
	int npt[1] = {8}; int npt2[1] = { 3 };//����εĶ������������npt��
	fillPoly(img,
		ppt,
		npt,
		1,
		Scalar(255, 255, 255),
		lineType);
	fillPoly(img,
		ppt2,
		npt2,
		1,
		Scalar(255, 255, 255),
		lineType);
}

void DrawLine( Mat img,Point start,Point end )
{
	int thickness = 2;
	int lineType = 8;
	line(
		img,
		start,
		end,
		Scalar(12, 23, 54),
		thickness,
		lineType);
}

int main()
{
	/*
	Mat a,c;
	a = imread("1.jpg", CV_LOAD_IMAGE_COLOR);
	Mat b(a, Rect(10, 10, 100, 100));//ʹ�þ��ν綨����Ȥ����
	c = a;//��ֵ
	imshow("����Ȥ����",b);
	imshow("���ƣ�", c);
	waitKey(60000);*/


	/*����ͼ������Mat
	//�����������еĶ�ά��ͨ��ͼ��CV_[λ��][���������]C[ͨ����]��
	//Scalar��1,1,3����ʾ�Ծ���ÿ��Ԫ�ض���ֵΪ��1,1,3������һ����ͨ���е�ֵ����1��������ͨ���е�ֵ����3.
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 225));
	Mat r(10, 3, CV_8UC3);
	//randu()�����������ֵ��������
	randu(r, Scalar::all(0), Scalar::all(255));
	cout << "r = " << endl << r << endl;//opencv���
	cout << "r = " << format(r, Formatter::FMT_PYTHON) << endl; //python���
	
	
	Point2f p(6, 2);//�����ά��
	Point3f p1(1, 1, 1);//������ά��
	vector<float> v; //�������Mat ��std::vector
	v.push_back(3);//vector��push_back��������˼����vector��ĩβ����һ��Ԫ�ء�
	v.push_back(2);
	vector<Point2f> points(10);//����std::vector��
	for (size_t i = 0; i < points.size(); i++)
		points[i] = Point2f((float)(i * 5), (float)(i % 5));
	cout << "[��ά������]points="<<endl << points << endl;
	*/
	/*
	//�������ݽṹ�ͺ���
	
	Point point; point.x = 10; point.y = 8;//Point�� ��ı�ʾ
	Point point1 = Point(10, 8);
	Scalar(1, 2, 3);//��ɫ�ı�ʾ��Scalar�� ;�������ֱ���3��2��1
	Size(3, 4);//��size.width = 3, size.height = 4
	Rect a = Rect(200, 200, 200, 200);
	Rect b = Rect(200, 200, 100, 100);
	//Rect�ೣ�õĺ���Size();arwa()���ؾ��������contains(Point)�жϵ��Ƿ��ھ�����
	          //inside(Rect)�жϾ����Ƿ��ھ����ڣ�tl()�������Ͻ����꣬bl()���Ͻ�
	cout << "���ε����Ϊ:" << a.size() << endl;
	Rect c = a&b;  //�������� �Ľ���
	Rect d = a | b;//����
	cout << "����Ľ���Ϊ��" << c << endl;
	cout << "����Ĳ���Ϊ��" << d << endl;

	//cvtColor("����ͼ", "���ͼ", "��ɫ�ռ�ת���ı�ʶ��");
	Mat img1 = imread("1.jpg",1);
	Mat img2;
	cvtColor(img1, img2, COLOR_RGB2GRAY );
	imshow("ת����ͼ��Ϊ",img2);
	*/
	

	//����ͼ�εĻ���
	Mat empty = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);//�����հ׵�Matͼ��
	
	Drawtuo(empty, 0);
	Drawtuo(empty, 45);
	Drawtuo(empty, 90);
	Drawtuo(empty, 135);
//	Drawcircle(empty, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));

	DrawPolygon(empty);
	imshow("��ѧԭ��:", empty);
	//DrawLine(empty, Point(100, 100), Point(200, 200));

	//rectangle()���ƾ���
	/*
	rectangle(empty,
		Point(100,100), //���϶���
		Point(200,200), //���¶���
		Scalar(0, 255, 255),
		-1,
		8);*/
	waitKey();
}