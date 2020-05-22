#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int main(int argc, char** args) {
	if(argc<2) { std::cerr<<"Usage: "<<args[0]<<" [POINTS_FILE.yaml]"<<std::endl; exit(1); }
	cv::FileStorage fs;
	cv::Mat_<cv::Point2f> points2D;
	cv::Mat_<cv::Point3f> points3D;

	// Import point correspondences
	fs.open(args[1], cv::FileStorage::READ);
	fs["image_points"] >> points2D;
	fs["world_points"] >> points3D;
	std::cerr<<std::endl<<"Image Points:"<<std::endl<<points2D<<std::endl;
	std::cerr<<std::endl<<"World Points:"<<std::endl<<points3D<<std::endl;
	fs.release();

	// Find Homography Matrix
	cv::Mat H=findHomography(points2D, points3D, cv::RANSAC);
	std::cerr<<std::endl<<"H:"<<std::endl<<H<<std::endl<<std::endl;

	// Generate yaml file
	fs.open("homography_matrix.yaml", cv::FileStorage::WRITE);
	fs<<"homography_matrix"<<H;
	fs.release();
}
