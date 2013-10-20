#include "TGraph.h"
#include "TCanvas.h"

TCanvas *plateauplot(){
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600) ;
  TGraph *f = new TGraph("plateaudata.plt", "%lf %lf") ;
  f->Draw("AP") ;
  return c1 ;
}
