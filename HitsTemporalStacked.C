void HitsTemporalStacked(){
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

TString detetorTitle;
TString histoName;
detetorTitle="Detector 0";
histoDetetor[0] = new TH1F(detetorTitle,detetorTitle,nBins,minBin,maxBin);
detetorTitle="Detector 1";
histoDetetor[1] = new TH1F(detetorTitle,detetorTitle,nBins,minBin,maxBin);
detetorTitle="Detector 2";
histoDetetor[2] = new TH1F(detetorTitle,detetorTitle,nBins,minBin,maxBin);
detetorTitle="Detector 3";
histoDetetor[3] = new TH1F(detetorTitle,detetorTitle,nBins,minBin,maxBin);

dados->SetBranchStatus("detectorID",1);
dados->SetBranchStatus("particleHitTime_ns",1);
dados->SetBranchAddress("detectorID",&detetorID);
dados->SetBranchAddress("particleHitTime_ns",&particleTime);
for (Int_t i = 0; i < Nentries; i++)
{
	dados->GetEntry(i);
	histoDetetor[detetorID]->Fill(particleTime);
}

THStack *hs = new THStack("hs","");
TCanvas *cs = new TCanvas("Hits por tempo dos detetores","Hits por tempo dos detetores",10,10,700,500);
TText T; T.SetTextFont(42); T.SetTextAlign(21);

for (Int_t i = 0; i < nHistos;i++)
{
	histoDetetor[i]->SetFillColor(i+1);
	histoDetetor[i]->SetLineColor(i+1);
	hs->Add(histoDetetor[i]);
}
hs->Draw("noclear");
T.DrawTextNDC(.5,.95," \"Hits nos Detetores\"");
cs->BuildLegend();

}
