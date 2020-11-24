/*
随机生成器和opencv文本
*/



#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <random>

using namespace std;
using namespace cv;

int Drawing_Random_Lines(Mat image, char * window_name, RNG rng);
int Drawing_Random_Lines(Mat image, char * window_name, RNG rng)
{
    int lineType = 8;
    Point pt1, pt2;
    for (int i = 0 ; i < NUMBER; i++)
    {
        pt1.x = rng.uniform(x_1, x_2);
        pt1.y = rng.uniform(y_1, y_2);
        pt2.x = rng.uniform(x_1, x_2);
        pt2.y = rng.uniform(y_1, y_2);
        line(image, pt1, pt2, randomColor(rng), rng.uniform(1,10),8);
        imshow(window_name, image);
        if(waitKey(DELAY) >= 0){return -1;}
    }
    return 0;
}
int main()
{
    // RNG : random number generator:随机数字生成器
    RNG rng( 0xFFFFFFFF);

    int window_height = 256;
    int window_width = 576;
    Mat image = Mat::zeros(window_height, window_width, CV_8UC3);
    namedWindow("windowname",WINDOW_AUTOSIZE);
    imshow("windowname", image);

    /*
    翻译过来就是 ：此声明没有存储类或类型说明符，
    出错的原因：在函数外对全局变量赋值
    */

    c = Drawing_Random_Lines（image，window_name，rng）;
    if（c！= 0）return 0;
    c = Drawing_Random_Rectangles（image，window_name，rng）;
    if（c！= 0）return 0;
    c = Drawing_Random_Ellipses（image，window_name，rng）;
    if（c！= 0）return 0;
    c = Drawing_Random_Polylines（image，window_name，rng）;
    if（c！= 0）return 0;
    c = Drawing_Random_Filled_Polygons（image，window_name，rng）;
    if（c！= 0）return 0;
    c = Drawing_Random_Circles（image，window_name，rng）;
    if（c！= 0）return 0;
    c = Displaying_Random_Text（image，window_name，rng）;
    if（c！= 0）return 0;
    c = Displaying_Big_End（image，window_name，rng）;

   putText（image，“testing text rendering”，org，rng.uniform（0,8），rng.uniform（0,100）* 0.05 + 0.1，randomColor（rng），rng.uniform（1,10），lineType）;

}



static Scalar randomColr(RNG &rng)
{
    int icolor = (unsigned) rng;
    return Scalar (icolor & 255, (icolor>>8)&255, (icolor>>16)&255);
}

int Displaying_Random_Text( Mat image, char* window_name, RNG rng )
{
  int lineType = 8;
  for ( int i = 1; i < NUMBER; i++ )
  {
    Point org;
    org.x = rng.uniform(x_1, x_2);
    org.y = rng.uniform(y_1, y_2);
    putText( image, "Testing text rendering", org, rng.uniform(0,8),
             rng.uniform(0,100)*0.05+0.1, randomColor(rng), rng.uniform(1, 10), lineType);
    imshow( window_name, image );
    if( waitKey(DELAY) >= 0 )
      { return -1; }
  }
  return 0;
}

