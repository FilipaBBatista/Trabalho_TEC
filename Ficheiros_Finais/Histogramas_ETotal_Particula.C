void Histogramas_ETotal_Particula(TString ficheiroLido){

TFile *ficheiro = new TFile("AmberTarget_Run_0.root","READ");
TString novoFicheiro = ficheiroLido;
novoFicheiro.ReplaceAll("AmberTarget_Run_","Analise_Histogramas_ETotal_Particula_");
	
TFile *ficheiroGravar = new TFile(novoFicheiro,"RECREATE");
TTree *dados = (TTree*) ficheiro->Get("tracksData");

Int_t particlePDG;
Double_t EdepDet0_keV;
Double_t EdepDet1_keV;
Double_t EdepDet2_keV;
Double_t EdepDet3_keV;
Double_t soma;
Int_t particlePDGNew;	


dados->SetBranchStatus("*", 0); // Desativar as branches

// Ativar só as necessárias
dados->SetBranchStatus("particlePDG", 1);
dados->SetBranchStatus("EdepDet0_keV", 1);
dados->SetBranchStatus("EdepDet1_keV", 1);
dados->SetBranchStatus("EdepDet2_keV", 1);
dados->SetBranchStatus("EdepDet3_keV", 1);

	
Int_t nBins = 500; 
Double_t minBin = 0.0;
Double_t maxBinP = 100000;
Double_t maxBinM = 52000;
Double_t maxBinO = 230000;

	
dados->SetBranchAddress("EdepDet0_keV", &EdepDet0_keV);
dados->SetBranchAddress("EdepDet1_keV", &EdepDet1_keV);
dados->SetBranchAddress("EdepDet2_keV", &EdepDet2_keV);
dados->SetBranchAddress("EdepDet3_keV", &EdepDet3_keV);
dados->SetBranchAddress("particlePDG", &particlePDG);
	
TTree *newTree = new TTree("Resultados", "Resultado da soma de energias por partícula"); 
newTree->Branch("soma", &soma, "soma/D"); 
newTree->Branch("particlePDGNew", &particlePDGNew, "particlePDGNew/I");
	
	
Long64_t Nentries = dados->GetEntries(); 
	
for(Int_t i = 0; i < Nentries; i++){
		
	dados->GetEntry(i);
	soma = EdepDet0_keV + EdepDet1_keV + EdepDet2_keV + EdepDet3_keV;
	particlePDGNew =  particlePDG;
	newTree->Fill();
			
	}
	
newTree->Write();

	
TCanvas *canvas = new TCanvas("c1", novoFicheiro, 1800, 700);
gStyle->SetOptStat(0);
canvas->Divide(3,1,0,0);


//PIÕES
TString HistoNomeP = "HistoNomeP";
TH1D* histo_Pioes = new TH1D(HistoNomeP, HistoNomeP, nBins, minBin, maxBinP);
TString canvasPioes = "Histograma da energia total dos Pioes";
canvas->cd(1);

newTree->Draw("soma>>HistoNomeP", "particlePDGNew==211 || particlePDGNew==-211");
histo_Pioes->SetFillColor(1);
histo_Pioes->Write();
histo_Pioes->SetTitle("Energia Total Pioes");
gPad->SetLogy();
TF1 *landouFitPioes = new TF1 ("landouFitPioes", "landau", 0, 30000);
histo_Pioes->Fit("landouFitPioes");
	
	
//MUÕES
TString HistoNomeM = "HistoNomeM";
TH1D* histo_muoes = new TH1D(HistoNomeM, HistoNomeM, nBins, minBin, maxBinM);
TString canvasMuoes = "Histograma da energia total dos Muoes";
canvas->cd(2);

newTree->Draw("soma>>HistoNomeM", "particlePDGNew==13 || particlePDGNew==-13");
histo_muoes->SetFillColor(3);
	histo_muoes->Write();
histo_muoes->SetTitle("Energia Total Muoes");
gPad->SetLogy();
TF1 *landouFitMuoes = new TF1 ("landouFitMuoes", "landau", 0, 30000);
histo_muoes->Fit("landouFitMuoes");

	
//OUTRAS PARTICULAS
TString HistoNomeO = "HistoNomeO";
TH1D* histo_outras = new TH1D(HistoNomeO, HistoNomeO, nBins, minBin, maxBinO);
TString canvasOutras = "Histograma da energia total das outras particulas";
canvas->cd(3);

newTree->Draw("soma>>HistoNomeO", "particlePDGNew != 13 || particlePDGNew !=-13 || particlePDGNew !=211 || particlePDGNew !=-211");
histo_outras->SetFillColor(2);
histo_outras->Write();
histo_outras->SetTitle("Energia Total Outras Particulas");
gPad->SetLogy();


}
