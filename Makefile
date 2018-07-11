default: main

all: main

main: main.o food.o
	g++ -o main -Wall -pedantic -g main.o
	rm -f *.o

main.o: food.o
	g++ -Wall -pedantic -g -c main.cpp

food.o: 
	g++ -Wall -pedantic -g -c food.cpp

clean:
	rm -f *.exe
	rm -f *.o
	rm -f *.exe.stackdump

rmvobjects:
	rm -f *.o

backup: Makefile *.cpp
	cp Makefile *.cpp Backup
