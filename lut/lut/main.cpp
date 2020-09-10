#include<opencv2\opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void customColorMap(Mat &image);

int main(int argc, char** argv)
{
	Mat src = imread("../../sample/lena512color.bmp");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		cin.get();
		return -1;
	}

	imshow("input", src);

	Mat gray, dst;
	applyColorMap(src, dst, COLORMAP_SUMMER); //使用LUT(Look Up Table, 查找表)
	imshow("colorMap", dst);

	cvtColor(src, gray, COLOR_BGR2GRAY);
	imshow("gray", gray);


	customColorMap(gray);

	waitKey(0);
	destroyAllWindows();
	return 0;
}


void customColorMap(Mat &image)
{
	int lut[256];
	for (int i = 0; i < 256; i++)
	{
		i < 127 ? lut[i] = 0 : lut[i] = 255; //二值映射表
	}

	int width = image.cols;
	int height = image.rows;
	for (int col = 0; col < width; col++)
	{
		for (int row = 0; row < height; row++)
		{
			int pv = image.at<uchar>(row, col);
			image.at<uchar>(row, col) = lut[pv]; //相当于做二值化
		}
	}

	imshow("lut demo", image);
}