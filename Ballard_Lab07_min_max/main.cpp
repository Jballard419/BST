#include "min_max.h"
#include <fstream>

void printMenu() //prints the options available to the user
{
  std::cout << ".........................................................." << '\n';
  std::cout<<"\n"<<std::endl;
	std::cout<<"Select an action:"<<std::endl;
	std::cout<<"1) insert"<<std::endl;

	std::cout<<"2) deletemin"<<std::endl;
  std::cout<<"3) deletemax"<<std::endl;
  std::cout<<"4) levelorder"<<std::endl;
	std::cout<<"5) Exit"<<std::endl;


}

int main(int argc, char const *argv[]) {
  /* code */
  if (argc != 2)
  {
    std::cout << "file didn't load use like this " << '\n';
    std::cout << "./BST data.txt" << '\n';
  }
  std::ifstream in(argv[1]);


  min_max_heap<int>* min_max = new min_max_heap<int>(2, 200);
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
  min_max->bottom_up(A, i);


  do {
printMenu();
std::cin >> input;
  switch (input)
  {
    case 1:
      std::cout << "Choose a number to be added to the list:" << '\n';
      std::cin >> input;
      min_max->insert( input);
      input = 0;
      break;



    case 2:
      min_max->deletemin();
      break;
    case 3:
      min_max->deletemax();
      break;


    case 4:
      std::cout << "levelorder :" ;
      min_max->levelorder();
      std::cout << "\n" ;
      break;
    case 5:
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
