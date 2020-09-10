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


	//ͨ�������±��ȡ����������ֵ
	for (int row = 0; row < heigth; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (ch == 1)
			{
				//��ͨ��
				int gray = src.at<uchar>(row, col); //��ȡ
				src.at<uchar>(row, col) = 255 - gray; //����
			}
			else if (ch == 3)
			{
				//��ͨ��
				Vec3b bgr = src.at<Vec3b>(row, col); //��ȡ
				bgr[0] = 255 - bgr[0];
				bgr[1] = 255 - bgr[1];
				bgr[2] = 255 - bgr[2];
				src.at<Vec3b>(row, col) = bgr; //����
			}
		}
	}
	imshow("output", src);

	//ͨ��ָ���ȡ
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
				//��ͨ��
				gray = *curr_row++; //��ȡ

				*result_row++ = 255 - gray; //����
			}
			else if(ch == 3)
			{
				//��ͨ��
				blue = *curr_row++; //��ȡ������һ��Mat����ͨ��ͼ��Ľṹ
				green = *curr_row++;
				red = *curr_row++;

				*result_row++ = 255 - blue; //����
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