#include <opencv2\opencv.hpp>
#include <iostream>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\nonfree\features2d.hpp>
#include <opencv2\legacy\legacy.hpp>
using namespace std;
using namespace cv;

//显示特征点
void main( )
{
	Mat image1 = imread("2.png");
	Mat image2 = imread("3.jpg");
	image2 = image2(Rect(140, 46, 112, 126));
	Mat iamgeGray1, iamgeGray2;
	cvtColor(image1, iamgeGray1, CV_RGB2GRAY);
	cvtColor(image2, iamgeGray2, CV_RGB2GRAY);


	vector<KeyPoint> keypoints1, keypoints2;
	SIFT sift(0,3,0.01,10,1.0);
	double t = (double)cvGetTickCount();  //notes time

	sift.detect(iamgeGray1, keypoints1);
	sift.detect(iamgeGray2, keypoints2);

	cout << getTickFrequency()/((double)cvGetTickCount() - t) << endl;

	drawKeypoints(image1, keypoints1, image1, Scalar(255, 0, 255),1);
	drawKeypoints(image2, keypoints2, image2, Scalar(255, 0, 255), 1);

	imshow("1", image1);
	imshow("2", image2);
	waitKey();
}

//int main(int argc, char** argv)
//{
//	//待匹配的两幅图像，其中img1包括img2，也就是要从img1中识别出img2  
//	Mat img1 = imread("2.png");
//	Mat img2 = imread("3.jpg");
//	img2 = img2((Rect(140, 46, 112, 126)));
//	SIFT sift1(10, 3, 0.01, 10, 1), sift2(10, 3, 0.01, 10, 1);
//
//	vector<KeyPoint> key_points1, key_points2; //关键点
//
//	Mat descriptors1, descriptors2, mascara;   //特征描述向量
//
//	sift1(img1, mascara, key_points1, descriptors1);
//	sift2(img2, mascara, key_points2, descriptors2);
//
//
//	drawKeypoints(img1, key_points1, img1, Scalar(255, 0, 255), 1);
//	drawKeypoints(img2, key_points2, img2, Scalar(255, 0, 255), 1);
//
//	imshow("img1", img1);
//	imshow("img2", img2);
//	//实例化暴力匹配器——BruteForceMatcher  
//
//	BFMatcher matcher(NORM_L1);
//	//定义匹配器算子  
//	vector<DMatch>matches;
//	//实现描述符之间的匹配，得到算子matches  
//	
//	matcher.match(descriptors1, descriptors2, matches);
//	//提取出前30个最佳匹配结果  
//	std::nth_element(matches.begin(),     //匹配器算子的初始位置  
//		matches.begin()+1 ,     // 排序的数量  
//		matches.end());       // 结束位置  
//	//剔除掉其余的匹配结果  
//	matches.resize(2);
//	cout << matches[0].distance << endl;
//	cout << matches[1].distance << endl;
//	namedWindow("SIFT_matches");
//	Mat img_matches;
//	//在输出图像中绘制匹配结果  
//	drawMatches(img1, key_points1,         //第一幅图像和它的特征点  
//		img2, key_points2,      //第二幅图像和它的特征点  
//		matches,       //匹配器算子  
//		img_matches,      //匹配输出图像  
//		Scalar(0, 255, 255));     //用白色直线连接两幅图像中的特征点  
//	imshow("SIFT_matches", img_matches);
//	waitKey(0);
//
//	return 0;
//}
