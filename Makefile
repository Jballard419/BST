BST: main.o
	g++ -g -std=c++11 main.o  -o BST
main.o: main.cpp  binary_seach_tree.h
	g++ -g -std=c++11 -c main.cpp  binary_seach_tree.h
binary_seach_tree.o: binary_seach_tree.h binary_seach_tree.hpp
	g++ -Wall -std=c++11 -c binary_seach_tree.hpp
Linkedlist.o: linkedlist.h linkedlist.hpp
	g++ -Wall -std=c++11 -c linkedlist.h
node.o: node.h node.hpp
	g++ -Wall -std=c++11 -c node.h
clean:
	rm *.o *.gch BST
tar: clean
	-mkdir Ballard_Lab05
	cp * Ballard_Lab05
	tar cfzv Ballard_Lab05.tar.gz Ballard_Lab05
	-rm -rf Ballard_Lab05
