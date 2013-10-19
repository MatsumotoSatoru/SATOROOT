#include "TF1.h"
#include "TMath.h"
TF1 *sinfunction(){
  TF1 *f = new TF1("f","TMath::Sin(x)") ;
  f->Draw() ;
  return f ;
}
