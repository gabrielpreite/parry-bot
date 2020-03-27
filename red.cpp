#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

//g++ -o red red.cpp `pkg-config opencv --cflags --libs`

using namespace std;
using namespace cv;

int main(){
    Mat img = imread("upw.png");
    Vec3b black = Vec3b();
    black.val[0] = 0;
    black.val[1] = 0;
    black.val[2] = 0;
    Vec3b red = Vec3b();
    red.val[0] = 0;
    red.val[1] = 0;
    red.val[2] = 255;
    for(int i=0; i<img.cols; i++){
        for(int j=0; j<img.rows; j++){
            Vec3b intensity = img.at<Vec3b>(Point(i, j));
            if(intensity.val[2] > 150 &&
               intensity.val[1] < 100 && 
               intensity.val[0] < 100)
                img.at<Vec3b>(Point(i, j)) = red;
            else
                img.at<Vec3b>(Point(i, j)) = black;
        }
    }
    imshow("image", img);
    waitKey(20000);

    return 0;
}