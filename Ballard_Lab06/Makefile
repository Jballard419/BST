Min_heap: main.o test.o
	g++ -g -std=c++11 main.o  -o Min_heap
	g++ -g -std=c++11 test.o  -o Test_bench
test.o: test.cpp  binary_seach_tree.h min-kheap.h
	g++ -g -std=c++11 -c test.cpp  binary_seach_tree.h min-kheap.h
main.o: main.cpp  binary_seach_tree.h min-kheap.h
	g++ -g -std=c++11 -c main.cpp  binary_seach_tree.h min-kheap.h
min-kheap.o: min-kheap.h min-kheap.hpp
	g++ -Wall -std=c++11 -c min-kheap.hpp
binary_seach_tree.o: binary_seach_tree.h binary_seach_tree.hpp
	g++ -Wall -std=c++11 -c binary_seach_tree.hpp
Linkedlist.o: linkedlist.h linkedlist.hpp
	g++ -Wall -std=c++11 -c linkedlist.h
node.o: node.h node.hpp
	g++ -Wall -std=c++11 -c node.h
clean:
	rm *.o *.gch Min_heap Test_bench
tar: clean
	-mkdir Ballard_Lab05
	cp * Ballard_Lab05
	tar cfzv Ballard_Lab05.tar.gz Ballard_Lab05
	-rm -rf Ballard_Lab05
