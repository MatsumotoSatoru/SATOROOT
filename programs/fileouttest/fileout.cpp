#include "TCanvas.h"
#include "TH1.h"
#include "TMath.h"
#include "TRandom3.h"
#include <fstream>
#include <iostream>
TCanvas *fileout(){
  std::ofstream outputfile;
  // file の出力先
  outputfile.open("output.plt" );// file を開く
  TRandom3 Random(unsigned(time(NULL)));
  TCanvas *c1 = new TCanvas("c1","c1") ;
  int imax = 100000; // event 数の最大値
  double start ; // start の時刻を擬似的に与える。 
  double stop  ; // stop の時刻を擬似的に与える。 
  double tdc   ; // TDC でのカウント数を擬似的に与える。
  double life = 2.2e-6 ; // Muon の平均寿命を入力する。
  
  TH1D *h1 = new TH1D("h1","h1",200,0,8000e-9) ; // [s]
  for(int i = 0; i < imax; i++){
    start = Random.Uniform(0., 1.e-9) ; // start の時刻を擬似的に与える。
    stop = Random.Exp(life) ; // 指数関数に従った乱数だけ立った時刻を stop とする
    stop += start ; // start してから 指数関数に従った乱数だけ立った時刻を stop とする
    tdc = stop - start ; // このプログラムだけを見るとこの処理は余分な処理だが、TDC の理の為
    std::cout << tdc << " [s] :: " << start << "" << stop << std::endl;
    // output という出力先に start と stop をスペース区切りで出力する
    outputfile << start << " " << stop << " " << endl ;
    h1->Fill(tdc) ; // ヒストグラムに詰める
  }
  h1->Draw("H") ; // 確認用にヒストグラムを出力する。
  outputfile.close(); // ファイルを閉じる return c1 ;
}
