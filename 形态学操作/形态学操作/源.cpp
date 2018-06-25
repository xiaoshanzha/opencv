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

	// 水平结构元素
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 16, 1), Point(-1, -1));
	// 垂直结构元素
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16), Point(-1, -1));
	// 矩形结构
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3), Point(-1, -1));


	//开操作：先腐蚀后膨胀。具有消除细小物体，在纤细处分离物体和平滑较大物体边界的作用。
//	morphologyEx(src, dst, CV_MOP_OPEN, kernel);


	//闭操作，先膨胀后腐蚀。具有填充物体内细小空洞，连接邻近物体和平滑边界的作用。
	//morphologyEx(src, dst, CV_MOP_CLOSE, kernel);

	//形态学梯度=基本梯度：用膨胀后的图像减去腐蚀后的图像得到差值图像，可以用形态学梯度来突出边缘，保留物体的边缘轮廓。
	morphologyEx(src, dst, CV_MOP_GRADIENT, kernel);

	//顶帽：原图与开运算结果图之差。开运算放大了裂缝或者局部低亮度的区域，所以，从原图中减去开运算后的图，得到的结果突出了比原图轮廓周围的区域更明亮的区域，
//	morphologyEx(src, dst, CV_MOP_TOPHAT, kernel);

	//黑帽运算：闭运算的结果与原图之差。突出了比原图轮廓周围区域更暗的区域，所以黑帽运算用来分离比邻近点暗一些的斑块
	//morphologyEx(src, dst, CV_MOP_BLACKHAT, kernel);

	imshow(output_title, dst);

	//提取水平与垂直线：1.输入图像彩色图像 2.转换为灰度图像 3.转换为二值图像 4.定义结构元素 5.开操作提取水平与垂直线

	//利用矩形结构元素 可以分离出 细线干扰下的较粗字体

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