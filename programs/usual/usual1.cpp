#include <iostream>
#include "TMath.h"
void usual1(int i){
  std::cout << i << std::endl ;
  std::cout << TMath::Power(i,2) << std::endl ;
  std::cout << TMath::Power(i,3) << std::endl ;
}
