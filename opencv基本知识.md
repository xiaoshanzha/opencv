* Mat 矩阵中data、size等属性:
```
data : uchar类型的指针，指向Mat数据矩阵的首地址。
dims : Mat矩阵的维度，若Mat是一个二维矩阵，则dims=2，三维则dims=3
rows : Mat矩阵的行数。
cols : Mat矩阵的列数。
size() : size是一个结构体，定义了Mat矩阵内数据的分布形式，数值上有关系式：
         image.size().width=image.cols;        
         image.size().height=image.rows;
channels()：Mat矩阵元素拥有的通道数。
            eg: 常见的RGB彩色图像，channels=3；
                而灰度图像只有一个灰度分量信息,channels=1。
```
---
* 加载、显示、修改、保存图像
```
加载：imread()函数

Mat src;
src = imread("图像文件名",int flag);
flag > 0 返回一个3通道的彩色图像
flag = 0 返回的是灰度图像
flag < 0 返回包含Alpha通道的加载图像，即对图像不做任何处理
```
```
显示：imshow()函数

imshow("窗口名称", src);
src即要显示的Mat图像名称
```
```
修改(颜色空间转换)：cvtColor()函数

void cvtColor(InputArray src, OutputArray dst, int code, int dstCn = 0)
第一个参数是输入图像，第二个是输出图像，第三个整形量为颜色空间转换的标识，第四个参数是转换后的通道数，如果该参数为0，就取源图像的通道数。

标识符：CV_RGB2GRAY  表示由RGB图像->GRAY灰度图像
```
```
保存：imwrite()函数

imwrite("指定保存的文件名",dst)  
dst为要保存的Mat图片
```
---
* RGB图像通道的排列顺序是BGR, 矩阵表示如下：
![](https://upload-images.jianshu.io/upload_images/10460153-7c06b85c01f2a4ed.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
---
* 读取图像像素
```
1.通过指针访问
uchar* data = image.ptr<uchar>(row)  通过ptr函数获取图像第row行像素的首地址
data[j]  获取第row行中第i列的像素值
2.单通道直接读取
int value = src.at<uchar>(row, col);
3.三通道直接读取
int b = src.at<Vec3b>(row, col)[0];
int g = src.at<Vec3b>(row, col)[1];
int r = src.at<Vec3b>(row, col)[2];
gray_src.at<uchar>(row, col) = max(r, max(b, g)); //取三通道图中像素最大值赋值给灰度图像素；

Vec3b对应三通道的顺序是blue、green、red的uchar类型数据
Vec3f对应三通道的float类型数据
```
---
* 溢出保护函数 调整像素范围
```
确保RGB值的范围在0~255之间
saturate_cast<uchar> (-100) 返回0
saturate_cast<uchar> (288) 返回255
saturate_cast<uchar> (100) 返回100  
```
---

* Mat对象
```
创建大小类型相同的对象：
Mat dst = Mat(src.size(), src.type());
dst.create(src.size(), src.type());
```
```
复制：
Mat dst = src.clone()
src.copyTo(dst);
```
```
三通道像素赋值
Mat dst = Scalar(x1, x2, x3) 
表示所有像素值均为(x1,x2,x3)
```
```
创建100 * 100的像素都为(0，0，255)的Mat:
Mat M(100, 100, CV_8UC3, Scalar(0, 0, 255))
```
---
* Mat矩阵对应的数据类型
```
CV_[位数][带符号与否][类型前缀]C[通道数] 
eg：CV_8UC3 表示使用8位的unsigned char型，每个像素由3个元素组成三通道
float 是32位的，对应CvMat数据结构参数就是：CV_32FC1，CV_32FC2，CV_32FC3
double是64bits，对应CvMat数据结构参数：CV_64FC1，CV_64FC2，CV_64FC3。
```
---
* 矩阵数据类型的转换
```
void convertTo( OutputArray m, int rtype, double alpha=1, double beta=0 ) 
```
 对应参数：
```
m ： 目标矩阵。如果m在运算前没有合适的尺寸或类型，将被重新分配。
rtype ： 目标矩阵的类型。因为目标矩阵的通道数与源矩阵一样，所以rtype也可以看做是目标矩阵的位深度。如果rtype为负值，目标矩阵和源矩阵将使用同样的类型。
alpha : 尺度变换因子（可选）。
beta : 附加到尺度变换后的值上的偏移量（可选）。

函数将源矩阵中的像素值转换为目标类型。最后会使用溢出保护函数saturate_cast<> ，以避免转换过程中可能出现的溢出。函数执行如下运算：
m(x,y) = saturate_cast<rtype> (α*(x,y)+β); 
```
---
* 图像的线性混合(or图像叠加)：
```
g(x) = (1 - α)*f1(X) + α*f2(x)   α的取值范围为0~1之间
相关API : addWeighted(src1, α, src2, β, gamma, dst, dtype = -1)
(两张图像的大小和类型必须一致才可以使用) 
参数1：输入图像src1;
参数2：src1所占的权值α
参数3：输入图像src2;
参数4: src2所占的权值β
参数5 : 常数项，进行微调
参数6：输出的混合图像
dst(I) = saturate(src1(I)*α + src2(I)*β + gamma); 保证像素在0~255之间
```
---
