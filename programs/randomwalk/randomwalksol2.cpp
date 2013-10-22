#include "TRandom3.h"
#include "TCanvas.h"
#include "TGraph.h"

TCanvas *randomwalksol2(const int imax,double radius, char *name){
  double x[imax] = {0.} ;
  double y[imax] = {0.} ;
  double deltax ;
  double deltay ;
  
  TRandom3 RandomGenerator(unsigned(time(NULL))) ;
  TCanvas *c1 = new TCanvas("c1", "c1", 600,600) ;
  c1->SetGrid(1,1) ;  
  for(int i = 1 ; i < imax ;i++){
    RandomGenerator.Circle(deltax, deltay, radius) ; // 半径radiusの円周上に一様に乱数を生成する。
    x[i] = deltax + x[i-1]; // 前の座標からdeltaxだけ移動する
    y[i] = deltay + y[i-1]; // 前の座標からdeltayだけ移動する
  }
  TGraph  *f  = new TGraph(imax, x, y) ;
  f->SetLineStyle(1) ;
  f->SetLineWidth(2) ;
  f->SetLineColor(kRed) ;
  f->SetMarkerStyle(1) ;
  f->SetMarkerSize(1.1) ;
  f->SetMarkerColor(kBlue) ;

  f->Draw("APL") ;
  c1->SaveAs(Form("%s_radius%3.1f_imax%d.eps", name,radius,imax));
  return c1 ;
}
