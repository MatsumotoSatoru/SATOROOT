#include "TGraph.h"
#include "TCanvas.h"

TCanvas *plateauplotsol1(char *datafilename)){
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600) ;
  c1->SetGrid(1,1) ;
  c1->SetLogy() ;
  c1->SetLeftMargin(0.14) ;
  TGraph *f = new TGraph(datafilename, "%lf %lf") ;
  f->SetMarkerStyle(20) ;
  f->SetMarkerSize(1.1) ;
  f->SetMarkerColor(kRed) ;
  f->SetTitle("Plateau Curve") ;
  f->GetXaxis()->SetTitle("Voltage[V]") ;
  f->GetYaxis()->SetTitle("Counts[c/min]") ;
  f->GetYaxis()->SetTitleOffset(1.4) ;
  f->Draw("AP") ;
  return c1 ;
}
