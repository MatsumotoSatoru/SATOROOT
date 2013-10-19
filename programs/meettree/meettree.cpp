#include <fstream>
#include "TFile.h"
#include "TTree.h"

TTree *meettree(char *datafile, char *rootfile = "output.root"){

  double start ; // TDC start
  double stop  ; // TDC stop
  double tdc   ; // delta T
  
  TTree *tree = new TTree("tree","tree");  //TTree作成
  //Branch準備
  tree->Branch( "start", &start, "start/D" ); // start を格納する為のブランチ
  tree->Branch( "stop" , &stop , "stop/D" );  // stop を格納する為のブランチ
  tree->Branch( "tdc"  , &tdc  , "tdc/D" );   // start とstopの時間差 を格納する為のブランチ
  
  ifstream fin(datafile) ;
  while(fin >> start >> stop){
    tdc = stop - start ;
    tree->Fill() ;
  }
  
  TFile *fout = new TFile(rootfile, "recreate");
  tree->Write(); // treeを書き込む
  fout->Close(); // file close

  return tree ;
}
