#ifndef __HEADER_H_INCLUDED__
#define __HEADER_H_INCLUDED__

#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <fstream>
#include <vector>
#include <sstream>
#include <time.h>
#include <algorithm>
#include <opencv2\ml\ml.hpp>


using namespace std;
using namespace cv;
using namespace cv::ml;

Scalar colorNum(0, 255, 0);
Scalar colorComm(255, 255, 0);

Mat grayNP;
Mat cropNumberPlate, resizedNP, binaryNP,commercialPlate;
Mat original, image, gray;

string uname = "root";
string password = "taka1974";
string ip_address = "http://" + uname + ":" + password + "@169.254.158.20/mjpg/video.mjpg";

vector<Rect> numPlate;
vector<Rect> num0;
vector<Rect> num1;
vector<Rect> num2;
vector<Rect> num3;
vector<Rect> num4;
vector<Rect> num5;
vector<Rect> num6;
vector<Rect> num7;
vector<Rect> num8;
vector<Rect> num9;

VideoCapture capture;


CascadeClassifier jpnNumPlate_cascade;
CascadeClassifier num0_cascade;
CascadeClassifier num1_cascade;
CascadeClassifier num2_cascade;
CascadeClassifier num3_cascade;
CascadeClassifier num4_cascade;
CascadeClassifier num5_cascade;
CascadeClassifier num6_cascade;
CascadeClassifier num7_cascade;
CascadeClassifier num8_cascade;
CascadeClassifier num9_cascade;


int vecNum = 0;
int a9;
int number0[4] = { 0 };
int number1[4] = { 0 };
int number2[4] = { 0 };
int number3[4] = { 0 };
int number4[4] = { 0 };
int number5[4] = { 0 };
int number6[4] = { 0 };
int number7[4] = { 0 };
int number8[4] = { 0 };
int number9[4] = { 0 };
int abc[4];



Mat numberPlatePut;
int counter = 1;
Mat mergedArr;
float numScale = 1.0;
int numThik = 2;
int point4 = 20;
int numHight = 35;
int numArrWith = 50;
int numArrHight = 50;
Mat numberM;

#endif
