#include<opencv2\opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("../../sample/lena512color.bmp");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		cin.get();
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	// BGR to GRAY
	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);//²ÊÉ«Í¼Ïñ,B¡¢G¡¢RÅÅÁÐ
	imshow("gray", gray);

	// BGR to HSV
	Mat hsv;
	cvtColor(src, hsv, COLOR_BGR2HSV);
	imshow("hsv", hsv);

	//BGR to YUV
	Mat yuv;
	cvtColor(src, yuv, COLOR_BGR2YUV);
	imshow("yuv", yuv);

	//BGR to YCrCb
	Mat ycrcb;
	cvtColor(src, ycrcb, COLOR_BGR2YCrCb);
	imshow("ycrcb", ycrcb);

	waitKey(0);
	destroyAllWindows();

	return 0;
}