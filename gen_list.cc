#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

#include "TROOT.h"
#include "TString.h"

void gen_list(int bgn, int end, int step, int flag)
{

  TString roostr = "";
  roostr = TString::Format("exe_%02d.sh", flag);
  ofstream ListWrite(roostr, ios::out|ios::trunc);
  ListWrite<<"#!"<<endl;

  ///
  //TString roostr_file = "data_ext_tgm.list";
  TString roostr_file = "data_bnb_numu.list";
  
  ///
  ifstream InputFile_aa(roostr_file, ios::in);
  if(!InputFile_aa) {
    cerr<<" No input-list"<<endl;
    exit(1);
  }

  int line_aa = 0;
  while( !InputFile_aa.eof() ) {
    line_aa++;
    InputFile_aa>>roostr;
  }
  line_aa -= 1;
  cout<<endl<<TString::Format("Input-list line: %4d", line_aa)<<endl<<endl;

  ///
  ifstream InputFile_ab(roostr_file, ios::in);
  
  for(int idx=1; idx<=line_aa; idx++) {

    InputFile_ab>>roostr;
    
    if( idx<bgn || idx>end ) continue;

    ListWrite<<TString::Format("dev-wire-cell-tpc-light ./ChannelWireGeometry_v2.txt ")<< roostr <<endl;
  }

  ListWrite.close();

  cout<<endl<<" chmod 744 *.sh"<<endl<<endl;
  
  // cout<<endl;
  // for(int idx=bgn; idx<=end; idx++) {
  //   int sub_bgn = (idx-1)*step+1;
  //   int sub_end = idx*step;

  //   //cout<<TString::Format("root -b -q read_Teval.cc+(%d, %d)", sub_bgn, sub_end)<<endl;
  //   //ListWrite<<"sleep 2"<<endl;
  //   //cout<<TString::Format("echo %6d %6d", sub_bgn, sub_end)<<endl;

  //   ListWrite<<TString::Format("./main_read_speb -b %6d -e %6d", sub_bgn, sub_end)<<endl;
  // }
  // cout<<endl;

  // ListWrite.close();
}
