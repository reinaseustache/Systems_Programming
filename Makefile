all: main.o readButtonPress.o binaryCounter.o
	gcc -o binaryCounter main.o readButtonPress.o binaryCounter.o -lbcm2835

main.o: main.c main.h readButtonPress.c readButtonPress.h binaryCounter.c binaryCounter.h
	gcc -c main.c readButtonPress.c binaryCounter.c

readButtonPress.o: readButtonPress.c readButtonPress.h
	gcc -c readButtonPress.c

binaryCounter.o: binaryCounter.c binaryCounter.h
	gcc -c binaryCounter.c

clean:
	rm *.o
