# opencv_c++





- cmake,gcc与opencv

![image-20201120165134713](/home/calmcar/calmcar_xjy/3_opencv/md/opencv_w3c_c++.assets/image-20201120165134713.png)





- 像素级别修改,注意行.列顺序,row行,column列

  image.at<cv::Vec3b>(j, i) [0]

  image.at<cv::Vec3b>(j, i) [1]

  image.at<cv::Vec3b>(j, i) [2]








## data：  

​    uchar类型的指针，指向Mat数据矩阵的首地址。可以理解为标示一个房屋的门牌号；
 

##   dims： 

​    Mat矩阵的维度，若Mat是一个二维矩阵，则dims=2，三维则dims=3，大多数情况下处理的都是二维矩阵，是一     个平面上的矩阵。



​    可以理解为房屋是一个一层的平房，三维或更多维的则是多层楼房；
 

##   rows： 

​    Mat矩阵的行数。可理解为房屋内房间行数；
 

##   cols： 

​    Mat矩阵的列数。可理解为房屋内房间列数；

##   size()： 

​    首先size是一个结构体，定义了Mat矩阵内数据的分布形式，数值上有关系式：



​     image.size().width==image.cols;     image.size().height==image.rows                             

​     可以理解为房屋内房间的整体布局，这其中包括了房间分别在行列上分布的数量信息；
 

##   channels()： 

​    Mat矩阵元素拥有的通道数。例如常见的RGB彩色图像，channels==3；而灰度图像只有一个灰度分量信息，       channels==1。



​    可以理解为每个房间内放有多少床位，3通道的放了3张床，单通道的放了1张床；
 

##   depth： 

​     用来度量每一个像素中每一个通道的精度，但它本身与图像的通道数无关！depth数值越大，精度越高。在          Opencv中，Mat.depth()得到的是一个0~6的数字，分别代表不同的位数，对应关系如下：                



​    enum{CV_8U=0,CV_8S=1,CV_16U=2,CV_16S=3,CV_32S=4,CV_32F=5,CV_64F=6}      

​    其中U是unsigned的意思，S表示signed，也就是有符号和无符号数。

​    可以理解为房间内每张床可以睡多少人，这个跟房间内有多少床并无关系；
 

##   elemSize： 

​     elem是element(元素)的缩写，表示矩阵中每一个元素的数据大小，如果Mat中的数据类型是CV_8UC1，那么        elemSize==1；如果是CV_8UC3或CV_8SC3，那么elemSize==3；如果是CV_16UC3或者CV_16SC3，那么        elemSize==6；即elemSize是以8位（一个字节）为一个单位，乘以通道数和8位的整数倍；



​    可以理解为整个房间可以睡多少人，这个时候就得累计上房间内所有床位数（通道）和每张床的容纳量了；
 

##   elemSize1： 

​    elemSize加上一个“1”构成了elemSize1这个属性，1可以认为是元素内1个通道的意思，这样从命名上拆分后就很     容易解释这个属性了：表示Mat矩阵中每一个元素单个通道的数据大小，以字节为一个单位，所以有： 



​    eleSize1==elemSize/channels；
 

##   step： 

​    可以理解为Mat矩阵中每一行的“步长”，以字节为基本单位，每一行中所有元素的字节总量，是累计了一行中所      有元素、所有通道、所有通道的elemSize1之后的值；

##   step1()： 

​    以字节为基本单位，Mat矩阵中每一个像素的大小，累计了所有通道、所有通道的elemSize1之后的值,所以有：



​    step1==step/elemSize1；
 

##   type： 

​    Mat矩阵的类型，包含有矩阵中元素的类型以及通道数信息，type的命名格式为CV_(位数)+(数据类型)+(通道        数)，所有取值如下

 ![img](/home/calmcar/calmcar_xjy/3_opencv/md/opencv_w3c_c++.assets/20160823213115424)
 

 
 

 
 