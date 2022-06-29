void xyDetetores(){
TFile *f = new TFile("AmberTarget_Run_1.root","READ");

TTree *dados = (TTree*)f->Get("tracksData");

Int_t nGraphs = 4;
TGraph *graphDetetor [nGraphs];
TCanvas *canvasDetetor [nGraphs];

Int_t nBins=500;
Double_t minBin=-20;
Double_t maxBin=20;

dados->SetBranchStatus("*",0);
Long64_t Nentries = dados->GetEntries();

Double_t X;
Double_t Y;
TString xBranchName;
TString yBranchName;
TString graphTitle;
TString canvasTitle;

for (Int_t k = 0; k < nGraphs; k++)
{
	xBranchName="X"+TString::Itoa(k,10)+"_cm";
	yBranchName="Y"+TString::Itoa(k,10)+"_cm";
	dados->SetBranchStatus(xBranchName,1);
	dados->SetBranchStatus(yBranchName,1);
	dados->SetBranchAddress(xBranchName,&X);
	dados->SetBranchAddress(yBranchName,&Y);
	graphDetetor[k] = new TGraph();
	for (Int_t i = 0; i < Nentries; i++)
	{
		dados->GetEntry(i);
		graphDetetor[k]->AddPoint(X,Y);
	}
	graphTitle="Hits no Detector "+TString::Itoa(k,10)+";X(cm);Y(cm)";
	canvasTitle="Hits no Detector "+TString::Itoa(k,10);
	graphDetetor[k]->SetTitle(graphTitle);
	canvasDetetor[k] = new TCanvas();
	canvasDetetor[k]->SetTitle(canvasTitle);
	graphDetetor[k]->Draw("AP");
}

}
