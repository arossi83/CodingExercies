void leggiTree(TString fname){

  //Aprire il file root
  TFile* fin=new TFile(fname);
  //Acquisire il TTree
  TTree* t=(TTree*)fin->Get("tree");

  //Imposto indirizzi di memnoria
  Double_t a,b;
  t->SetBranchAddress("Data1",&a);
  t->SetBranchAddress("Data2",&b);

  //Istogrammi
  TH1F* h=new TH1F("h","Data2 senza taglio",300,-10,10);
  h->SetLineColor(kBlue+2);
  h->GetXaxis()->SetTitle("data2 [mm]");
  h->GetYaxis()->SetTitle("Entries");
  TH1F* hc=new TH1F("hc","Data2 con taglio",300,-10,10);
  hc->SetLineColor(kRed+2);
  
  //loop su Tree
  for(int i=0;i<t->GetEntries();i++){
    t->GetEntry(i);
    if(i%100==0) cout<<"Processing event "<<i<<endl;
    h->Fill(b);
    if(a>1) hc->Fill(b);
  }

  TCanvas* c=new TCanvas();
  h->Draw();
  hc->Draw("same");

  TLegend* leg=new TLegend(0.7,0.7,0.9,0.9);
  leg->AddEntry(h,"Senza Taglio","l");
  leg->AddEntry(hc,"Con Taglio","l");
  leg->Draw();
  
  return;
}
