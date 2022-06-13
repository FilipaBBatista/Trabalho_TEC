void QuatroHisto_stack(){

//ler ficheiro
TFile *ficheiro = new TFile("AmberTarget_Run_0.root", "READ");
//criar ficheiro
TFile *ficheiroGravar = new TFile("Histogramas.root", "RECREATE");
//buscar a arvore certa
TTree *dados = (TTree*)ficheiro->Get("edep_Per_Event");


Int_t nBins=500;
Double_t minBin=0.0;
Double_t maxBin=400000;

Int_t nHistos=4;

THStack *hs = new THStack("hs","");
TH1F* histoDetetor[nHistos];
TCanvas *canvas;
TString branchName;


canvas =new TCanvas("canvas","stacked hists",10,10,700,900);

for (Int_t i=0;i<nHistos;i++){
	TString histoName="histoDetetor"+TString::Itoa(i,10);
	histoDetetor[i]=new TH1F (histoName,histoName,nBins,minBin,maxBin);
	branchName="detector"+TString::Itoa(i,10);
	
	
	dados->Draw(branchName+">>"+histoName,branchName+">0");
	histoDetetor[i]->SetLineColor(i+1);
	histoDetetor[i]->SetTitle(histoName);
	hs->Add(histoDetetor[i]);
	histoDetetor[i]->Write();


	}
	
hs->Draw("noStack");
canvas->BuildLegend();
}
