
#include "imageRender.hpp"
#include "speedDecider.hpp"


int main(){

	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}   
	bool asking = true;
	bool core = true;
	
	while(asking){	
		std::string level ="";
		std::cout<<"core/completion/challenge: "<<std::endl;
		std::cin>>level;
		if(level.compare("core")==0 |level.compare("completion")==0){
			asking = false;
		}
		else if(level.compare("challenge")==0){
			asking = false;
			core =false;
		}
	}
    while(1){
		takePicture();
			// While true is going in a loop move the car
		if(core){
		setMotorCompletion(renderImageCompletion());
		}
		else{
			setMotorChallenge(renderImageChallenge());
			//setMotorCompletion(renderImageChallenge());
		}

  } //while
} // main
