#include "TCanvas.h"
#include "TF2.h"
#include "TH2.h"
#include "TMath.h"
#include "TPad.h"
#include "TPaveStats.h"
#include "TRandom.h"
#include "TString.h"
#include "TStyle.h"

#include <iostream>
int main(int argc, char** argv){
  if(argc!=2){
    std::cerr << "### Usage like ... \n   ./gaus2d 10000(imax)" << std::endl ;
    return EXIT_FAILURE ;
  }
  else{/* DO NOT ANYTHING */}
  
  double x ;
  double y ;
  int imax = atoi(argv[1]) ;
  TString title("2D Gaussian") ;
  TString titleimax(argv[1])   ;
  title += titleimax ;
  
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600) ;
  gStyle->SetOptStat("enRM") ;
    
  TH2D *hist    = new TH2D("hist",title,100, -5., 5., 100, -5., 5.) ;
  TF2 *gausfunc = new TF2("gausfunc","[0]*TMath::Exp( - TMath::Sqrt(  TMath::Power((x-[1])/[2],2)/2. + TMath::Power((y-[3])/[4],2)/2. ))", -5., 5., -5., 5.) ;
  gausfunc->SetParameters(1., 0., 0.5, 0., 0.5) ;
  gausfunc->SetNpx(300) ;
  gausfunc->SetNpy(300) ;

  gRandom->SetSeed(unsigned(time(NULL))) ;
  for(int i =0 ; i< imax ; i++){
    gausfunc->GetRandom2(x,y) ;
    hist->Fill(x,y) ;
  }
  hist->Draw("colz") ;
  gPad->Update();
  TPaveStats *st = (TPaveStats*)hist->FindObject("stats") ;
  st->SetX1NDC(0.65) ;
  st->SetX2NDC(0.90) ;
  st->SetY1NDC(0.70) ;
  st->SetY2NDC(0.90) ;
  
  c1->SaveAs("gaus2dc1.eps") ;
  delete c1 ;
  delete hist ;
  delete gausfunc ;
  return EXIT_SUCCESS ;
}
