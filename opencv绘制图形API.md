##opencv  绘制图形API
[TOC]
####效果展示:

![](https://upload-images.jianshu.io/upload_images/10460153-277e7031c9b7051c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
* 随机线生成效果：

![](https://upload-images.jianshu.io/upload_images/10460153-23172efc7e98370b.gif?imageMogr2/auto-orient/strip)
---

#### 绘制直线
```
void line(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=LINE_8, int shift=0 )
第一个参数 : 背景图片
第二个参数 : 直线的起点
第三个参数 : 直线的终点
第四个参数 : 直线的颜色
第五个参数 : 直线的粗度
第六个参数 : 直线的类型
Type of the line: LINE_8 (or omitted) - 8-connected line.
                  LINE_4 - 4-connected line.
                  LINE_AA - antialiased line.
第七个参数:点坐标中的小数位数
```
---
#### 绘制箭头
```
void arrowedLine(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0, double =0.1)
前几个参数同上
最后一个参数 tipLength ：箭头尖端相对于箭头长度的长度
```
以下是tipLength分别为0.1和0.5的对比:
![](https://upload-images.jianshu.io/upload_images/10460153-7eaf7ada5e06c0eb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)    ![](https://upload-images.jianshu.io/upload_images/10460153-48bf71730bfa527c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---
#### 绘制矩形
```
void rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=LINE_8, int shift=0 )
参数pt1 : 矩形的一个顶点
参数pt2 ：与pt1相对的矩形顶点
```
---
#### 绘制椭圆和弧线
```
void ellipse(InputOutputArray img, Point center, Size axes, double angle, double startAngle, double endAngle, const Scalar& color, int thickness=1, int lineType=LINE_8, int shift=0 )
参数center : 椭圆的中心点
参数axes : 椭圆主轴长的一半;  Size axes1(100, 50)代表长半径为100，短半径为50;
参数angle : 椭圆顺时针旋转的角度
参数startAngle : 椭圆弧的起始角
参数endAngle : 椭圆弧的结束角
角度均为按顺时针所转过的角度
*** 绘制弧线即 起始角与结束角相差小于360度的椭圆
```
---
#### 绘制圆形
```
void circle(InputOutputArray img, Point center, int radius, const Scalar& color, int thickness=1, int lineType=LINE_8, int shift=0 )
参数center : 即圆的圆心;
参数radius : 圆的半径;
```
---
#### 绘制实心多边形
```
void fillPoly(Mat& img, const Point** pts, const int* npts, int ncontours, const Scalar& color, int lineType=LINE_8, int shift=0, Point offset=Point() )
参数pts : 多边形的数组，其中每个多边形表示为点的数组
参数npts : 多边形顶点计数器数组
参数ncontours : 绑定填充区域的轮廓数
参数offset : 轮廓的所有点的可选偏移(可直接忽略)
```
---
#### 在图像中加入文本
```
void putText(InputOutputArray img, const String& text, Point org, int fontFace, double fontScale, Scalar color, int thickness=1, int lineType=LINE_8, bool bottomLeftOrigin=false )
参数text : 要显示的文本内容
参数org : 显示文本的左角
参数fontFace : 字型 eg : FONT_HERSHEY_SIMPLEX , FONT_HERSHEY_PLAIN, FONT_HERSHEY_DUPLEX, FONT_HERSHEY_COMPLEX, FONT_HERSHEY_TRIPLEX, FONT_HERSHEY_COMPLEX_SMALL, FONT_HERSHEY_SCRIPT_SIMPLEX, or FONT_HERSHEY_SCRIPT_COMPLEX,
参数fontScale : 字体大小
参数bottomLeftOrigin : 为真时，图像数据原点位于左下角。否则，它在左上角。
```
---
####随机线生成
```c
void RandomLineDemo() {
	RNG rng(12345);
	Point pt1;
	Point pt2;
	Mat bg = Mat::zeros(bgImage.size(), bgImage.type());
	namedWindow("random line demo", CV_WINDOW_AUTOSIZE);
	for (int i = 0; i < 100000; i++) {
		pt1.x = rng.uniform(0, bgImage.cols);
		pt2.x = rng.uniform(0, bgImage.cols);
		pt1.y = rng.uniform(0, bgImage.rows);
		pt2.y = rng.uniform(0, bgImage.rows);
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		if (waitKey(50) > 0) {
			break;
		}
		line(bg, pt1, pt2, color, 1, 8);
		imshow("random line demo", bg);
	}
}
```
---
####实现代码
```c
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
```

