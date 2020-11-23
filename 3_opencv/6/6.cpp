// //读点
// /*
// row:行
// column:列
// */
// #include <iostream>
// #include <opencv2/core/core.hpp>  
// #include <opencv2/highgui/highgui.hpp>  
// #include "opencv2/imgproc.hpp"
// #include "opencv2/imgcodecs.hpp"


// using namespace std;
// using namespace cv;

// int main()
// {
//     double t;
//     namedWindow("src");
//     namedWindow("dst");

//     Mat src, src2, dst;
//     src = imread("../1.jpg", IMREAD_UNCHANGED);
//     cout <<"src : size = " << src.size()<<endl;
//     cout <<"src : type = " << src.type()<<endl;
//     cout <<"src : data = " << src.data<<endl;
//     //这种方法是错误的,读取不到mat中存储的像素值
//     dst = Mat::zeros(src.size(), src.type());
//     cout << "dst: size= " << dst.size() << endl;
//     cout << "dst: type= " << dst.type() << endl;
//     int channel = src.channels(); //获取图像的通道数量
//     cout << "channel :"<<channel<< endl;

//     float a = 1.5;//对比度
//     int b = 0;//亮度
//     t = (double)getTickCount();
//     //GetTickcount函数：它返回从操作系统启动到当前所经过的毫秒数，
//     //常常用来判断某个方法执行的时间

//     /*
    
// getTickCount()：用于返回从操作系统启动到当前所经的计时周期数，看名字也很好理解，get Tick Count(s)。
// getTickFrequency()：用于返回CPU的频率。get Tick Frequency。这里的单位是秒，也就是一秒内重复的次数。

// 所以剩下的就很清晰了：
// 总次数/一秒内重复的次数 = 时间(s)
// 1000 *总次数/一秒内重复的次数= 时间(ms)

// 这个逻辑很清晰，没什么问题，但是这里有一个小坑，那就是C版本的cvGetTickFrequency()函数和C++版本的getTickFrequency()的单位不一样，前者以ms计算频率，后者以s为单位计算频率，所以如果使用C版本的cvGetTickFrequency()计算时间的话，应该是：
// 总次数/一秒内重复的次数*1000 = 时间(ms)
// 总次数/一秒内重复的次数*1000000 = 时间(s)
//     */

//     //对通道数量不同的图像进行不同处理
//     switch (channel)
//     {
//         case 1:
//             for (int i = 0; i < src.rows; i++)
//                 for (int j = 0; j < src.cols; j++)
//                     dst.at<uchar>(i, j) = saturate_cast<uchar>(a * src.at<uchar>(i, j) + b);
//             break;
//         default://channel ==3
//             cout <<"src.rows:" << src.rows<<endl;
//             cout <<"src.cols:" << src.cols<<endl;
//             for (int i = 0; i < src.rows; i++)//i <= 256
//             {
//                 for (int j = 0; j < src.cols; j++)//j <= 576
//                 {
//                     for (int c = 0; c < src.channels(); c++)//c 0,1,2
//                     {
//                         dst.at<Vec3b>(i, j)[c] = saturate_cast<uchar>(a * src.at<Vec3b>(i, j)[c] + b);//a:对比度, b:亮度
//                         /*
                        
//                         img.at<Vec3b>(row, col)[0] = 255;　　// 这是指修改B通道数据
//                         img.at<Vec3b>(row, col)[1] = 255;　　// 这是指修改G通道数据
//                         img.at<Vec3b>(row, col)[2] = 255;　　// 这是指修改R通道数据   
//                         */
//                         cout << "show me the data : "<< dst.at<Vec3b>(i,j)[c]<< endl;

//                         /*
                        
//                         at<typename>(i,j) 是opencv中图像遍历函数，它是一个模板函数，可以取到任何类型的图像上的点。
//                         image.at<Vec3b>(i,j)[k]：是指取出彩色图像中i行j列第k通道的颜色点。
//                         */

//                     }
//                 }
//             }

//     }

//     t = ((double)getTickCount() - t) / getTickFrequency();
//     cout << t << endl;

//     imshow("src", src);
//     imshow("dst", dst);
//     waitKey(0);
//     return 0;
// }



#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <random>

using namespace std;
using namespace cv;

void salt(cv::Mat image, int n)
{
	std::default_random_engine generator;

	std::uniform_int_distribution<int>
		randomRow(0, image.rows - 1);
	std::uniform_int_distribution<int>
		randomCol(0, image.cols - 1);
	int i, j;
	for (int k = 0; k < n; k++)
	{
		// 随机生成图形位置
		i = randomCol(generator);
		j = randomRow(generator);
		if (image.type() == CV_8UC1)
		{ 
			// 灰度图像
		// 单通道8 位图像
			image.at<uchar>(j, i) = 255;
		}
		else if (image.type() == CV_8UC3) { // 彩色图像
	 // 3 通道图像
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
		}
	}
}
int main()
{
	// 打开图像
	cv::Mat image = cv::imread("../1.jpg", 1);
	// 调用函数以添加噪声
	salt(image, 30000);
	// 显示结果
	cv::namedWindow("Image");
	cv::imshow("Image", image);

	cv::waitKey();
	return 0;
}