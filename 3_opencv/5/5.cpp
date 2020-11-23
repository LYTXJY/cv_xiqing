/*

像素点所有强度值的矩阵

这样做的问题是它带来了C语言的所有缺点。最大的问题是手动内存管理。
    它建立在用户负责处理内存分配和释放的假设的基础上。
    虽然这不是一个较小的程序的问题，但一旦你的代码基础的增长，
        处理这些代码就更难，而不是专注于解决你的发展目标。

幸运的是C ++来了，并介绍了类的概念，
    使用户更容易通过自动内存管理（或多或少）。

OpenCV是一个图像处理库。它包含大量的图像处理功能。
为了解决计算挑战，大多数时候你最终会使用库的多个功能。
因此，将图像传递给功能是常见的做法。


这个想法是每个Mat对象都有自己的头，
但是通过使它们的矩阵指针指向相同的地址，
矩阵可以在它们的两个实例之间共享。
此外，复制操作符只会将头和指针复制到大矩阵，而不是数据本身。
*/

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int main(int argc , char** argv)
{
    Mat A, C;
    A = imread(argv[1], IMREAD_COLOR);

    Mat B(A);
    C = A;

/*
所有上述对象，最后指向相同的单个数据矩阵。
然而，它们的头部是不同的，
并且使用它们中的任何一个进行修改也会影响所有其他的。
*/


    Mat F = A.clone();
    Mat G;
    A.copyTo(G);
    /*
    有时你也想复制矩阵本身
        所以OpenCV提供了
        cv :: Mat :: clone（）和
        cv :: Mat :: copyTo（）函数。
    现在修改F或G不会影响Mat头指向的矩阵
    */


   /*
   色彩空间:

   HSV,HLS:色调,饱和度,亮度

   基本数据类型:
    浮点:float  4个字节 4*8=32位(b,比特)
    双精度:double   8个字节 8*8 = 64位(b, 比特)
   */


  /*
  虽然Mat作为一个图像容器非常好，但它也是一个通用的矩阵类。
  因此，可以创建和操纵多维矩阵。您可以通过多种方式创建Mat对象：
  */

    Mat M(2,4,CV_8UC3,Scalar(0,0,255));//scalar:标量
    /*
    
    2,4是大小
    2行
    4列


    指定用于存储元素的数据类型和每个矩阵点的通道数
    CV_
    [The number of bits per item]
    [Signed or Unsigned]
    C[Type Prefix]
    [The channel number]
    
    CV_8UC3:意味着我们使用8位长的无符号字符类型，
        每个像素有三个形成三个通道。
    */
    std::cout <<"M = "<<std::endl<<""<<M<<std::endl;

    M.create(2,3, CV_8UC(2));
    std::cout <<"M = "<<std::endl<<""<<M<<std::endl;

    
    
    
    Mat E = Mat :: eye(4,4,CV_64F);
    std::cout <<"E = "<<std::endl<<""<<E<<std::endl;

    Mat O = Mat :: ones(2,2,CV_32F);
    std::cout <<"O = "<<std::endl<<""<<O<<std::endl;

    Mat Z = Mat :: zeros (3,3 , CV_8UC1);
    std::cout <<"Z = "<<std::endl<<""<<Z<<std::endl;


    Mat R = Mat(3, 2, CV_8UC3);
    randu (R, Scalar :: all(0), Scalar::all(255));
    std::cout <<"R (default)= :" <<std::endl<< R<< std::endl;
    std::cout <<"R (python)= :" <<std::endl<< format(R,Formatter::FMT_PYTHON)<< std::endl;
    std::cout <<"R (CSV)= :" <<std::endl<< format(R,Formatter::FMT_CSV)<< std::endl;
    std::cout << "R(numpy): "<< std::endl<<""<<format(R,Formatter::FMT_NUMPY) <<std::endl;
    std::cout << "R (C) : " << std::endl << "" <<format(R, Formatter::FMT_C) <<std::endl;
    std::cout << "R(MATLAB):" <<std::endl << "" << format(R, Formatter::FMT_MATLAB)<<std::endl; 

    //2d point

    Point2f P (5,1);
    std :: cout <<"point 2d = " << P <<std::endl;

    Point3f P3f (2,6,7);
    std::cout << "P3f = "<< P3f<< std::endl;

    std::vector<float> vPoints(20);
    // for (size_t i = 0; i < vPoints.size() ; i ++)

    //     vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));

    // std::cout << "a vector of 2d points = "<<vPoints <<std::endl;
    
    
    
    
    
    
    return 0;
}