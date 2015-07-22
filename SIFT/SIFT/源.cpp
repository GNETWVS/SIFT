#include <opencv2\opencv.hpp>
#include <iostream>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\nonfree\features2d.hpp>
#include <opencv2\legacy\legacy.hpp>
using namespace std;
using namespace cv;

//��ʾ������
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
//	//��ƥ�������ͼ������img1����img2��Ҳ����Ҫ��img1��ʶ���img2  
//	Mat img1 = imread("2.png");
//	Mat img2 = imread("3.jpg");
//	img2 = img2((Rect(140, 46, 112, 126)));
//	SIFT sift1(10, 3, 0.01, 10, 1), sift2(10, 3, 0.01, 10, 1);
//
//	vector<KeyPoint> key_points1, key_points2; //�ؼ���
//
//	Mat descriptors1, descriptors2, mascara;   //������������
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
//	//ʵ��������ƥ��������BruteForceMatcher  
//
//	BFMatcher matcher(NORM_L1);
//	//����ƥ��������  
//	vector<DMatch>matches;
//	//ʵ��������֮���ƥ�䣬�õ�����matches  
//	
//	matcher.match(descriptors1, descriptors2, matches);
//	//��ȡ��ǰ30�����ƥ����  
//	std::nth_element(matches.begin(),     //ƥ�������ӵĳ�ʼλ��  
//		matches.begin()+1 ,     // ���������  
//		matches.end());       // ����λ��  
//	//�޳��������ƥ����  
//	matches.resize(2);
//	cout << matches[0].distance << endl;
//	cout << matches[1].distance << endl;
//	namedWindow("SIFT_matches");
//	Mat img_matches;
//	//�����ͼ���л���ƥ����  
//	drawMatches(img1, key_points1,         //��һ��ͼ�������������  
//		img2, key_points2,      //�ڶ���ͼ�������������  
//		matches,       //ƥ��������  
//		img_matches,      //ƥ�����ͼ��  
//		Scalar(0, 255, 255));     //�ð�ɫֱ����������ͼ���е�������  
//	imshow("SIFT_matches", img_matches);
//	waitKey(0);
//
//	return 0;
//}
