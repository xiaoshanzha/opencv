#include   <iostream>   
#include<opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
using namespace cv;
using   namespace   std;
#define WINDOW_WIDTH 600

void Drawtuo(Mat img,double angle)  //绘制椭圆
{
	int thickness = 2; //线宽
	int lineType = 8;  //8联通线型,即下一个点连接上一个点的边或角

	ellipse(
		img,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),//椭圆中心点
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),//位于此矩形内,关乎到矩形的形状，宽高一样变成圆
		angle,//椭圆旋转角度
		0,//扩展的弧度从0-360度  假如是0-90，只是1/4个椭圆弧
		360,
		Scalar(12, 23, 54),
		thickness,
		lineType
	);
}


void Drawcircle(Mat img,Point center)
{
	int thickness = -1;  //线粗为-1，所以绘制的圆为实心圆
	int  lineType = 8;
	circle(
		img,
		center,  //圆心
		WINDOW_WIDTH / 32,  //圆半径
		Scalar(0, 0, 255),
		thickness,
		lineType
	);
}

void DrawPolygon(Mat img)  //绘制凹多边形
{
	int lineType = 8;
	Point rookPoints[2][8];  //各顶点从上到下，从左到右
	//第一个多边形各顶点
	rookPoints[0][0] = Point(100, 100);
	rookPoints[0][1] = Point(150, 100);
	rookPoints[0][2] = Point(150, 150);
	rookPoints[0][3] = Point(200, 150);
	rookPoints[0][4] = Point(200, 100);
	rookPoints[0][5] = Point(250, 100);
	rookPoints[0][6] = Point(250, 200);
	rookPoints[0][7] = Point(100, 200);
	//第二个多边形各顶点
	rookPoints[1][0] = Point(400, 400);
	rookPoints[1][1] = Point(500, 400);
	rookPoints[1][2] = Point(450, 450);
	const Point* ppt[1] = {  rookPoints[0]};  //指向多边形顶点的数组指针ppt
	const Point* ppt2[1] = { rookPoints[1] };
	int npt[1] = {8}; int npt2[1] = { 3 };//多边形的顶点个数的数组npt。
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
	Mat b(a, Rect(10, 10, 100, 100));//使用矩形界定感兴趣区域
	c = a;//赋值
	imshow("感兴趣区域",b);
	imshow("复制：", c);
	waitKey(60000);*/


	/*基础图像容器Mat
	//创建两行两列的二维多通道图像，CV_[位数][带符号与否]C[通道数]，
	//Scalar（1,1,3）表示对矩阵每个元素都赋值为（1,1,3），第一二个通道中的值都是1，第三个通道中的值都是3.
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 225));
	Mat r(10, 3, CV_8UC3);
	//randu()函数产生随机值来填充矩阵
	randu(r, Scalar::all(0), Scalar::all(255));
	cout << "r = " << endl << r << endl;//opencv风格
	cout << "r = " << format(r, Formatter::FMT_PYTHON) << endl; //python风格
	
	
	Point2f p(6, 2);//定义二维点
	Point3f p1(1, 1, 1);//定义三维点
	vector<float> v; //定义基于Mat 的std::vector
	v.push_back(3);//vector中push_back函数的意思是在vector的末尾插入一个元素。
	v.push_back(2);
	vector<Point2f> points(10);//定义std::vector点
	for (size_t i = 0; i < points.size(); i++)
		points[i] = Point2f((float)(i * 5), (float)(i % 5));
	cout << "[二维点向量]points="<<endl << points << endl;
	*/
	/*
	//常用数据结构和函数
	
	Point point; point.x = 10; point.y = 8;//Point类 点的表示
	Point point1 = Point(10, 8);
	Scalar(1, 2, 3);//颜色的表示：Scalar类 ;红绿蓝分别是3，2，1
	Size(3, 4);//即size.width = 3, size.height = 4
	Rect a = Rect(200, 200, 200, 200);
	Rect b = Rect(200, 200, 100, 100);
	//Rect类常用的函数Size();arwa()返回矩形面积，contains(Point)判断点是否在矩形内
	          //inside(Rect)判断矩形是否在矩形内，tl()返回左上角坐标，bl()右上角
	cout << "矩形的面积为:" << a.size() << endl;
	Rect c = a&b;  //求两矩形 的交集
	Rect d = a | b;//并集
	cout << "矩阵的交集为：" << c << endl;
	cout << "矩阵的并集为：" << d << endl;

	//cvtColor("输入图", "输出图", "颜色空间转换的标识符");
	Mat img1 = imread("1.jpg",1);
	Mat img2;
	cvtColor(img1, img2, COLOR_RGB2GRAY );
	imshow("转换后图像为",img2);
	*/
	

	//基本图形的绘制
	Mat empty = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);//创建空白的Mat图像
	
	Drawtuo(empty, 0);
	Drawtuo(empty, 45);
	Drawtuo(empty, 90);
	Drawtuo(empty, 135);
//	Drawcircle(empty, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));

	DrawPolygon(empty);
	imshow("化学原子:", empty);
	//DrawLine(empty, Point(100, 100), Point(200, 200));

	//rectangle()绘制矩形
	/*
	rectangle(empty,
		Point(100,100), //左上顶点
		Point(200,200), //右下顶点
		Scalar(0, 255, 255),
		-1,
		8);*/
	waitKey();
}