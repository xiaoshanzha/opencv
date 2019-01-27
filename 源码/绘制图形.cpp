#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>


using namespace std;
using namespace cv;

Mat src;
void My_Line();
void My_arrowLine();
void My_rectangle();
void My_ellipse();
void MyPolygon();
void MY_putText();
void My_circle();
void RandomLineDemo();
int main()
{
	Mat dst;
	src = imread("F:/picture/dog.jpg");
	if (!src.data)
	{
		printf("could not load image...\n");
		return -1;
	}
	My_Line();
	My_arrowLine();
	My_circle();
	My_rectangle();
	My_ellipse();
	MyPolygon();
	MY_putText();
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);
	
	 RandomLineDemo();
	return 0;
}
void My_arrowLine()
{
	Point p1 = Point(600, 20);
	Point p2;
	p2.x = 200;
	p2.y = 100;
	Scalar color = Scalar(100, 100, 255);
	arrowedLine(src, p1, p2, color, 2, LINE_AA,0,0.1);
}
void My_Line()
{
	Point p1 = Point(30, 30);
	Point p2;
	p2.x = 100;
	p2.y = 30;
	Scalar color = Scalar(100, 100, 255);
	line(src, p1, p2, color, 2, LINE_AA, 0);
}
void My_rectangle()
{
	Point p1 = Point(200, 20);
	Point p2;
	p2.x = 400;
	p2.y = 220;
	Scalar color = Scalar(0, 0, 255);
	rectangle(src, p1, p2, color, 1, LINE_8, 0);
}
void My_ellipse()
{
	Point p1 = Point(300, 300);
	Scalar color = Scalar(100, 10, 220);
	Size axes(src.cols / 4, src.rows / 8);
	Size axes1(100, 50);
	ellipse(src, p1,  axes1, 45,0, 360, color, 1, LINE_8, 0);
	//ellipse(src, const RotatedRect& box, color, 1, LINE_8);
}

void MyPolygon() {
	Point pts[1][5];
	pts[0][0] = Point(100, 100);
	pts[0][1] = Point(100, 200);
	pts[0][2] = Point(200, 200);
	pts[0][3] = Point(200, 100);
	pts[0][4] = Point(100, 100);

	Point pts1[1][5];
	pts1[0][0] = Point(300, 300);
	pts1[0][1] = Point(300, 500);
	pts1[0][2] = Point(500, 500);
	pts1[0][3] = Point(500, 300);
	pts1[0][4] = Point(300, 300);

	const Point * ppts[] = { pts[0]};
	const Point * ppts1[] = { pts1[1] };
	int npt[] = { 5 };
	Scalar color = Scalar(255, 12, 255);
	fillPoly(src, ppts, npt, 1, color, 8,0,Point(10,10));
	fillPoly(src, ppts1, npt, 1, color, 8);
}

void MY_putText()
{
	Scalar color = Scalar(255, 12, 255);
	putText(src, "Hello opencv", Point(40, 500), FONT_HERSHEY_SCRIPT_COMPLEX, 5, color, 1, LINE_8, false);
}
void My_circle()
{
	Scalar color = Scalar(0, 255, 255);
	Point center = Point(src.cols / 2, src.rows / 2);
	circle(src, center, 150, color, 2, 8);
}

void RandomLineDemo() {
	RNG rng(12345);
	Point pt1;
	Point pt2;
	Mat bg = Mat::zeros(src.size(), src.type());
	namedWindow("random line demo", CV_WINDOW_AUTOSIZE);
	for (int i = 0; i < 100000; i++) {
		pt1.x = rng.uniform(0, src.cols);
		pt2.x = rng.uniform(0, src.cols);
		pt1.y = rng.uniform(0, src.rows);
		pt2.y = rng.uniform(0, src.rows);
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		if (waitKey(50) > 0) {
			break;
		}
		line(bg, pt1, pt2, color, 1, 8);
		imshow("random line demo", bg);
	}
}