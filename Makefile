#Corrina Lakin CS4280 P0

CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o scanner.o testScanner.o
TARGET = P1

P1: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o P1

main.o: main.cpp scanner.h token.h
	$(CC) $(CFLAGS) -c main.cpp

scanner.o: scanner.cpp scanner.h
	$(CC) $(CFLAGS) -c scanner.cpp

testScanner.o: testScanner.cpp
	$(CC) $(CFLAGS) -c testScanner.cpp

clean:
	rm *.o P1
