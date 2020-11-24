/*
opencv 基本绘图

分区:
    scalar:标量
    scale:规模
*/

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

#define w 400

void MyEllipse(cv::Mat img, double angle);
void MyFilledCircle(cv::Mat img, cv::Point center);
void MyPolygon(Mat img);
void MyLine(Mat img, Point start, Point end);

int main(){
    char atom_window[] = "drawing 1:atom";
    char rook_window[] = "drawing 2:rook";
    Mat atom_image = Mat::zeros(w,w,CV_8UC3);
    Mat rook_image = Mat::zeros(w,w,CV_8UC3);
    
    MyEllipse(atom_image, 90);
    MyEllipse(atom_image, 0);
    MyEllipse(atom_image, 45);
    MyEllipse(atom_image, -45);//四条椭圆
    
    MyFilledCircle(atom_image, Point(w/2, w/2));//圆形

    MyPolygon(rook_image);//多边形

    rectangle(rook_image,
            Point(0, 7* w /8),
            Point(w, w),
            Scalar(0, 255,255),
            FILLED,
            LINE_8);//矩形

  MyLine( rook_image, Point( 0, 15*w/16 ), Point( w, 15*w/16 ) );
  MyLine( rook_image, Point( w/4, 7*w/8 ), Point( w/4, w ) );
  MyLine( rook_image, Point( w/2, 7*w/8 ), Point( w/2, w ) );
  MyLine( rook_image, Point( 3*w/4, 7*w/8 ), Point( 3*w/4, w ) );//画线

  imshow( atom_window, atom_image );
  moveWindow( atom_window, 0, 200 );
  imshow( rook_window, rook_image );
  moveWindow( rook_window, w, 200 );
  waitKey( 0 );

    return 0;
}


void MyEllipse(cv::Mat img, double angle)
{
    int thickness = 2;//thickness : 厚度
    int lineType = 8;
    ellipse(
        img,
        Point(w/2,w/2),
        Size(w/4,w/16),
        angle,
        0,360,
        Scalar(255,0,0),
        thickness,lineType
    );
}
void MyFilledCircle(cv::Mat img, cv::Point center)
{
    circle(
        img,
        center,
        w/32,
        Scalar(0,0,255),
        FILLED,
        LINE_8
    );
}
void MyPolygon(Mat img)
{

    int lineType = LINE_8;
    Point rook_points[1][20];
    rook_points[0][0]  = Point(    w/4,   7*w/8 );
    rook_points[0][1]  = Point(  3*w/4,   7*w/8 );
    rook_points[0][2]  = Point(  3*w/4,  13*w/16 );
    rook_points[0][3]  = Point( 11*w/16, 13*w/16 );
    rook_points[0][4]  = Point( 19*w/32,  3*w/8 );
    rook_points[0][5]  = Point(  3*w/4,   3*w/8 );
    rook_points[0][6]  = Point(  3*w/4,     w/8 );
    rook_points[0][7]  = Point( 26*w/40,    w/8 );
    rook_points[0][8]  = Point( 26*w/40,    w/4 );
    rook_points[0][9]  = Point( 22*w/40,    w/4 );
    rook_points[0][10] = Point( 22*w/40,    w/8 );
    rook_points[0][11] = Point( 18*w/40,    w/8 );
    rook_points[0][12] = Point( 18*w/40,    w/4 );
    rook_points[0][13] = Point( 14*w/40,    w/4 );
    rook_points[0][14] = Point( 14*w/40,    w/8 );
    rook_points[0][15] = Point(    w/4,     w/8 );
    rook_points[0][16] = Point(    w/4,   3*w/8 );
    rook_points[0][17] = Point( 13*w/32,  3*w/8 );
    rook_points[0][18] = Point(  5*w/16, 13*w/16 );
    rook_points[0][19] = Point(    w/4,  13*w/16 );
    const Point* ppt[1] = { rook_points[0] };
    int npt[] = { 20 };
    fillPoly( img,
        ppt,
        npt,
        1,
        Scalar( 255, 255, 255 ),
        lineType );
}
void MyLine(Mat img, Point start, Point end)
{
  int thickness = 2;
  int lineType = LINE_8;
  line( img,
    start,
    end,
    Scalar( 0, 0, 0 ),
    thickness,
    lineType );
}