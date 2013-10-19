#include <fstream>
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TMath.h"
#include "TStyle.h"
using namespace std ;

TCanvas *filein(char *file_name){
  
  double range_min = 0. ;
  double range_max = 8000.e-9 ;// 8000 [ns]
  int nbin = 100 ;
  
  double start ; // TDC start
  double stop  ; // TDC stop
  double tdc   ; // delta T
  
  TCanvas *c1 = new TCanvas("c1","c1",600,600) ;
  c1->SetGrid(1,1); // Canvas c1 にグリッドを描く
  c1->SetLogy(1) ;  // Canvas c1 の縦軸をlogで
  gStyle->SetOptFit(1) ;
  
  TH1D *h = new TH1D(file_name,"Decay curve (Muon);TDC [s] ; Counts ", nbin, range_min, range_max);
  h->GetXaxis()->CenterTitle() ;
  h->GetYaxis()->CenterTitle() ;
  h->GetYaxis()->SetTitleOffset(1.4) ;
  h->SetFillStyle(3002) ;
  h->SetFillColor(kRed-4) ;
  h->SetLineColor(kRed) ;
  h->SetLineWidth(2) ;
  
  ifstream fin(file_name) ;
  while(fin >> start >> stop){
    tdc = stop - start ;
    h -> Fill(tdc) ;
  }
  
  h->Draw("HE");
  
  /******************************************************************************** \
 * Decay Curve Fitting
\********************************************************************************/
  TF1 *muon = new TF1("muon","[0]*(TMath::Exp(-x/[1])+[2])") ;
    muon->SetParameters(2e+3, 2e-6, 0.5) ;
    muon->SetLineColor(kBlue) ;
    muon->SetLineWidth(4) ;
    h->Fit(muon) ;
    
    return c1 ;
}
