#include "Header.h"

int main(int, char**)
{
	time_t t;
	char fname[80];

	if (!capture.open(ip_address))
	{
		cout << "Cannot connect IP camera! Check Your Camera Connection." << endl;
		system("pause");
		return -1;
	}

	if (!jpnNumPlate_cascade.load("./cascade/700_cascade.xml"))
	{
		cout << "cascade.load failed!! put the xml file into this project holder\n";
		system("pause");
		return -1;
	}


	if (!num0_cascade.load("./cascade/num0_cascade.xml")) {
		cout << "cannot read xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}


	if (!num1_cascade.load("./cascade/num1_cascade.xml")) {
		cout << "cannot read num1 xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}

	if (!num2_cascade.load("./cascade/num2_cascade.xml")) {
		cout << "cannot read num2 xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}

	if (!num3_cascade.load("./cascade/num3_cascade.xml")) {
		cout << "cannot read num3 xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}

	if (!num4_cascade.load("./cascade/num4_cascade.xml")) {
		cout << "cannot read num4 xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}

	if (!num5_cascade.load("./cascade/num5_cascade.xml")) {
		cout << "cannot read num5xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}

	if (!num6_cascade.load("./cascade/num6_cascade.xml")) {
		cout << "cannot read num6 xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}

	if (!num7_cascade.load("./cascade/num7_cascade.xml")) {
		cout << "cannot read num7 xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}

	if (!num8_cascade.load("./cascade/num8_cascade.xml")) {
		cout << "cannot read num8 xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}

	if (!num9_cascade.load("./cascade/num9_cascade.xml")) {
		cout << "cannot read num9 xml file.check out project holder" << endl;
		system("pause");
		return -1;
	}

	Mat mainNumber[4];

	mainNumber[0].create(numArrWith, numArrHight, CV_8SC3);
	mainNumber[1].create(numArrWith, numArrHight, CV_8SC3);
	mainNumber[2].create(numArrWith, numArrHight, CV_8SC3);
	mainNumber[3].create(numArrWith, numArrHight, CV_8SC3);

	for (;;)
	{

		if (!capture.read(original)) {
			return -1;
		}

		mainNumber[0] = 0;
		mainNumber[1] = 0;
		mainNumber[2] = 0;
		mainNumber[3] = 0;

		image = original.clone();
		cvtColor(original, gray, CV_BGR2GRAY);

		jpnNumPlate_cascade.detectMultiScale(gray, numPlate, 1.3, 3);
		for (int i = 0; i < numPlate.size(); i++)
		{

			int num0row[] = { 0,1,2,3 };
			int num1row[] = { 0,1,2,3 };
			int num2row[] = { 0,1,2,3 };
			int num3row[] = { 0,1,2,3 };
			int num4row[] = { 0,1,2,3 };
			int num5row[] = { 0,1,2,3 };
			int num6row[] = { 0,1,2,3 };
			int num7row[] = { 0,1,2,3 };
			int num8row[] = { 0,1,2,3 };
			int num9row[] = { 0,1,2,3 };

			t = time(NULL);

			Point pt1(numPlate[i].x + numPlate[i].width, numPlate[i].y + numPlate[i].height);
			Point pt2(numPlate[i].x, numPlate[i].y);
			rectangle(image, pt1, pt2, colorNum, 2, 8, 0);
			Mat cropNumberPlate(original, Rect(pt1, pt2));
			resize(cropNumberPlate, resizedNP, Size(200, 100), 1.0, 1.0, INTER_LINEAR); //resize(src,dst,size(x,y),x_scale_factor,y_scale_factor,interpolation_type)
			cvtColor(resizedNP, grayNP, CV_BGR2GRAY);
			blur(grayNP, binaryNP, Point(3, 3));
			threshold(binaryNP, binaryNP, 0, 255, THRESH_BINARY | THRESH_OTSU);
						
			//strftime(fname, sizeof(fname), "C:/ImageStorage//commercialNP//CNP_%y_%m_%d_%H_%M_%S_.jpg", localtime(&t));
			//imwrite(fname, grayNP);

			vector<vector<Point> > contours;
			findContours(binaryNP, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE,Point(0,0));

			vector<vector<Point> > contours_poly(contours.size());
			vector<Rect> boundRect(contours.size());

			for (int i = 0; i < contours.size() ; i++) {
				boundRect[i] = boundingRect(Mat(contours_poly[i]));
			}

			Mat drawing = Mat::zeros(binaryNP.size(), CV_8UC3);
			for (int i = 0; i < contours.size();i++) {
				rectangle(drawing,boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,255),2,8,0);
			}
	
			imshow("rectangle", drawing);
		

			num0_cascade.detectMultiScale(grayNP, num0, 1.25, 2);
			for (int k = 0; k < num0.size(); k++) {

					Point cpt1(num0[k].x + num0[k].width, num0[k].y + num0[k].height);
					Point cpt2(num0[k].x, num0[k].y);
					rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
					Mat num0Crop(grayNP, Rect(cpt1, cpt2));
					//strftime(fname, sizeof(fname), "C:/ImageStorage//num0//num0_%y_%m_%d_%H_%M_%S_.jpg", localtime(&t));
					//imwrite(fname, num0Crop);
					num0row[k] = num0[k].x;
					number0[k] = num0[k].x;
				}

			num1_cascade.detectMultiScale(grayNP, num1, 1.25, 1);
			for (int k = 0; k < num1.size(); k++) {

				Point cpt1(num1[k].x + num1[k].width, num1[k].y + num1[k].height);
				Point cpt2(num1[k].x, num1[k].y);
				rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
				Mat num1Crop(grayNP, Rect(cpt1, cpt2));
				//strftime(fname, sizeof(fname), "C:/ImageStorage//num1//num1_%y_%m_%d_%H_%M_%S.jpg", localtime(&t));
				//imwrite(fname, num1Crop);
				num1row[k] = num1[k].x;
				number1[k] = num1[k].x;
			}

			num2_cascade.detectMultiScale(grayNP, num2, 1.25, 5);
			for (int k = 0; k < num2.size(); k++) {

				Point cpt1(num2[k].x + num2[k].width, num2[k].y + num2[k].height);
				Point cpt2(num2[k].x, num2[k].y);
				rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
				Mat num2Crop(grayNP, Rect(cpt1, cpt2));
				//strftime(fname, sizeof(fname), "C:/ImageStorage//num2//num2_%y_%m_%d_%H_%M_%S.jpg", localtime(&t));
				//imwrite(fname, num2Crop);
				num2row[k] = num2[k].x;
				number2[k] = num2[k].x;
			}

			num3_cascade.detectMultiScale(grayNP, num3, 1.25, 1);
			for (int k = 0; k < num3.size(); k++) {

				Point cpt1(num3[k].x + num3[k].width, num3[k].y + num3[k].height);
				Point cpt2(num3[k].x, num3[k].y);
				rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
				Mat num3Crop(grayNP, Rect(cpt1, cpt2));
				//strftime(fname, sizeof(fname), "C:/ImageStorage//num3//num3_%y_%m_%d_%H_%M_%S.jpg", localtime(&t));
				//imwrite(fname, num3Crop);
				num3row[k] = num3[k].x;
				number3[k] = num3[k].x;
			}

			num4_cascade.detectMultiScale(grayNP, num4, 1.25, 5);
			for (int j = 0; j < num4.size(); j++) {

				Point cpt1(num4[j].x + num4[j].width, num4[j].y + num4[j].height);
				Point cpt2(num4[j].x, num4[j].y);
				rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
				Mat num4Crop(grayNP, Rect(cpt1, cpt2));
				//strftime(fname, sizeof(fname), "C:/ImageStorage//num4//num4_%y_%m_%d_%H_%M_%S.jpg", localtime(&t));
				//imwrite(fname, num4Crop);
				num4row[j] = num4[j].x;
				number4[j] = num4[j].x;
			}

			num5_cascade.detectMultiScale(grayNP, num5, 1.25, 1);
			for (int j = 0; j < num5.size(); j++) {

				Point cpt1(num5[j].x + num5[j].width, num5[j].y + num5[j].height);
				Point cpt2(num5[j].x, num5[j].y);
				rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
				Mat num5Crop(grayNP, Rect(cpt1, cpt2));
				//strftime(fname, sizeof(fname), "C:/ImageStorage//num5//num5_%y_%m_%d_%H_%M_%S_.jpg", localtime(&t));
				//imwrite(fname, num5Crop);
				num5row[j] = num5[j].x;
				number5[j] = num5[j].x;
			}

			num6_cascade.detectMultiScale(grayNP, num6, 1.25, 5);
			for (int j = 0; j < num6.size(); j++) {

				Point cpt1(num6[j].x + num6[j].width, num6[j].y + num6[j].height);
				Point cpt2(num6[j].x, num6[j].y);
				rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
				Mat num6Crop(grayNP, Rect(cpt1, cpt2));
				//strftime(fname, sizeof(fname), "C:/ImageStorage//num6/num6_%y_%m_%d_%H_%M_%S_.jpg", localtime(&t));
				//imwrite(fname, num6Crop);
				num6row[j] = num6[j].x;
				number6[j] = num6[j].x;
			}

			num7_cascade.detectMultiScale(grayNP, num7, 1.25, 5);
			for (int j = 0; j < num7.size(); j++) {

				Point cpt1(num7[j].x + num7[j].width, num7[j].y + num7[j].height);
				Point cpt2(num7[j].x, num7[j].y);
				rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
				Mat num7Crop(grayNP, Rect(cpt1, cpt2));
				//strftime(fname, sizeof(fname), "C:/ImageStorage//num7//num7_%y_%m_%d_%H_%M_%S_.jpg", localtime(&t));
				//imwrite(fname, num7Crop);
				num7row[j] = num7[j].x;
				number7[j] = num7[j].x;
			}

			num8_cascade.detectMultiScale(grayNP, num8, 1.25, 5);
			for (int j = 0; j < num8.size(); j++) {

				Point cpt1(num8[j].x + num8[j].width, num8[j].y + num8[j].height);
				Point cpt2(num8[j].x, num8[j].y);
				rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
				Mat num8Crop(grayNP, Rect(cpt1, cpt2));
				//strftime(fname, sizeof(fname), "C:/ImageStorage//num8//num8_%y_%m_%d_%H_%M_%S_.jpg", localtime(&t));
				//imwrite(fname, num8Crop);
				num8row[j] = num8[j].x;
				number8[j] = num8[j].x;
			}

			num9_cascade.detectMultiScale(grayNP, num9, 1.25, 5);
			for (int j = 0; j < num9.size(); j++) {
				a9++;
				Point cpt1(num9[j].x + num9[j].width, num9[j].y + num9[j].height);
				Point cpt2(num9[j].x, num9[j].y);
				rectangle(resizedNP, cpt1, cpt2, colorComm, 1, 8, 0);
				Mat num9Crop(grayNP, Rect(cpt1, cpt2));
				//strftime(fname, sizeof(fname), "C:/ImageStorage//num9//num2_%y_%m_%d_%H_%M_%S_.jpg", localtime(&t));
				//imwrite(fname, num9Crop);
				num9row[j] = num9[j].x;
				number9[j] = num9[j].x;
			}

			vector<int> listVector{
				num0row[0],num0row[1],num0row[2],num0row[3],
				num1row[0],num1row[1],num1row[2],num1row[3],
				num2row[0],num2row[1],num2row[2],num2row[3],
				num3row[0],num3row[1],num3row[2],num3row[3],
				num4row[0],num4row[1],num4row[2],num4row[3],
				num5row[0],num5row[1],num5row[2],num5row[3],
				num6row[0],num6row[1],num6row[2],num6row[3],
				num7row[0],num7row[1],num7row[2],num7row[3],
				num8row[0],num8row[1],num8row[2],num8row[3],
				num9row[0],num9row[1],num9row[2],num9row[3],
			};

			sort(listVector.begin(), listVector.end());
			for (vecNum = 0;vecNum < 4;vecNum++) {
				listVector.erase(remove(listVector.begin(), listVector.end(), vecNum), listVector.end());
			}

			auto itr = listVector.begin();
			for (int i = 0; i < listVector.size(); i++) {
				mainNumber[i];

				for (int y = 0; y < 4; y++) {
	
					if (*itr == number0[y]) {
						cout << 0;
						putText(mainNumber[i], "0", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik, 8);
						break;
					}

					if (*itr == number1[y]) {
						cout << 1;
						putText(mainNumber[i], "1", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX,	numScale, Scalar(0, 255, 0), numThik, 8);
						break;
					}

					if (*itr == number2[y]) {
						cout << 2;
						putText(mainNumber[i], "2", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik, 8);
						break;
					}

					if (*itr == number3[y]) {
						cout << 3;
						putText(mainNumber[i], "3", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik, 8);
						break;
					}

					if (*itr == number4[y]) {
						cout << 4;
						putText(mainNumber[i], "4", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik , 8);
						break;
					}

					if (*itr == number5[y]) {
						cout << 5;
						putText(mainNumber[i], "5", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik, 8);
						break;
					}

					if (*itr == number6[y]) {
						cout << 6;
						putText(mainNumber[i], "6", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik, 8);
						break;
					}

					if (*itr == number7[y]) {
						cout << 7;
						putText(mainNumber[i], "7", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik, 8);
						break;
					}

					if (*itr == number8[y]) {
						cout << 8;
						putText(mainNumber[i], "8", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik, 8);
						break;
					}

					if (*itr == number9[y]) {
						cout << 9;
						putText(mainNumber[i], "9", Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik, 8);
						break;
					}

				}

				itr++;

			
		}


			//cout << listVector[i] << endl;
			cout << "\n";
			imshow("captured number", resizedNP);

			vector<Mat> mv{ mainNumber[0],mainNumber[1],mainNumber[2],mainNumber[3] };

			hconcat(mv,numberPlatePut);
		//	vconcat(resizedNP, numberPlatePut);
			imshow("numberPut", numberPlatePut);

		}

		putText(image, "Detecting Number Plate", Point(15, 15), CV_FONT_HERSHEY_SIMPLEX, 0.35, Scalar(0, 255, 0), 1, 8);
		
		imshow("Detecting Number Plate Streaming", image);
		if (waitKey(1) >= 0) break;

	}

	destroyAllWindows;

	return 0;
}

