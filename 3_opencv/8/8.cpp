// //opencv 核心功能 2
// //扫描图像,查找表格与时间测量

// //opencv 核心功能 3
// //掩码
// /*

// 根据掩码矩阵(也叫内核)重新计算图像中的每个像素值

// */

#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;


void Sharpen(const Mat & myImage, Mat & Result)
{
    CV_Assert(myImage.depth() == CV_8U);//accept  only uchar images
    //2** 8,最大255
    const int nChannels = myImage.channels();
    Result.create(myImage.size(), myImage.type());
    // for(int j = nChannels;j<nChannels *(myImage.rows -1); ++j)
    for(int j = 1;j<myImage.rows -1; ++j)
    {
        const uchar * previous = myImage.ptr<uchar> (j- 1);
        //前一行
        const uchar * current = myImage.ptr<uchar> (j);
        //当前行
        const uchar * next = myImage.ptr<uchar> (j + 1);
        //下一行

        uchar * output = Result.ptr<uchar>(j);
        for(int i = nChannels;i<nChannels*(myImage.cols -1);++i)
        {
            *output++ = saturate_cast<uchar>(5*current[i]-current[i-nChannels]-current[i+nChannels]-previous[i]-next[i]);
        }
    }
    Result.row(0).setTo(Scalar(0)); //row得到一行的矩阵头 
    //setto将元素不为0的点全部变为value值
    Result.row(Result.rows -1).setTo(Scalar(0));
    Result.col(0).setTo(Scalar(0));
    Result.col(Result.cols -1).setTo(Scalar(0));



    Mat kernel = (Mat_<char>(3,3) << 0,-1,0,
                                    -1,5,-1,
                                    0,-1,0);
    
    // filter2D(src, dst1, src.depth(), kernel);
    // filter2D(myImage, Result, myImage.depth(), kernel);s



}

void visual_creat()
{
    Mat m;
    m.create(4,4,CV_8UC1);
    cout << "m = "<< endl <<""<< m <<endl;
    m.ptr<uchar>(0)[0] = 12;//()[]使用两种符号区分行与列,
    m.ptr<uchar>(0)[1] = 32;
    m.ptr<uchar>(3)[3] = 13;
    m.ptr<uchar>(4)[3] = 52;//越界不报错?厉害,
    m.ptr<uchar>(4)[3] = 5200;//越界不报错?厉害,
    //注意 :uchar(unsigned char) 是无符号的,8-bit无符号整形数据
    //char 整数范围为-128到127( 0x80__0x7F) 而unsigned char 整数范围为0到255

    /*
    常用形式:
    mat.ptr<type>(row)[col]

    对于Mat的ptr函数，返回的是<>中的模板类型指针，指向的是()中的第row行的起点
    通常<>中的类型和Mat的元素类型应该一致
    然后再用该指针去访问对应col列位置的元素 
    
    */
    cout << "m = "<< endl <<""<< m <<endl;

    m.create(4,4,CV_8UC1);
    cout << "m = "<< endl <<""<< m <<endl;
    m.create(3,3,CV_8UC1);
    cout << "m = "<< endl <<""<< m <<endl;
    m.create(5,5,CV_8UC1);
    cout << "m = "<< endl <<""<< m <<endl;
}


int main()
{
    visual_creat();
    
    
    Mat img = imread("../1.jpg");
    Mat res;
    namedWindow("origin",WINDOW_AUTOSIZE);
    imshow("origin", img);
    Sharpen(img, res);
    namedWindow("sharpen", WINDOW_AUTOSIZE);
    imshow("sharpen", res);
    waitKey(0);
    destroyAllWindows();


    return 0;
}












// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/highgui.hpp>
// #include <opencv2/imgproc.hpp>
// #include <iostream>

// using namespace std;
// using namespace cv;

// static void help(char* progName)
// {
//     cout << endl
//         <<  "This program shows how to filter images with mask: the write it yourself and the"
//         << "filter2d way. " << endl
//         <<  "Usage:"                                                                        << endl
//         << progName << " [image_path -- default lena.jpg] [G -- grayscale] "        << endl << endl;
// }


// void Sharpen(const Mat& myImage,Mat& Result);

// int main( int argc, char* argv[])
// {
//     help(argv[0]);
//     const char* filename = argc >=2 ? argv[1] : "lena.jpg";

//     Mat src, dst0, dst1;

//     if (argc >= 3 && !strcmp("G", argv[2]))
//         src = imread( samples::findFile( filename ), IMREAD_GRAYSCALE);
//     else
//         src = imread( samples::findFile( filename ), IMREAD_COLOR);

//     if (src.empty())
//     {
//         cerr << "Can't open image ["  << filename << "]" << endl;
//         return EXIT_FAILURE;
//     }

//     namedWindow("Input", WINDOW_AUTOSIZE);
//     namedWindow("Output", WINDOW_AUTOSIZE);

//     imshow( "Input", src );
//     double t = (double)getTickCount();

//     Sharpen( src, dst0 );

//     t = ((double)getTickCount() - t)/getTickFrequency();
//     cout << "Hand written function time passed in seconds: " << t << endl;

//     imshow( "Output", dst0 );
//     waitKey();

//   //![kern]
//     Mat kernel = (Mat_<char>(3,3) <<  0, -1,  0,
//                                    -1,  5, -1,
//                                     0, -1,  0);
//   //![kern]

//     t = (double)getTickCount();

//   //![filter2D]
//     filter2D( src, dst1, src.depth(), kernel );
//   //![filter2D]
//     t = ((double)getTickCount() - t)/getTickFrequency();
//     cout << "Built-in filter2D time passed in seconds:     " << t << endl;

//     imshow( "Output", dst1 );

//     waitKey();
//     return EXIT_SUCCESS;
// }
// //! [basic_method]
// void Sharpen(const Mat& myImage,Mat& Result)
// {
//   //! [8_bit]
//     CV_Assert(myImage.depth() == CV_8U);  // accept only uchar images
//   //! [8_bit]

//   //! [create_channels]
//     const int nChannels = myImage.channels();
//     Result.create(myImage.size(),myImage.type());
//   //! [create_channels]

//   //! [basic_method_loop]
//     for(int j = 1 ; j < myImage.rows-1; ++j)
//     {
//         const uchar* previous = myImage.ptr<uchar>(j - 1);
//         const uchar* current  = myImage.ptr<uchar>(j    );
//         const uchar* next     = myImage.ptr<uchar>(j + 1);

//         uchar* output = Result.ptr<uchar>(j);

//         for(int i= nChannels;i < nChannels*(myImage.cols-1); ++i)
//         {
//             *output++ = saturate_cast<uchar>(5*current[i]
//                          -current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
//         }
//     }
//   //! [basic_method_loop]

//   //! [borders]
//     Result.row(0).setTo(Scalar(0));
//     Result.row(Result.rows-1).setTo(Scalar(0));
//     Result.col(0).setTo(Scalar(0));
//     Result.col(Result.cols-1).setTo(Scalar(0));
//   //! [borders]
// }
// //! [basic_method]
