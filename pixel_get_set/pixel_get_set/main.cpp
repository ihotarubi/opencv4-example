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

	int width = src.cols;
	int heigth = src.rows;
	int ch = src.channels();


	//通过数组下标读取和设置像素值
	for (int row = 0; row < heigth; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (ch == 1)
			{
				//单通道
				int gray = src.at<uchar>(row, col); //读取
				src.at<uchar>(row, col) = 255 - gray; //设置
			}
			else if (ch == 3)
			{
				//三通道
				Vec3b bgr = src.at<Vec3b>(row, col); //读取
				bgr[0] = 255 - bgr[0];
				bgr[1] = 255 - bgr[1];
				bgr[2] = 255 - bgr[2];
				src.at<Vec3b>(row, col) = bgr; //设置
			}
		}
	}
	imshow("output", src);

	//通过指针读取
	Mat result = Mat::ones(src.size(), src.type());
	int blue = 0, green = 0, red = 0;
	int gray;
	for (int row = 0; row < heigth; row++)
	{
		uchar* curr_row = src.ptr<uchar>(row);
		uchar* result_row = result.ptr<uchar>(row);
		for (int col = 0; col < width; col++)
		{
			if (ch == 1)
			{
				//单通道
				gray = *curr_row++; //读取

				*result_row++ = 255 - gray; //设置
			}
			else if(ch == 3)
			{
				//三通道
				blue = *curr_row++; //读取，回忆一下Mat类三通道图像的结构
				green = *curr_row++;
				red = *curr_row++;

				*result_row++ = 255 - blue; //设置
				*result_row++ = 255 - green;
				*result_row++ = 255 - red;
			}
		}
	}
	imshow("result", result);

	waitKey(0);
	destroyAllWindows();
	return 0;
}