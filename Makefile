all: I2C.o PWM.o MotorHat.o Robot.o RobotTest.o Sensor.o
	gcc -o Robi I2C.o PWM.o MotorHat.o Robot.o RobotTest.o Sensor.o -lbcm2835 -lm -pthread

RobotTest.o: RobotTest.c RobotTest.h Robot.c Robot.h MotorHat.c MotorHat.h PWM.c PWM.h I2C.c I2C.h Sensor.c Sensor.h
	gcc -c RobotTest.c Robot.c MotorHat.c PWM.c I2C.c Sensor.c

Robot.o: Robot.c Robot.h MotorHat.c MotorHat.h PWM.c PWM.h I2C.c I2C.h
	gcc -c Robot.c MotorHat.c PWM.c I2C.c

MotorHat.o: MotorHat.c MotorHat.h PWM.c PWM.h I2C.c I2C.h
	gcc -c MotorHat.c PWM.c I2C.c

PWM.o: PWM.c PWM.h I2C.c I2C.h
	gcc -c PWM.c I2C.c

I2C.o: I2C.c I2C.h
	gcc -c I2C.c

Sensor.o: Sensor.c Sensor.h
	gcc -c Sensor.c

clean:
	rm *.o
