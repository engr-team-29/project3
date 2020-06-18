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

LineReading renderImageCompletion(){
	LineReading reading;
			for(int row=0; row<cameraView.height; row++){
				for(int col=0; col<cameraView.width; col++){
					int brightness = get_pixel(cameraView, row, col, 3);
					bool isWhite = brightness>=250 |brightness<2; //includes black so that the car hits the flag in the end
					if(isWhite){
					if(col == 0){                                
						reading.leftPosition += row;
						reading.leftLine++;
					}
					else if(col == cameraView.width-1){
						
				 reading.rightPosition += row;
				 reading.rightLine++;
					}
					if(row == 0){
						
					reading.topPosition += col;
				 reading.topLine++;
						}
						else if(row==cameraView.height-1){
							
							reading.bottomPosition += col;
							reading.bottomLine++;
						}
				}
				}
			}
	return reading;
}
