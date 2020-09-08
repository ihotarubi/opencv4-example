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

	//克隆（深拷贝）
	Mat m1 = src.clone();
	//复制(深拷贝)
	Mat m2;
	src.copyTo(m2);
	//赋值(深拷贝)
	Mat m3 = src;
	
	//创建空白对象
	Mat m4 = Mat::zeros(src.size(), src.type());
	Mat m5 = Mat::zeros(Size(8, 8), CV_8UC1);//单通道,全为0
	Mat m6 = Mat::zeros(Size(8, 8), CV_8UC3); //3通道,全为0
	Mat m7 = Mat::ones(Size(8, 8), CV_8UC3); //3通道，只有第一个通道为0，其余两个通道为1
	Mat m8 = (Mat_<char>(3, 3) << 
		0, -1, 0,
		-1, 5, -1,
		0, -1, 0);


	cout << "m5, " "width: " << m5.cols << " heigth: " << m5.rows << " channels: " << m5.channels() << endl;
	cout << m5 << endl;
	cout << "m6, " "width: " << m6.cols << " heigth: " << m6.rows << " channels: " << m6.channels() << endl;
	cout << m6 << endl;
	cout << "m7, " "width: " << m7.cols << " heigth: " << m7.rows << " channels: " << m7.channels() << endl;
	cout << m7 << endl;
	cout << "m8, " "width: " << m8.cols << " heigth: " << m8.rows << " channels: " << m8.channels() << endl;
	cout << m8 << endl;

	m6 = 127;//给第一个通道赋值
	cout << "m6: " << endl;
	cout << m6 << endl;
	m4 = Scalar(0, 0, 255);//给3个通道都进行赋值，3个通道分别为B、G、R,因此为红色
	imshow("m4", m4);

	waitKey(0);
	destroyAllWindows();
	return 0;
}