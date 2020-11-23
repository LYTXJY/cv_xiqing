#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>
#include <random>

using namespace std;
using namespace cv;

void image_opt(Mat image);
void traverse_pixel(Mat image);


int main(int argc, char ** argv)
// int main(int argc, char * argv[])
{
    char * imagename  = argv[1];
    Mat image = imread(imagename, 3);
    Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
    image_opt(image);
    image_opt(gray_image);


    namedWindow("3");
    imshow("3", image);
    namedWindow("1");
    imshow("1", gray_image);


    // traverse_pixel(image);
    traverse_pixel(gray_image);

    waitKey(0);
    destroyAllWindows();
    return 0;
}

void image_opt(Mat img)
{

    // namedWindow(img);
    // imshow(img, image);

}

void traverse_pixel(Mat image)
{
    std::default_random_engine e;
    std::uniform_int_distribution<int> randomrow(0,image.rows-1);
    std::uniform_int_distribution<int> randomcol(0,image.cols-1);


    Mat test_im = image.clone();
    for(int i=0;i<test_im.rows;i++)
    {
        uchar * ptr = test_im.data + i * test_im.step;
        // cout << ptr<<endl;
        for(int j=0;j<test_im.step;j++)
        {
            *(ptr + j) = i%255;
        }
    }
    namedWindow("test");
    imshow("test",test_im);

    if(image.type() == CV_8UC1)
    {
        Scalar intersity = test_im.at<uchar>(0,0);
        cout << "intersity" << intersity <<endl;
    }
    else if(image.type() == CV_8UC3)
    {
        Scalar intersity = test_im.at<Vec3b>(100,100);
        uchar blue = intersity.val[0];
        uchar green = intersity.val[1];
        uchar red = intersity.val[2];
        cout << "blue" << blue <<endl;
        cout << "green" << green <<endl;
        cout << "red" << red <<endl;

    }

}




