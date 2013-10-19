#include "TF1.h"
#include "TMath.h"
TF1 *sinfunctionsol3(){
  double pi = TMath::Pi() ;
  TF1 *f = new TF1("f","TMath::Sin(x)", -pi, pi) ;
  TF1 *f2 = new TF1("f2","TMath::Cos(x)", -pi, pi) ;
  f->SetLineColor(kRed) ;
  f2->SetLineColor(kGreen) ;

  f->Draw() ;
  f2->Draw("same") ;
  return f ;
}
