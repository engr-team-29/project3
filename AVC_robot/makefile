CFLAGS = -I C:\Users\helen\Desktop\Uni\ENGR101\avcProject\SFML\include
LFLAGS = -L C:\Users\helen\Desktop\Uni\ENGR101\avcProject\SFML\lib
LIBS = -lsfml-window  -lsfml-graphics -lsfml-system -lsfml-network 
robot: robot.o 
	g++ $(LFLAGS) -o robot robot.o ${LIBS} 
robot.o: robot.cpp 
	g++  -c $(CFLAGS) robot.cpp 


