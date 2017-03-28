#include "leftist_heap.h"
#include <fstream>

void printMenu() //prints the options available to the user
{
  std::cout << ".........................................................." << '\n';
  std::cout<<"\n"<<std::endl;
	std::cout<<"Select an action:"<<std::endl;
	std::cout<<"1) insert"<<std::endl;

	std::cout<<"2) deletemin"<<std::endl;

  std::cout<<"3) preorder"<<std::endl;
  std::cout<<"4) inorder"<<std::endl;
  std::cout<<"5) levelorder"<<std::endl;
	std::cout<<"6) Exit"<<std::endl;


}

int main(int argc, char const *argv[]) {
  /* code */
  if (argc != 2)
  {
    std::cout << "file didn't load use like this " << '\n';
    std::cout << "./Leftist_Heap data.txt" << '\n';
  }
  std::ifstream in(argv[1]);


  Leftist_Heap<int>* tree = new Leftist_Heap<int>();
  int input;
  int value;
  int dummy;
  while(true)
  {
    if (!(in>>value)){ break;}
    tree->insert(value);
  }


  do {
printMenu();
std::cin >> input;
  switch (input)
  {
    case 1:
      std::cout << "Choose a number to be added to the list:" << '\n';
      std::cin >> input;
      tree->insert(input);
      input = 0;
      break;


    case 2:
       tree->deletemin();
      break;


    case 3:
      std::cout << "preorder :" ;
      tree->preorder();
      std::cout << "\n" ;
      break;
    case 4:
      std::cout << "inorder :" ;
      tree->inorder();
      std::cout << "\n" ;
      break;
    case 5:
      std::cout << "levelorder :" ;
      tree->levelorder();
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
