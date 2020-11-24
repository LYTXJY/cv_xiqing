/*
离散傅里叶变换
*/

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static void help(char * progName)
{
    cout << endl
         << "this program demonstrated the use of the discrete fourier transform(DFT). "<<endl
         << "the dft of an imageis taken and it`s power spectrum is displayed. " << endl
         <<"usage : " << endl
         <<progName << " [image_name -- default ../data/lena,jpg]" << endl << endl;
}

int main(int argc, char ** argv)
{
    help(argv[0]);
    const char * filename = argc >= 2 ?argv[1] : "../data/lena.jpg";

    Mat I = imread(filename, IMREAD_GRAYSCALE);
    if (I.empty())
    {
        return -1;
    }
    Mat padded;//expand input image to optimal size:将输入图像扩展到最优大小
    int m = getOptimalDFTSize(I.rows);
    int n = getOptimalDFTSize(I.cols);// on the border add zero values:在边框上添加零值
    copyMakeBorder(I, padded, 0, m-I.rows, 0, n-I.cols, BORDER_CONSTANT, Scalar::all(0));
}



