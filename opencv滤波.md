## 滤波相关知识
### 图像滤波：
即在尽量保留图像细节特征的条件下对目标图像的噪声进行抑制。（滤波就是要去除没用的信息，保留有用的信息，可能是低频，也可能是高频）

#### 图像的高频和低频
```
色彩剧烈变化的地方，就是图像的高频区域；
色彩稳定平滑的地方，就是低频区域。
```
---
#### 滤波器内核
核(kernel)其实是一组权重，决定了如何利用某一个点周围的像素点来计算新的像素点，核也被称为卷积矩阵，
 核通常是一个二维数组，特征是奇数行、奇数列，中心位置对应着感兴趣的像素，数组每一个元素为整数或者浮点数，相对应值的大小对应其权重，比如：
 ![](https://upload-images.jianshu.io/upload_images/10460153-2896607fa74f339d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
    表明感兴趣的像素值权重为9，相邻区域权重为-1，而计算则为将中心像素值乘以9，减去周围所有的像素，如果感兴趣的像素与周围像素存在差异，则该差异会被放大，达到了锐化的目的。
【注意】权重加起来和为1，这样做的结果是不会改变图像的亮度，如果权重之和为0，则会得到一个边缘检测核，将边缘转为白色，而非边缘区域转为黑色。

---

#### 线性滤波器：
```
（1）低通滤波器(保留低频信号)：使得图像的高频区域变成低频，即色彩变化剧烈的区域变得平滑，也就是出现模糊效果。
    功能：平滑图像，去除噪音
（2）高通滤波器(保留高频信号)：过滤了低频，只保留那些变化最快速最剧烈的区域，也就是图像里面的物体边缘，所以常用于边缘识别。
    功能：边缘增强，边缘提取
（3）带通滤波器：删除特定频率
```
 ---

### 均值滤波：
```
均值滤波器即把邻域内的平均值赋给中心元素

用途 ： 均值滤波器用来降低噪声，去除图像中的不相关细节。模糊图片以便得到感兴趣物体的粗略描述。

缺点 ： 存在着边缘模糊的问题
```
##### 所用卷积核：
![](https://docs.opencv.org/3.0-beta/_images/math/0a3a3decb904a04778cbe67506aa86d2dba618d6.png)
##### 相关API:
```
void blur(InputArray src, OutputArray dst, Size ksize, Point anchor=Point(-1,-1), int borderType=BORDER_DEFAULT )
参数ksize : 内核的大小 eg:Size(3,3)代表内核的大小为3*3的矩阵
参数anchor : 锚点。默认值点(- 1,1)表示锚点位于内核中心。
参数borderType : 用于外推图像外部像素的边框模式，忽略。
```
---
### 高斯模糊
```
在某些情况下，需要对一个像素的周围的像素给予更多的重视。因此，可通过高斯函数的权重分配方案来解决。
权重分配原理 ：分配权重时采取正态分布的模式。越接近中心，取值越大，越远离中心，取值越小。
用途 ：磨皮,毛玻璃效果,背景虚化
(此处可参考博客：http://www.ruanyifeng.com/blog/2012/11/gaussian_blur.html)
```
##### 所用卷积核：
![](https://img-blog.csdn.net/20151009013733783)
##### 相关API:
```
void GaussianBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY=0, int borderType=BORDER_DEFAULT )
参数sigmaX : X方向上的高斯核标准差
参数sigmaY : Y方向上的高斯核标准差;
             sigmaY为0，它被设置为等于sigmaX；
             sigmaY=sigmaX=0时，它们的值将由ksize.width和ksize.height自动确定

高斯矩阵尺寸和标准差越大，处理后的图片越模糊
```
---

#### 非线性滤波器
使用模板进行结果像素值的计算时，结果值直接取决于像素领域的值，而不使用加权和的计算方式。
（1）中值滤波：平滑图像，去除噪音
（2）最大值滤波：寻找最亮点
（3）最小值滤波：寻找最暗点

---

##### 中值滤波
```
基本思想 ：用像素点邻域灰度值的中值来代替该像素点的灰度值，让周围的像素值接近真实的值从而消除孤立的噪声点。
优点 : 对消除椒盐噪声和斑点噪声非常有效，能够克服线性滤波器带来的图像细节模糊等弊端，能够有效保护图像边缘信息，
```
```
void medianBlur(InputArray src, OutputArray dst, int ksize)
```
---
##### 高斯双边滤波
```
用途 ： 可以保边去噪。滤除图像数据中的噪声，且还会保留住图像的边缘、纹理等
```
##### 相关API:
```
void bilateralFilter(InputArray src, OutputArray dst, int d, double sigmaColor, double sigmaSpace, int borderType=BORDER_DEFAULT )
参数d : 过滤过程中使用的每个像素邻域的直径。如果是非正数，则从sigmaSpace计算。
参数sigmaColor ：较大时，则在邻域中的像素值相差较大的像素点也会用来平均。
参数sigmaSpace : 在坐标空间中过滤西格玛。 较大的参数值意味着只要它们的颜色足够接近，更远的像素也会相互影响（参见sigmaColor）。 当d> 0时，无论sigmaSpace如何，它都指定邻域大小。 否则，d与sigmaSpace成比例。
```
![](https://upload-images.jianshu.io/upload_images/10460153-eb2050bf1a759d58.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
