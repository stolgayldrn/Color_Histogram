#include "helpers2.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <string>
#include <vector>
#include "HSV_histogram.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	vector<string> fileList;
	get_directory_images(argv[1],fileList);//@param argv[1] is directory of frames' folder
	vector<MatND> HSV_Hists;
	int base_frame_number = 0;

	for(int i = 0; i < fileList.size(); i++)
	{
		string fileName = argv[1];
		fileName =+ "\\" + fileList[i];
		HSV_histogram hsv_hist = HSV_histogram(fileName);
		hsv_hist.Calculate_Histogram();
		HSV_Hists.push_back(hsv_hist.getHistogram());		

		//double base_base = compareHist( HSV_Hists[base_frame_number], 
			//HSV_Hists[i], 1 );
				
	}

	return 0;
}