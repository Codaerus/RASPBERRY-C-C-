/*
 *                             Diferencia de Frames
 * Restaremos el frame actual de un frame de referencia anterior, si la diferencia 
 * entre dos frames es lo suficientemente significativa, entonces se detecta movimiento
*/
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(){
	cv::VideoCapture cap(0);
	if(!cap.isOpened()){
		std::cout<<"Error al abrir la camara"<<endl;
		return -1;
		}
	cv::Mat f,f2,frame,gray,thresh,orig,result;
	bool ret = cap.read(f);
	if(!ret){
		cout<<"Error al capturar el frame"<<endl;
		return -1;
			}
	cv::resize(f,frame,cv::Size(576,384));
	cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY); //Simplificar el procesamiento
	cv::GaussianBlur(frame,frame,cv::Size(23,23),0);
	while(true){
		bool ret = cap.read(f2);
		if(!ret){
			cout<<"Error al capturar el frame"<<endl;
			break;
			}
		cv::resize(f2,orig,cv::Size(576,384));
		//Restamos el frame de referencia del frame actual

		cv::cvtColor(orig,orig,cv::COLOR_BGR2GRAY); //Simplificar el procesamiento
		cv::GaussianBlur(orig,orig,cv::Size(23,23),0);
		cv::absdiff(frame,orig,result);
		cv::threshold(result,thresh,120,255,cv::THRESH_BINARY);
		cv::imshow("Movimiento detectado",thresh);
		cv::imshow("Imagen Original",orig);
		//cv::imshow("Diferencia",result);
		if(cv::countNonZero(thresh)<500){
				thresh = cv::Mat::zeros(thresh.size(),thresh.type());//orig.clone();
			}
		else{
				frame = orig.clone();
			}
		if (cv::waitKey(1) == 's'){
			break;}
		}
	cap.release();
	cv::destroyAllWindows();
	return 0;
}
