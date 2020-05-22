#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int main(int argc, char** args) {
	if(argc<3) { std::cerr<<"Usage: "<<args[0]<<" [ H_MATRIX.yaml u-COORDINATE v-COORDINATE ]"<<std::endl; exit(1); }  
	cv::Mat H;
	// Read yaml file
	cv::FileStorage fs(args[1], cv::FileStorage::READ);
	fs["homography_matrix"]>>H;
	fs.release();

	// Now, inputs 2D points and show them as 3D
	cv::Mat_<cv::Point2f> sourcePoints;
	cv::Mat_<cv::Point2f> targetPoints;
	sourcePoints.push_back(cv::Point2f(std::stof(args[2]), std::stof(args[3])));
	perspectiveTransform(sourcePoints, targetPoints, H);
	std::cerr<<sourcePoints<<">"<<targetPoints<<std::endl;

}
