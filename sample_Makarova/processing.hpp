#pragma once

#include <opencv2/core/core.hpp>

class Processing
{
 public:
     void processFrame(const cv::Mat& src, cv::Mat& dst);
     void processGrey(const cv::Mat& src, cv::Mat& dst); 
     void processCanny(const cv::Mat& src, cv::Mat& dst); 
};
