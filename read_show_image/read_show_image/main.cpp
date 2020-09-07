#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//Mat src = imread("test.png"); //��ɫͼ��,B��G��R����
	Mat src = imread("../../sample/lena512color.bmp", IMREAD_GRAYSCALE); //��ȡ�Ҷ�ͼ��

	if (src.empty())
	{
		cout << "could not load image..." << endl;
		cin.get();
		return -1;
	}

	//namedWindow("input", WINDOW_AUTOSIZE);
	namedWindow("input", WINDOW_FREERATIO); //WINDOW_FREERATIO:���������ŵĴ���
	imshow("input", src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}