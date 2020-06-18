
#include "speedDecider.hpp"
#include "robot.hpp"
/*****Line reading, values for lines from image*****/
struct LineReading{
	int leftLine=0;
	int leftPosition=0;
	int rightLine=0;
	int rightPosition=0;
	int topLine=0;
	int topPosition=0;
	int bottomLine=0;
	int bottomPosition=0;
};

int main(){

	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	const double v_go = 40.0;
	const double kp = 0.04; //how far the error is from the error line, the constant turning SCALE 

   //const int CameraWidth = 150;

   
    while(1){
    double vLeft = 40.0;
    double vRight = 40.0;
		takePicture();
		// While true is going in a loop analyzing the frames
		LineReading reading; 
		//LineReading reading = new LineReading();
		//int CameraWidth = 150;    
		for(int i =0; i<4; i++){
			//Line_position =0;
			//white=0;
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
				if(i==1){                                      
				 reading.leftPosition += pixInt;
				 reading.leftLine++;
			 }
			 else{
				 reading.rightPosition += pixInt;
				 reading.rightLine++;
				 }
				} 
		  }
		 
			}
			else if(i==2 ||i==3){
				for (int pixInt = 0; pixInt < cameraView.width; pixInt++){                           
			int brightness = get_pixel(cameraView, checkRow, pixInt, 3);       // Brightness of the pixels
			if(brightness>=250){                             // Detects pixels with a brightness of 255            
				//white++;                                            
				int linePosition= pixInt - cameraView.width/2;
				if(i==2){
					reading.bottomPosition += pixInt;
				 reading.bottomLine++;
				}
				else{
					reading.topPosition += pixInt;
				 reading.topLine++;
				}
				} 
			}
			}
			
		}

		 //Line_position /= white;                         // Divides the Line Position by the white  
		//}
		std::cout<<std::endl<<"left:"<<reading.leftLine<<" right:"<<reading.rightLine<<" top:"<<reading.topLine<<" bot:"<<reading.bottomLine<<std::endl;    // Prints the average

        double dv = 0;
        //vLeft = 40;
        //vRight= 40;
        
        if(reading.rightLine >0 && reading.rightLine<10){
			/*
			double dv =kp*(cameraView.width/2) + kp*(reading.rightPosition/(reading.rightLine));
			vLeft = v_go + 2*dv;
			vRight = v_go - 2*dv;
			*/
			vLeft = v_go -20;
			vRight =v_go +20;
		}
		else if(reading.leftLine >0&& reading.leftLine<10){
			/*
			double dv =kp*(cameraView.width) + kp*(reading.rightPosition/reading.rightLine);
			vLeft = v_go - dv;
			vRight = v_go + dv;
			*/
			vLeft = v_go + 20;
			vRight = v_go -20;
		}
		else if(reading.topLine>0 && reading.topLine<20){
			/*
			double dv =kp * (reading.topPosition/reading.topLine);
			vLeft = v_go + dv;
			vRight = v_go - dv;
			*/
			vLeft = v_go;
			vRight = v_go; 
			
		}
		/*
		else if((reading.bottomLine==0&&reading.topLine==0)){
			double dv =kp * (cameraView.width/2)+ kp*(cameraView.height);
			vLeft = v_go + dv;
			vRight = v_go - dv;
			//vLeft =-40;
			//vRight =-40;
		}
		*/
		else if(reading.topLine>15){
			
			vLeft=-30;
			vRight =-40;
			}
		else if((reading.topLine==0 && reading.bottomLine>0)){
			vLeft=40;
			vRight =-40;
		
		}
		/*
		else{
			vLeft=-30;
			vRight =-40;
		}
		*/

    std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;

	setMotors(vLeft,vRight);   
       //usleep(10000);

  } //while

  



} // main
