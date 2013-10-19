#include "TH1.h"
#include <iostream>

TH1D *hist1sol1(){
  std::cout << "Start!!" << std::endl;
  TH1D *h = new TH1D("h","h",100,-5.,5.);
  h->FillRandom("gaus") ;
  h->Draw("E");
  return h;
}
