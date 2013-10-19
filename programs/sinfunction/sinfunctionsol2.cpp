#include "TF1.h"
#include "TMath.h"
TF1 *sinfunctionsol2(){
  double pi = TMath::Pi() ;
  TF1 *f = new TF1("f","[0]*TMath::Sin([1]*x)", -pi, pi) ;
  f->SetParameter(0, 2.) ;
  f->SetParameter(1, 0.5) ;
  f->Draw() ;
  return f ;
}
