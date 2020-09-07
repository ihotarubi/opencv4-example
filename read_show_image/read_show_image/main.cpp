#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//Mat src = imread("test.png"); //彩色图像,B、G、R排列
	Mat src = imread("../../sample/lena512color.bmp", IMREAD_GRAYSCALE); //读取灰度图像

	if (src.empty())
	{
		cout << "could not load image..." << endl;
		cin.get();
		return -1;
	}

	//namedWindow("input", WINDOW_AUTOSIZE);
	namedWindow("input", WINDOW_FREERATIO); //WINDOW_FREERATIO:可自由缩放的窗口
	imshow("input", src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}