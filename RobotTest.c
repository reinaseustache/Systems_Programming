#include "RobotTest.h"

int distance = 0;

int main(){
	pthread_t tid[2];

	pthread_create(&tid[0], NULL, calculateDistance, NULL); // updates the distance
	pthread_create(&tid[1], NULL, runRobi, NULL); // moves Robi forward or backwards

	pthread_exit(0);
}

void *calculateDistance(void * null){
	while(1){
		distance = getDistance(); // update distance variable
	}
	pthread_exit(0);
}

void *runRobi(void * null){
	initRobot(); // initialize motors on the Robot
	sleep(3.0); // give distance thread time to calculate initial distance

	while(1){
		if (distance <= 30) { // to close to an object, move back
			stop();
			backward(75, 1.0);
			right(75, 0.5);
		}
		else{
			forward(75, 0);
		}
	}
	pthread_exit(0);
}
