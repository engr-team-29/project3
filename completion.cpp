
#include "speedDecider.hpp"
#include "robot.hpp"

int main(){

	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	const double v_go = 40.0;
	const double kp = 0.04; //how far the error is from the error line, the constant turning SCALE 

   //const int CameraWidth = 150;
    double vLeft = 40.0;
    double vRight = 40.0;

   
    while(1){ 
		
		takePicture();
		
		double Line_position = 0;                  // While true is going in a loop analyzing the frames

		int white = 0; 
		int leftLine=0;
		int rightLine=0;
		int topLine=0;
		int bottomLine=0;
		int CameraWidth = 150;    
		for(int i =0; i<4; i++){
			Line_position =0;
			white=0;
			//will check 3 sides.
			int checkCol=0;
			int checkRow = -1;
			if(i==0){checkCol=0;}
			if(i==1){checkCol=cameraView.width-1;}
			if(i==2){checkRow=cameraView.height-1;}
			if(i==3){checkRow=0;}
			if(i==0 || i==1){
				for (int pixInt = 0; pixInt < cameraView.height; pixInt++){                           
			int brightness = get_pixel(cameraView, pixInt, checkCol, 3);       // Brightness of the pixels
			if(brightness>=250){
                // Detects pixels with a brightness of 255            
				white++;                                            
				 Line_position += pixInt;
				} 
		  }
		 
			}
			else if(i==2 ||i==3){
				for (int pixInt = 0; pixInt < CameraWidth; pixInt++){                           
			int brightness = get_pixel(cameraView, checkRow, pixInt, 3);       // Brightness of the pixels
			if(brightness>=250){                             // Detects pixels with a brightness of 255            
				white++;                                            
				int linePosition= pixInt - CameraWidth/2;
				} 
			}
			}
			if(i==1){leftLine=white;}
			if(i==0){rightLine=white;}
			if(i==3){topLine=white;}
			if(i==2){bottomLine=white;}
			
		}

		 //Line_position /= white;                         // Divides the Line Position by the white  
		//}
		std::cout<<std::endl<<"left:"<<leftLine<<" right:"<<rightLine<<" top:"<<topLine<<" bot:"<<bottomLine<<std::endl;    // Prints the average

        double dv = 0;
        //vLeft = v_go + dv;
        //vRight = v_go - dv;
        vLeft = 40;
        vRight= 40;
        
        if(rightLine >0){
			//dv = kp * rightLine;
			vRight=50;
			vLeft =30;
		}
		else if(leftLine >0){
			//dv = kp * rightLine;
			vLeft=50;
			vRight=30;
		}
		else if((bottomLine==0&&topLine==0)){
			
			vLeft =-40;
			vRight =-40;
		}
		else if((topLine==0 && bottomLine>0)||topLine>30){
			vLeft=40;
			vRight =-40;
		
		}

      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;

	     setMotors(vLeft,vRight);   
       //usleep(10000);

  } //while

  



} // main
