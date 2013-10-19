#include "TRandom3.h"
#include "TCanvas.h"
#include "TGraph2D.h"

TCanvas *randomwalk(){
  const int imax = 20 ;
  double x[imax] = {0.} ;
  double y[imax] = {0.} ;

  TRandom3 RandomGenerator(unsigned(time(NULL))) ;
  TCanvas *c1 = new TCanvas("c1", "c1", 600,600) ;
  
  for(int i = 1 ; i < imax ;i++){
    x[i] = RandomGenerator.Uniform(-1., 1.) + x[i] ; // 前の位置から[-1,1]だけx座標を移動
    y[i] = RandomGenerator.Uniform(-1., 1.) + y[i] ; // 前の位置から[-1,1]だけy座標を移動
  }
  TGraph  *f  = new TGraph(imax, x, y) ;
  f->SetLineStyle(1) ;
  f->SetLineWidth(2) ;
  f->SetLineColor(kRed) ;
  f->SetMarkerStyle(20) ;
  f->SetMarkerSize(1.1) ;
  f->SetMarkerColor(kBlue) ;

  f->Draw("APL") ;
}
