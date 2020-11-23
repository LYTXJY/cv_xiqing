#include <opencv2/core.hpp>
/*
core.hpp
核心部分:定义库的基本构建块儿
*/
#include <opencv2/imgcodecs.hpp>

#include <opencv2/highgui.hpp>
/*
highgui:输入输出操作功能
*/
#include <iostream>
//控制台输入输出操作功能
#include <string>

using namespace cv;
using namespace std;

int main(int argc , char ** argv)
{

    String imageName("../1.jpg");
    if (argc > 1)
    {
        imageName = argv[1];
    }
    Mat image;
    image = imread(imageName, IMREAD_COLOR);
    /*
    IMREAD_COLOR:彩色
    IMREAD_GRAY:灰度
    IMREAD_UNCHANGED:原样加载图像


    图片格式一览:
    bmp:    windows位图
    pbm,pgm,ppm:    便携式图像格式
    sr,ras: 光栅
    JPEG(jpeg,jpg,jpe):
    JPEG 2000:
    TIFF(tiff,tif):
    png:    便携式网络图像

    */
    if(image.empty())
    {
        cout << "could not open or find the image" <<std::endl;
        return -1;
    }

    namedWindow("Display Window",WINDOW_AUTOSIZE);
    imshow("Display Window", image);
    waitKey(0);
    /*
    
    因为我们希望我们的窗口被显示直到用户按下一个键
    （否则程序会结束太快），
    所以我们使用cv :: waitKey函数，
    其唯一的参数是等待用户输入需要多长时间毫秒）。
    零意味着永远等待。
    */
    return 0;
}