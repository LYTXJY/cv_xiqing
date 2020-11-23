// /*

// opencv 混合两个图像
// 重磅! 
// CV大佬Szeliski新书《计算机视觉：算法与应用(第二版)》



#include <opencv2/opencv.hpp> 
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;



int main( void )
{
   double alpha = 0.5; double beta; double input;
   Mat src1, src2, dst;
   cout << " Simple Linear Blender " << endl;
   cout << "-----------------------" << endl;
   cout << "* Enter alpha [0-1]: ";
   cin >> input;
   // We use the alpha provided by the user if it is between 0 and 1
   if( input >= 0 && input <= 1 )
     { alpha = input; }
   src1 = imread( "../1.png" );
//警告
// 由于我们添加 src1和src2，它们必须具有相同的大小（宽和高）和类型。

    int rows = src1.rows;
    int columns = src1.cols;
    src2 = imread( "../2.png" );

    Mat src2_resize;
    // resize(src2, );
    resize(src2, src2_resize, cv::Size(columns, rows));//缩放图像
    

   if( src1.empty() ) { cout << "Error loading src1" << endl; return -1; }
   if( src2.empty() ) { cout << "Error loading src2" << endl; return -1; }
   beta = ( 1.0 - alpha );
//    addWeighted( src1, alpha, src2, beta, 0.0, dst);
   addWeighted( src1, alpha, src2_resize, beta, 0.0, dst);
   /*
   
   addWeighted参数说明:
   src1:待融合图像1
   alpha:图像1融合参数
   src2:待融合图像2
   beta:图像2融合参数,alpha+beta = 1
   0.0:gamma，图1与图2作和后添加的数值。不要太大，不然图片一片白。
   总和等于255以上就是纯白色了。
   dst:输出图片

   */
   imshow( "Linear Blend", dst );
   waitKey(0);
   return 0;
}