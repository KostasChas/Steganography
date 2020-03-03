//// Opencvtest.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
////CONTRAST AND BRIGHTNESS_____________________________________________________
//
//
//#include "opencv2/imgcodecs.hpp" // library from net for img process	
//#include "opencv2/highgui.hpp"   // this too
//#include <iostream>
//
//using std::cin;
//using std::cout;
//using std::endl;
//
//using namespace cv;
//// using namspace std;   <----- why this error????????????-----------------------------
//
//int main(int argc, char** argv)
//{
//	CommandLineParser parser(argc, argv, "{@input | smile1.jpg | input image}"); // always img in same folder as solution (better)
//	Mat image = imread(samples::findFile(parser.get<String>("@input")));
//	if (image.empty()) {
//
//		cout << "Could not open or find the image!\n" << endl;
//		cout << "Usage: " << argv[0] << " <Input image>" << endl;
//		return -1;
//	}
//
//	Mat new_image = Mat::zeros(image.size(), image.type());
//
//	double alpha = 1.0; /*< STUDY THE CONTROL ----MAKE IT BETTER FOR CONTR */
//	int beta = 0;       /* STUDY THE CONTROL ---MAKE IT BETTER FOR BRIGHTNESS */
//
//
//	cout << "-------------------------" << endl;
//	cout << "* Enter value from 1.0 to 3.0: "; cin >> alpha;
//	cout << "* Enter value from 0 to 100: ";    cin >> beta;
//	cout << "-------------------------" << endl;
//
//	for (int y = 0; y < image.rows; y++) {
//		for (int x = 0; x < image.cols; x++) {
//			for (int c = 0; c < image.channels(); c++) {
//				new_image.at<Vec3b>(y, x)[c] =
//					saturate_cast<uchar>(alpha*image.at<Vec3b>(y, x)[c] + beta);
//			}
//		}
//	}
//	imshow("Original Image", image); // print old image
//	imshow("New Image", new_image); // print new processed img
//	waitKey(); // wait for user input to end
//	return 0;
//}



// _____________________________________________________ BLEND 2 IMAGES TOGETHER_______________________________________________-


#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	double alpha =0; double beta; double input;
	Mat src1, src2, dst;
	cout << " Simple Linear Blender " << endl;
	cout << "-----------------------" << endl;
	cout << "* Enter alpha [0.0-1.0]: ";
	cin >> input;
	// We use the alpha provided by the user if it is between 0 and 1
	if (input >= 0 && input <= 1)
	{
		alpha = input;
	}
	src1 = imread(samples::findFile("smile1.jpg"));
	src2 = imread(samples::findFile("smile2.jpg"));
	if (src1.empty()) { cout << "Error loading src1" << endl; return EXIT_FAILURE; }
	if (src2.empty()) { cout << "Error loading src2" << endl; return EXIT_FAILURE; }
	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);
	imshow("Linear Blend", dst);
	waitKey(0);
	return 0;
}

 //Run program: Ctrl + F5 or Debug > Start Without Debugging menu
 //Debug program: F5 or Debug > Start Debugging menu

 //Tips for Getting Started: 
 //  1. Use the Solution Explorer window to add/manage files
 //  2. Use the Team Explorer window to connect to source control
 //  3. Use the Output window to see build output and other messages
 //  4. Use the Error List window to view errors
 //  5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
 //  6. In the future, to open this project again, go to File > Open > Project and select the .sln file
