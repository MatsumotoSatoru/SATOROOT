#include "head.h"
#include <iostream>
int cube(int a) ;

int main(int argc, char** argv){
  if(argc != 2){
    std::cout << "Usage like \n   ./main 4" << std::endl ;
  }
  int i ;
  i = atoi(argv[1]) ;
  
  std::cout << cube(i) << std::endl ;
  return EXIT_SUCCESS ;
}
