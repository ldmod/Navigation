#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/background_segm.hpp"
#include "ParticleTrackingAlg.h"
#include "RGBHistFeature.h"
#include "Particle.h"
#include "ParticleFeature.h"
#include "Utility.h"
#include <time.h>
#include <iostream>
using namespace cv;

const string videoFileName = "H:\\GitHubCode\\Navigation\\Research\\TrackingTeacher\\Data\\T_WALK1.mp4";

int main(int argc, char **argv)
{
	VideoCapture cap;
	Mat frame, foreground, tmpForeground;
	BackgroundSubtractorMOG2 mog;
	cap.open(videoFileName);
	cap >> frame;
	int cols = frame.cols;
	int rows = frame.rows;
	namedWindow("Gaussian Foreground");
	namedWindow("Bary Centre");
	Utility::GenerateAuxMatForBaryCentre(rows, cols);
	
	for(;;)
	{
		if(frame.empty())
		{
			break;
		}
		mog(frame, foreground, 0.01);
		threshold(foreground, foreground, 128, 255, THRESH_BINARY);
		foreground.copyTo(tmpForeground);
		tmpForeground = tmpForeground/255;
		int sum = Utility::GetNoneZeroPointsNum(tmpForeground);
		Point2f centre;
		Utility::CalcImageBaryCentre(tmpForeground, sum, centre);
		std::cout<<"None Zero Points: "<<sum<<std::endl;
		std::cout<<"Bary Centre: "<<centre<<std::endl;
		circle(tmpForeground, centre, 5, Scalar(255,0,0), 2);
		imshow("Guassian Foreground", foreground);
		imshow("Bary Centre", tmpForeground);
		waitKey(10);
		cap >> frame;
	}
}