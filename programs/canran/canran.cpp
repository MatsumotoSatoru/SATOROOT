#include "TRandom3.h"
#include "TCanvas.h"
#include "TH1.h"
TCanvas *canran(){
  TCanvas *c1 = new TCanvas("c1","c1",600,600) ;
  TRandom3 *r = new TRandom3();
  TH1D *h = new TH1D("h","h-title;x;y",100,-5,5) ;
  for(int i = 0 ; i<100000 ; i++){
    h->Fill(r->Uniform(-3.,3.)) ;
  }
  h->Draw("HE") ;
  c1->SaveAs("c1.eps") ;
  return c1 ;
}
