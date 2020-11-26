// #include<opencv2/opencv.hpp>


// using namespace cv;
// int main()
// {
    
//     Mat srcImage=imread("1.jpg");
//     imshow("Origin",srcImage);
//     waitKey(0);
//     return 0;
// }







/*


g++ -std=c++11 3.cpp -o main_dle `pkg-config --cflags --libs opencv4`
*/

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char ** argv)
{


    if(argc != 2)
    {
        printf("usage : DisplayImage.out <Image_Path>\n");
        return -1;//约定俗成, -1表示失败
    }
    Mat image;
    image = imread(argv[1], 1);
    if(!image.data)
    {

        printf("No image data \n");
        return -1;
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);


    return 0;//约定俗成, 0表示成功
}

// g++ -std=c++11 test.cpp -o test `pkg-config --cflags --libs opencv4` 