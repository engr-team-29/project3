#include "robot.hpp"
/*****Line reading, values for lines from image*****/
struct LineReading{
	double leftLine=0;
	double leftPosition=0;
	double rightLine=0;
	double rightPosition=0;
	double topLine=0;
	double topPosition=0;
	double bottomLine=0;
	double bottomPosition=0;
};
/*****Red lines, values for red borders from image*****/
struct RedLines{
	int redRow=0; //in the row ahead, how many red columns
	int otherRow=0; //this row is closer to the robot. if its red then the robot is near boundray and needs to move back
	int leftSide=0; //how many columns wide is the left side (or portion of it which in the image)
	int rightSide=0; //how many columns wide is the right side (or portion of it which in the image)
};

LineReading renderImageCompletion(){
	LineReading reading; // this is the struct which stores the values
	for(int row=0; row<cameraView.height; row++){
		for(int col=0; col<cameraView.width; col++){
			//for every pixel in the image:
			int brightness = get_pixel(cameraView, row, col, 3); //how much rgb is in pixel
			if(brightness>=250){
				if(col == 0){    
					//for first column only:  
					reading.leftPosition += row;//increase total positions of left line by this value
					reading.leftLine++; //increase the number of values for left line
				}
				else if(col == cameraView.width-1){
					//for the last column do the same as above but for right
					reading.rightPosition += row;
					reading.rightLine++;
				}
				if(row == 0){
					//for the highest row, do the same as for left but for top line
					reading.topPosition += col;
					reading.topLine++;
				}
				else if(row==cameraView.height-1){
					//for last row, do same as above but for bottom line
					reading.bottomPosition += col;
					reading.bottomLine++;
				}
			}
		}
	}
	return reading; //return the values so the motors can be set appriately
}

RedLines renderImageChallenge(){
	int checkRow = (1.0*cameraView.height)/5.0; //the row which is checked
	int redRow = 0; //varible stores the size of red line
	/* for each col, check if the specifeid row is red. if so, start counting/increase the number of red pixels in that row */
	for(int col=0; col<cameraView.width; col++){
		int redness = get_pixel(cameraView, checkRow, col, 0); //how much red is in the pixel
			int nonRed = get_pixel(cameraView, checkRow, col, 1); //how much other colours are in the pixel
			if(redness>nonRed*1.05+0.01){
				//if there is more red then other colours (multiplied by 1.05) increase the red
				redRow++;
			}
	}
	int otherRow=0;
	int otherCheckedRow = (cameraView.height*4.0)/5.0;
	for(int col=0; col<cameraView.width; col++){
		int redness = get_pixel(cameraView, otherCheckedRow, col, 0); //how much red is in the pixel
			int nonRed = get_pixel(cameraView, otherCheckedRow, col, 1); //how much other colours are in the pixel
			if(redness>nonRed*1.05){
				//if there is more red then other colours (multiplied by 1.05) increase the red
				otherRow++;
			}
	}
	int borderThicknes=14; //the number of cols checked for the left/right borders
	int leftSide=0; //size of left red border
	/* for columns from the left, counting the size of left side */
	for(int col=0; col<borderThicknes; col++){
		bool containsRed=false; //number of reds in the column
		for(int row=checkRow++; row<cameraView.height; row++){
			//for each pixel:
			int redness = get_pixel(cameraView, row, col, 0); //amont of red in pixel
			int nonRed = get_pixel(cameraView, row, col, 1); //amount of other colors in pixel
			if(redness>nonRed*1.05+0.01){
				//if pixel is red, increase count
				containsRed=true;
			}
		}
		if(containsRed){
			//everytime some red was in the column so increase the width of left border
			leftSide++;
		}
	}
	int rightSide=0; //thickness of right border
	/* counts the number of columns with red from the right (in the red-most section of red) */
	for(int col=cameraView.width-1; col>cameraView.width-borderThicknes-1; col--){
		bool containsRed=false;
	for(int row=checkRow++; row<cameraView.height; row++){
		//for every pixel:
		int redness = get_pixel(cameraView, row, col, 0); //amount of red in pixel
			int nonRed = (get_pixel(cameraView, row, col, 1)); //average of green/blue in pixel
			if(redness>nonRed*1.05+1){
				//if its red and currently counting the right border, the border is increased in thickness
				containsRed=true;
			}
	}
	if(containsRed){
		//for each column with red in it, increase the thickness of right side
		rightSide++;
	}
}

	std::cout<<"left"<<leftSide<<" right="<<rightSide<<" row="<<redRow<<" other="<<otherRow<<std::endl; //prints thickness of left/right and width of row ahead
	//int checkRight = cameraView.width-1;
	
	RedLines lines; //stuct used to return values to set motors
	lines.redRow = redRow;
	lines.otherRow = otherRow;
	lines.rightSide = rightSide;
	lines.leftSide = leftSide;
	return lines;

}
