#include "TCanvas.h"
#include "TH1.h"
#include <iostream>

int main(int argc, char** argv){
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600) ;
  TH1D *h = new TH1D("h", "h", 100, -5., 5.) ;
  h->FillRandom("gaus") ;
  h->Draw("E") ;
  c1->SaveAs("hist2c1.eps") ;
  delete h ;
  delete c1 ;
  return EXIT_SUCCESS ;
}
