TEST: test.o
		g++ -g -std=c++11 test.o  -o Test_bench
test.o: test.cpp  skew_heap.h leftist_heap.h
		g++ -g -std=c++11 -c test.cpp  skew_heap.h leftist_heap.h
leftist_heap.o: leftist_heap.h leftist_heap.hpp
	g++ -Wall -std=c++11 -c leftist_heap.hpp
skew_heap.o: skew_heap.h skew_heap.hpp
	g++ -Wall -std=c++11 -c skew_heap.hpp
Linkedlist.o: linkedlist.h linkedlist.hpp
	g++ -Wall -std=c++11 -c linkedlist.h
node.o: node.h node.hpp
	g++ -Wall -std=c++11 -c node.h
clean:
	rm *.o *.gch  Test_bench
tar: clean
	-mkdir Ballard_Lab05
	cp * Ballard_Lab05
	tar cfzv Ballard_Lab05.tar.gz Ballard_Lab05
	-rm -rf Ballard_Lab05
