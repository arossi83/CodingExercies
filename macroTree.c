void macroTree(TString fname){

  //Aprire file di testo
  ifstream file;
  file.open(fname);

  //Creare il Tree
  TFile* fout=new TFile("output.root","recreate");
  fout->cd();
  TTree* t=new TTree("tree","Semplice tree");
  //Creare i Branch
  Double_t a,b;
  t->Branch("Data1",&a,"Data1/D");
  t->Branch("Data2",&b,"Data2/D");

  while(file.good()){
    file>>a>>b;
    t->Fill();
  }

  //Scrivere il tutto su disco
  fout->Write();
  
  return;
}
