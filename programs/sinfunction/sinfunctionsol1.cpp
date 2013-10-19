#include "TF1.h"
#include "TMath.h"
TF1 *sinfunctionsol1(){
  double pi = TMath::Pi() ;
  TF1 *f = new TF1("f","TMath::Sin(x)", -pi, pi) ;
  f->Draw() ;
  return f ;
}
