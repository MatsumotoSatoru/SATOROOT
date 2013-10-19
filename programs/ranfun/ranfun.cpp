#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TMath.h"
#include "TStyle.h"

TH1D *ranfun(){
  double range_min = 0. ; // 0 [ns]
  double range_max = 8000.e-9 ;// 8000 [ns]
  double tau       = 2.2e-6 ; // it means lifetime
  double bgd = 0.5 ; // Back Ground
  int nbin = 100 ; // histgram bin num
  int imax = 100000 ; // event
  
  TCanvas *c1 = new TCanvas("c1","c1",600,600) ;
  c1->SetGrid(1,1) ; // Canvas c1 にグリッドを描く
  c1->SetLogy(1) ;  // Canvas c1 の縦軸をlogで
  gStyle->SetOptFit(1) ;

  TF1 *f = new TF1("f","TMath::Exp(-x/[0])+[1]", range_min, range_max) ;
  f->SetParameter(0, tau) ;
  f->SetParameter(1, bgd) ;
  //  f->SetParameters(tau,bgd) ; // <--上の二行はこの一行と等価

  TH1D *h = new TH1D("h","Decay curve (Muon);TDC [s] ; Counts ", nbin, range_min, range_max);
  /*
    h->GetXaxis()->CenterTitle() ;
    h->GetYaxis()->CenterTitle() ;
    h->GetYaxis()->SetTitleOffset(1.4) ;
    h->SetFillStyle(3002) ;
    h->SetFillColor(kRed-4) ;
    h->SetLineColor(kRed) ;
    h->SetLineWidth(2) ;
  */
  for(int i=0; i < imax; i++){
    h->Fill(f->GetRandom()) ;
  }
  h->Draw("HE") ;
  return h ;
}
