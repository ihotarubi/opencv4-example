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

	//��¡�������
	Mat m1 = src.clone();
	//����(���)
	Mat m2;
	src.copyTo(m2);
	//��ֵ(���)
	Mat m3 = src;
	
	//�����հ׶���
	Mat m4 = Mat::zeros(src.size(), src.type());
	Mat m5 = Mat::zeros(Size(8, 8), CV_8UC1);//��ͨ��,ȫΪ0
	Mat m6 = Mat::zeros(Size(8, 8), CV_8UC3); //3ͨ��,ȫΪ0
	Mat m7 = Mat::ones(Size(8, 8), CV_8UC3); //3ͨ����ֻ�е�һ��ͨ��Ϊ0����������ͨ��Ϊ1
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

	m6 = 127;//����һ��ͨ����ֵ
	cout << "m6: " << endl;
	cout << m6 << endl;
	m4 = Scalar(0, 0, 255);//��3��ͨ�������и�ֵ��3��ͨ���ֱ�ΪB��G��R,���Ϊ��ɫ
	imshow("m4", m4);

	waitKey(0);
	destroyAllWindows();
	return 0;
}