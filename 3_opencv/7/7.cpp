#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>
#include <random>
#include <unistd.h>
// #


using namespace std;
using namespace cv;


void image_base_info(cv::Mat image, int n)
{

    cout <<image.dims<<endl;

    std::default_random_engine e;
    std::uniform_int_distribution<int> randomr(0,image.rows - 1);
    std::uniform_int_distribution<int> randomc(0,image.cols - 1);

    
    for(int i=0;i<100;i++)
    {
        cout<<i<<"----" <<e<<"---"<< endl;
        //单独使用 default_random_engine 显示异常
        //必须搭配uniform_int_distribution使用
        cout<<i<<"----" <<e<<"---"<<randomc(e)<< endl;

        //必须有延迟,否则显示不完整
        // usleep(1000*1000);//usleep单位:微秒
        //1秒bai=1000毫秒(ms)

        // 1秒=1,000,000 微秒(μs)
    }

    int i,j;
    for(int k = 0;k<n; k++)
    {

        i = randomr(e);
        j = randomc(e);

        image.at<Vec3b>(i, j)[0] = 255;
        image.at<Vec3b>(i, j)[1] = 255;
        image.at<Vec3b>(i, j)[2] = 255;
    }

    cout << image.dims<< endl;
    cout << image.rows<< endl;
    cout << image.cols<< endl;
    cout << image.channels()<< endl;
    cout << image.step[0]<< endl;
    cout << image.step[1]<< endl;
    cout << image.elemSize()<< endl;//一个像素点的大小  CV_8U3C=1*3
    cout << image.elemSize1()<< endl;
    //数据类型的大小 UCHAR = 1 （ElemSize / Channel）
    
    Mat test_im = image.clone();
    for (int i=0;i<test_im.rows;i++)
    {
        uchar * ptr = test_im.data + i * test_im.step;//step 是一行的数据长度
        for(int j =0; j< test_im.step;j++)
        {
            *(ptr + j) = i%255;//ptr一行的数据改写为灰度值0~255
            //0是黑,255是白
        }
    }

    namedWindow("test");
    imshow("test",test_im);

    Mat copy_im = image.clone();
    for (int i = 0;i<copy_im.rows; i++)
    {
        for (int j =0;j<copy_im.cols;j++)
        {
            Vec3b pixel;
            //vector<uchar, 3>。
            //简单而言就是一个uchar类型的，长度为3的vector向量。
            pixel[0]=i%255;
            pixel[1]=j%255;
            pixel[2]=0;

            copy_im.at<Vec3b>(i,j) = pixel;

        }
    }
    namedWindow("new");
    imshow("new", copy_im);


    
}

// int main(int argc, char * argv)
int main()
{

    Mat image = imread("../1.png", 1);
    imshow("1", image);

    int n = 5000;
    image_base_info(image, n);

    namedWindow("image", WINDOW_AUTOSIZE);
    imshow("image", image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}

