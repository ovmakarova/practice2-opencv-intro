#include "processing.hpp"

#include <opencv2/imgproc/imgproc.hpp>
#include <time.h>
#include <math.h>

using namespace cv;

void Processing::processFrame(const cv::Mat& src, cv::Mat& dst)
{
    src.copyTo(dst);

    srand(time(NULL));
    int x0 = rand()%src.rows;
    int y0 = rand()%src.cols;

    while((x0+x0+100 > 500) || (y0+y0+100> 500)){
        x0 = rand()%src.rows;
        y0 = rand()%src.cols;
    }

    cv::Rect region(x0, y0, x0+100, y0+100);
    Mat roi = dst(region);

    const int kSize = 11;
    medianBlur(roi, roi, kSize);
    rectangle(dst, region, Scalar(255, 0, 0));
}

void Processing::processGrey(const cv::Mat& src, cv::Mat& dst)
{
    src.copyTo(dst);

    srand(time(NULL));
    int x0 = rand()%src.rows;
    int y0 = rand()%src.cols;
    
    while ((x0+x0+100 > 500) || (y0+y0+100> 500))
    {
        x0 = rand()%src.rows;
        y0 = rand()%src.cols;
    }

    cv::Rect region(x0, y0, x0+100, y0+100);
    Mat roi = dst(region);
       
    const int kSize = 11;

    Mat grey;
    cvtColor(roi, grey, CV_BGR2GRAY, 1);
    vector<Mat> channels(3);
    
    channels[0] = grey;
    channels[1] = grey;
    channels[2] = grey;
    
    merge(channels, roi);

    rectangle(dst, region, Scalar(255, 0, 0)); 
}

void Processing::processCanny(const cv::Mat& src, cv::Mat& dst)
{
    src.copyTo(dst);

    srand(time(NULL));
    int x0 = rand()%src.rows;
    int y0 = rand()%src.cols;
    
    while ((x0+x0+100 > 500) || (y0+y0+100> 500))
    {
        x0 = rand()%src.rows;
        y0 = rand()%src.cols;
    }

    cv::Rect region(x0, y0, x0+100, y0+100);
    Mat roi = dst(region);
       
    const int kSize = 11;

    Mat canny;
    Canny(roi, canny, CV_BGR2GRAY, 1);
    vector<Mat> channels(3);
    
    channels[0] = canny;
    channels[1] = canny;
    channels[2] = canny;
    
    merge(channels, roi);

    rectangle(dst, region, Scalar(255, 0, 0)); 
}


