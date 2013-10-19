#include "TCanvas.h"
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"

TH1D *meettree2(char *InputRootFileName){
  
  TCanvas *c1 = new TCanvas("c1", "c1") ;
  TFile *file = new TFile(InputRootFileName,"READ") ;
  TTree *t = (TTree*)file->Get("tree") ;
  
  TH1D *h = new TH1D("h","TDC",100, 0., 8000e-9) ; // 8000[ns]
  t->Draw("tdc>>h") ;
  
  c1->cd() ;
  h->Draw() ;
  
  return h ;
}
