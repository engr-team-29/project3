#include "imageRender.hpp"
#include "speedDecider.hpp"


int main(){

	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}   
    while(1){
		takePicture();
		// While true is going in a loop move the car
		setMotorCompletion(renderImageCompletion());



  } //while
} // main
