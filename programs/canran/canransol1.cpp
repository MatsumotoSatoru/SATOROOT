#include "TRandom3.h"
#include "TCanvas.h"
#include "TH1.h"
TCanvas *canransol1(){
  TCanvas *c1 = new TCanvas("c1","c1",600,600) ;
  TRandom3 *r = new TRandom3() ;
  //  r->SetSeed() ;
  //  TRandom3 *r = new TRandom3(unsigned (time(NULL))) ;
  r->SetSeed(unsigned (time(NULL))) ;
  
  TH1D *h = new TH1D("h","h-title;x;y",100,-5,5) ;
  for(int i = 0 ; i<100000 ; i++){
    h->Fill(r->Uniform(-3.,3.)) ;
  }
  h->Draw("HE") ;
  c1->SaveAs("c1.eps") ;
  return c1 ;
}
