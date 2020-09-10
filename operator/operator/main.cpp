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

	imshow("src", src);

	Mat dst1;
	dst1 = src + Scalar(50, 50, 50); //������Mat�����㣬Scalar(50, 50, 50)����������Mat����ֵ
	//dst1 = src + Mat::zeros(src.size(), src.type()); //Ҳ�����������ųߴ�һ�µ�ͼƬ��ӣ���ͬ
	//add(src, Scalar(50, 50, 50), dst1); //cv::add���������������� + һ�£���ͬ
	imshow("add", dst1);

	Mat dst2;
	dst2 = src - Scalar(50, 50, 50);
	//subtract(src, Scalar(50, 50, 50), dst2);
	imshow("sub", dst2);

	Mat dst3;
	multiply(src, Scalar(2, 2, 2), dst3); //�˷�����ֱ��ʹ������� * ,��Ҫʹ��cv::multiply����
	imshow("mult", dst3);

	Mat dst4;
	dst4 = src / Scalar(2, 2, 2);
	//divide(src, Scalar(2, 2, 2), dst4);
	imshow("div", dst4);

	//ʵ��add
	Mat result = Mat::zeros(src.size(), src.type());
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			Vec3b bgr = src.at<Vec3b>(row, col);

			bgr[0] = saturate_cast<uchar>(bgr[0] + 50); //saturate_cast<uchar>():��()�ڵ���ֵ������uchar���͵�ȡֵ��Χ(0-255)��
			bgr[1] = saturate_cast<uchar>(bgr[1] + 50);
			bgr[2] = saturate_cast<uchar>(bgr[2] + 50);

			result.at<Vec3b>(row, col) = bgr;
		}
	}
	imshow("add2", result);

	waitKey(0);
	destroyAllWindows();
	return 0;
}