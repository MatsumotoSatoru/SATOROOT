#include "iostream"
int cube(int a) ;

int main(int argc, char** argv){
  std::cout << cube(4) << std::endl ;
  return EXIT_SUCCESS ;
}

int cube(int a){
  return a*a*a ;
}
