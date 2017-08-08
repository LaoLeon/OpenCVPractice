
//written by Lau , at 2017/08/08
//這個檔案可以讓程式播放webcam 的畫面

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;




int main(){

	VideoCapture capture("http://root:hellokitty@10.0.0.100/axis-cgi/mjpg/video.cgi?resolution=640x480&req_fps=30&.mjpg") ;
	//VideoCapture capture("train.avi") ;
	Mat frame ;
	Mat gray;
	Mat edge;
	int cnt = 0;

	if(frame.empty()){
			cout << "hello empty " << endl;		
		}

	while(true){
		
		/*if(!frame.empty()){
			cnt++;	
			cout << cnt << endl;
		}*/
		capture >> frame ;
		cvtColor(frame,gray,CV_BGR2GRAY);
		blur(gray,edge,Size(15,15));
		Canny(edge,edge,3,9);
		try{
			imshow("video",gray);
			imshow("video2",frame);
		}catch(Exception e){
			cout << "thanks for your watching " << endl;
			break;
			}
		waitKey(10);
	}
	system("pause");

	return 0;
}

