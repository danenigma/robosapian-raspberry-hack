gcc -c robot.c -l wiringPi
g++ -c robot_command.cpp
g++ robot.o robot_command.o -l wiringPi -o robot
sudo ./robot 
