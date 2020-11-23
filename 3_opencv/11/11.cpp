/*
改变对比度与亮度



色调（H），饱和度（S），明度（V）。

    Hue, Saturation, Value 
*/
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <random>


using namespace std;
using namespace cv;


int main(int argc, char ** argv)
{

    double alpha = 1.0;
    int beta = 0;
/*
g(i, j) = a*f(i, j) + b
以下代码执行：g(i,j)=α⋅f(i,j)+β

< Simple contrast control 
< Simple brightness control 
*/

    String imageName = ("../1.png");
    if (argc > 1)
    {
        imageName = argv[1];
    }
    Mat image = imread(imageName);
    Mat new_image = Mat::zeros(image.size(),image.type());
    
    cout << "basic linear transforms"<<endl;
    cout << "-----------------"<<endl;
    cout << "* enter the alpha value [1.0-3.0]: "; cin >> alpha;
    cout << "*enter the beta value [0-100]: ";cin >> beta;

    for (int y =0; y< image.rows ; y++){
        for(int x = 0;x<image.cols;x++){
            for(int c = 0;c < 3;c++){
                new_image.at<Vec3b>(y, x)[c] = 
                saturate_cast<uchar>(alpha * (image.at<Vec3b>(y,x)[c])+
                beta);
                /*
                saturate_cast函数的作用即是：
                当运算完之后，结果为负，则转为0，结果超出255，则为255。
                */
            }
        }
    }
    namedWindow("origin", WINDOW_AUTOSIZE);
    namedWindow("new", WINDOW_AUTOSIZE);
    imshow("origin", image);
    imshow("new", new_image);

    waitKey(0);
    // destroyAllWindows();

    return 0;


}