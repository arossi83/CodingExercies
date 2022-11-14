void macroHist(TString fname){

  //Aprire il file di testo
  ifstream file;
  file.open(fname);

  //Creare istogrammi
  TH1F* h1=new TH1F("h1","Istogramma 1",100,-10,10);
  TH1F* h2=new TH1F("h2","Istogramma 2",100,-10,10);
  TH2F* h3=new TH2F("h3","Istrogramma 2D",100,-10,10,100,-10,10);
  
  //Loop per leggere i dati
  Double_t a,b;
  while(file.good()){
    file>>a>>b;
    h1->Fill(a);
    h2->Fill(b);
    h3->Fill(a,b);
  }

  //Plot degli istogrammi
  /*Singole Canvas
  TCanvas* c=new TCanvas();
  h1->Draw();
  TCanvas* c2=new TCanvas();
  h2->Draw();
  */

  TCanvas* c=new TCanvas();
  c->Divide(2,2);
  c->cd(1);
  h3->Draw("colz");
  c->cd(2);
  h2->Draw();
  c->cd(3);
  h1->Draw();
  

  return;
}
