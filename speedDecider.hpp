/**
* function which sets the speeds of motors depending on the resence of lines in the image taken by the camera
*/
void setMotorCompletion(LineReading reading){
	//varibles
		double vLeft = 40.0; //left motor speed
		double vRight = 40.0; //right motor speed
        double delta = 20;
        if(reading.rightLine>0){
			//go right if there is a line to the right
			 double row = reading.rightPosition/reading.rightLine;
			 delta = (row/cameraView.height)*(15);
			vLeft = vLeft + 5+delta;
			 vRight = vRight- 5-delta;
			}
		else if(reading.topLine==0 && reading.bottomLine>0 && reading.leftLine==0){
			//if there is a line at the bottom but not to the left, right or top, the robot is at a dead end and should spin around
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
			 //go left if there is no line ahead or to right
			 double row = reading.leftPosition/reading.leftLine;
			 delta = (row/cameraView.height)*15;
			vLeft = vLeft - 5-delta;
			 vRight = vRight+ 5+delta;
			}
		else{
			//no lines found so go straight back in hopes of returning to lines
			vLeft =-40;
			vRight =-40;
		}		
	
    std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl; //prints speeds of motors

	setMotors(vLeft,vRight);   // sets motors to desired speeds
     usleep(10000);
	//prints the indexes of the lines:
     std::cout<<std::endl<<"left:"<<reading.leftPosition/(1+reading.leftLine)<<" right:"<<reading.rightPosition/(1+reading.rightLine)<<" top:"<<reading.topPosition/(1+reading.topLine)<<" bottom:"<<reading.bottomPosition/(1+reading.bottomLine)<<std::endl;    // Prints the average

}
