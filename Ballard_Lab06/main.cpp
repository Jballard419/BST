#include "binary_seach_tree.h"
#include "min-kheap.h"
#include <fstream>

void printMenu() //prints the options available to the user
{
  std::cout << ".........................................................." << '\n';
  std::cout<<"\n"<<std::endl;
	std::cout<<"Select an action:"<<std::endl;
	std::cout<<"1) insert"<<std::endl;
	std::cout<<"2) remove"<<std::endl;
	std::cout<<"3) deletemin"<<std::endl;
  std::cout<<"4) deletemax"<<std::endl;
  std::cout<<"6) levelorder"<<std::endl;
	std::cout<<"8) Exit"<<std::endl;


}

int main(int argc, char const *argv[]) {
  /* code */
  if (argc != 2)
  {
    std::cout << "file didn't load use like this " << '\n';
    std::cout << "./BST data.txt" << '\n';
  }
  std::ifstream in(argv[1]);


  k_heap<int>* min_heap = new k_heap<int>(3, 200);
  int input;
  int value;
  int* A = new int[200];
  int i=0;
  while(i<200)
  {
    if (!(in>>value)){ break;}
    A[i]=value;
    i++;
  }
  min_heap->drake(A, i);


  do {
printMenu();
std::cin >> input;
  switch (input)
  {
    case 1:
      std::cout << "Choose a number to be added to the list:" << '\n';
      std::cin >> input;
      min_heap->insert( input);
      input = 0;
      break;

    case 2:
      std::cout << "Choose a number to be deleted from the list:" << '\n';
      std::cin >> input;
      min_heap->remove_node(input);
      input = 0;
      break;

    case 3:
      min_heap->deletemin();
      break;
    case 4:
      min_heap->deletemax();
      break;


    case 5:
      std::cout << "levelorder :" ;
      min_heap->levelorder();
      std::cout << "\n" ;
      break;
    case 6:
      input = -1;
      break;


    default:
      std::cout << "invalid input" << '\n';
      input = 0;
      break;

  }
  if(input == -1)
  {break;}
} while(true);
  return 0;
}
