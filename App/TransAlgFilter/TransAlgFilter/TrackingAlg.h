#pragma once
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/background_segm.hpp"
#include "Utility.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace cv;

class TrackingAlg
{
public:
	TrackingAlg();
	int Update(Mat& frame);
private:
	BackgroundSubtractorMOG2 bgSubtractor;
	PersonManager personManager;
	int frameIndex;
	Mat gbmForeground;

private:
	int CalcImageBaryCenters(const Mat& img, vector<Point2f>& baryCenters);
};