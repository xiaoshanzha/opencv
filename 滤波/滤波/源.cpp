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

	blur(src, dst, Size(11, 11), Point(-1, -1));  //均值滤波
	imshow(output_title, dst);

	Mat gblur;
	//倒二参数：高斯核函数在X方向上的标准偏差
	//最后参数：高斯核函数在Y方向上的标准偏差
	GaussianBlur(src, gblur, Size(11, 11), 1, 11);    //高斯滤波
	imshow("gaussian blur", gblur);


	//第三个参数：表示在过滤过程中每个像素邻域的直径范围
	//第四个参数：颜色空间过滤器的sigma值，这个参数的值越大，表明该像素邻域内有越宽广的颜色会被混合到一起，产生较大的半相等颜色区域
	//第五个参数：坐标空间中滤波器的sigma值，如果该值较大，则意味着颜色相近的较远的像素将相互影响，从而使更大的区域中足够相似的颜色获取相同的颜色。
	
	bilateralFilter(src, biimage, 15, 50, 5);  //双边滤波  权重在边界有很明显的分界，从而几乎只对自己所属的边缘一侧的像素点进行加权。是边界得到很好的保留，非边界更加平滑
	namedWindow("BiBlur Filter Result", CV_WINDOW_AUTOSIZE);   //可以达到保边去噪的目的
	imshow("BiBlur Filter Result", biimage);

	waitKey(0);
	return 0;
}