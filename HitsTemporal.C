void HitsTemporal(){
TFile *f = new TFile("AmberTarget_Run_1.root","READ");

TTree *dados = (TTree*)f->Get("Hits");

Int_t nHistos = 4;
TH1F *histoDetetor [nHistos];

Int_t nBins=500;
Double_t minBin=0;
Double_t maxBin=10;
Double_t particleTime;
Int_t detetorID;

dados->SetBranchStatus("*",0);
Long64_t Nentries = dados->GetEntries();

TString canvasTitle;

TCanvas *detetor0 = new TCanvas("Detetor0","Detetor0");
TCanvas *detetor1 = new TCanvas("Detetor1","Detetor1");
TCanvas *detetor2 = new TCanvas("Detetor2","Detetor2");
TCanvas *detetor3 = new TCanvas("Detetor3","Detetor3");

canvasTitle="Hits por tempo no Detector 0";
histoDetetor[0] = new TH1F(canvasTitle,canvasTitle,nBins,minBin,maxBin);
canvasTitle="Hits por tempo no Detector 1";
histoDetetor[1] = new TH1F(canvasTitle,canvasTitle,nBins,minBin,maxBin);
canvasTitle="Hits por tempo no Detector 2";
histoDetetor[2] = new TH1F(canvasTitle,canvasTitle,nBins,minBin,maxBin);
canvasTitle="Hits por tempo no Detector 3";
histoDetetor[3] = new TH1F(canvasTitle,canvasTitle,nBins,minBin,maxBin);

dados->SetBranchStatus("detectorID",1);
dados->SetBranchStatus("particleHitTime_ns",1);
dados->SetBranchAddress("detectorID",&detetorID);
dados->SetBranchAddress("particleHitTime_ns",&particleTime);
for (Int_t i = 0; i < Nentries; i++)
{
	dados->GetEntry(i);
	histoDetetor[detetorID]->Fill(particleTime);
}

for (Int_t i = 0; i < nHistos;i++)
{
	histoDetetor[i]->SetFillColor(i+1);
	histoDetetor[i]->SetLineColor(i+1);
}
histoDetetor[3]->Draw();
detetor0->cd();
histoDetetor[0]->Draw();
detetor1->cd();
histoDetetor[1]->Draw();
detetor2->cd();
histoDetetor[2]->Draw();
detetor3->cd();

}