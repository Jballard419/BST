Leftist_Heap: main.o
	g++ -g -std=c++11 main.o  -o Leftist_Heap
main.o: main.cpp  leftist_heap.h
	g++ -g -std=c++11 -c main.cpp  leftist_heap.h
leftist_heap.o: leftist_heap.h leftist_heap.hpp
	g++ -Wall -std=c++11 -c leftist_heap.hpp
Linkedlist.o: linkedlist.h linkedlist.hpp
	g++ -Wall -std=c++11 -c linkedlist.h
node.o: node.h node.hpp
	g++ -Wall -std=c++11 -c node.h
clean:
	rm *.o *.gch Leftist_Heap
tar: clean
	-mkdir Ballard_Lab05
	cp * Ballard_Lab05
	tar cfzv Ballard_Lab05.tar.gz Ballard_Lab05
	-rm -rf Ballard_Lab05
