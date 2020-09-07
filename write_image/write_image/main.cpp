#include <opencv2\opencv.hpp>
#include <iostream>

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

	Mat gray_img;
	cvtColor(src, gray_img, COLOR_BGR2GRAY);
	imwrite("lena512gray.bmp", gray_img);

	cout << "write completed " << endl;

	cin.get();
	return 0;
}