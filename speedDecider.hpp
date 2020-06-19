/**
 * sets the motor speed for core/completion based on where the line is present 
 */
void setMotorCompletion(LineReading reading){
		
		double vLeft = 40.0; //default value of left motor
		double vRight = 40.0; // default value of right motor
        double delta = 20;
        if(reading.rightLine>0){
			//go right if there is a line to the right
			 double row = reading.rightPosition/reading.rightLine;
			 delta = (row/cameraView.height)*(15); //how much the values should change. depends on row of white line and height of image ratio
			 vLeft = vLeft + 5+delta;
			 vRight = vRight- 5-delta;
			}
		else if(reading.topLine==0 && reading.bottomLine>0 && reading.leftLine==0){
			//otherwise if there is no line in front, but there is on behind and on to the left: turn right on the spot to find itself
			vLeft=-40;
			vRight =0;
		
		}
         else if(reading.topLine>0){
			 //go foward if no line to the right but there is one foward
			 double col = reading.topPosition/reading.topLine;
			 double difference = cameraView.width/2 - col;
			 double delta = 30*(difference/cameraView.width);
			 vLeft -= delta;
			 vRight += delta;
		 }
		 else if(reading.leftLine>0){
			 //go left if thats the only option
			 double row = reading.leftPosition/reading.leftLine;
			 delta = (row/cameraView.height)*15; //how much the values should change. depends on row of white line and height of image ratio
			vLeft = vLeft - 5-delta;
			 vRight = vRight+ 5+delta;
			}
		else{
			//car is lost, move backwards
			vLeft =-40;
			vRight =-40;
		}		
	//prints the values for left/right motors
    std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;

	setMotors(vLeft,vRight); //sets motors
    //usleep(10000);
}

/**
 * sets motors for challenge based on whether there is red at a set row and how much of the left and right lines is on camera
 * the above information is passed in through a 'redlines' struct. see imagerender for more info on the struct
 */
void setMotorChallenge(RedLines border){
	LineReading checkIfWhite = renderImageCompletion(); //makes a 'linereading' (the struct used for core/completion) and searches for the white line
	//the below asks if there is a white line ahead, and if so move foward
	
	if(checkIfWhite.topLine>0){
		//go foward if no line to the right but there is one foward
		double col = checkIfWhite.topPosition/checkIfWhite.topLine;
		double difference = cameraView.width/2 - col;
		double delta = 30*(difference/cameraView.width);
		double vLeft =40- delta;
		double vRight =40+ delta;
		setMotors(vLeft,vRight);  
	}
	else{
		//if there is no white line, then use the red lines to set speeds
		int vLeft = 40;
		int vRight = 40;
		if(border.otherRow>border.rightSide+border.leftSide+10){
			vLeft = -40;
			vRight = -45;
		}
		else if(border.redRow>cameraView.width/2 & border.rightSide==0){
			//if the line ahead is not just the left line turn right (T-section)
			//int difference = border.redRow-border.rightSide;
			double difference = (1.0*border.redRow)/(1.0*cameraView.width/2);
			vLeft += difference*10.0; 
			vRight -= difference*10.0; 
		}
		
		else if(border.rightSide==0){
			//if there is no border to the right, turn right  & border.leftSide !=0
			double difference = (1.0*border.leftSide)/14.0;
			vLeft += 10.0*difference; 
			vRight -= 10.0*difference; 
		}
		else if (border.redRow<=cameraView.width/2){
			//otherwise, ahead must be clear so go foward.
			double difference = (border.leftSide-border.rightSide)/2.0; //uses difference to help the car find the middle of the path for easy turning
			vLeft += difference; 
			vRight -= difference; 
		}
		else if(border.leftSide ==0){
			double difference = (1.0*border.rightSide)/14.0;
			vLeft-=20;
			vRight+=20;
		}
		else{
			vLeft-=20;
			vRight+=20;
		}
		setMotors(vLeft, vRight); 
    std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
	}
}
