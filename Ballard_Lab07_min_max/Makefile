min_max: main.o
		g++ -g -std=c++11 main.o  -o Min_max
main.o: main.cpp   min_max.h
	g++ -g -std=c++11 -c main.cpp  min_max.h
Min_max.o: min_max.h min_max.hpp
	g++ -Wall -std=c++11 -c min_max.hpp
clean:
		rm *.o Min_max
