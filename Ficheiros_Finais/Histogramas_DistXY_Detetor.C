void Histogramas_DistXY_Detetor(TString ficheiroLido){


TFile *ficheiro = new TFile("AmberTarget_Run_0.root","READ");
	
TString novoFicheiro=ficheiroLido;
novoFicheiro.ReplaceAll("AmberTarget_Run_","Analise_Hitogramas_DistXY_Detetor_");
	
TFile *ficheiroGravar = new TFile(novoFicheiro,"RECREATE");
TTree *dados = (TTree*) ficheiro->Get("Hits");
	   

Int_t nBins = 100;
//Como vai até 40 deu-se um intervalo de 5 para se ver o final
Double_t minBin = -45.0;
Double_t maxBin = 45.0;

Int_t nHistos = 4;
TH2D* histo[nHistos];
TCanvas *canvas = new TCanvas("canvas",novoFicheiro,3000,1000);
gStyle->SetOptStat(0);
canvas->Divide(2,2,0,0);

TString branchX;
TString branchY; 
	

for(Int_t i = 0; i < nHistos; i++){
	
	TString HistNome = "Histograma " + TString::Itoa(i+1, 10);
	histo[i] = new TH2D(HistNome, HistNome, nBins, minBin, maxBin, nBins, minBin, maxBin);
	branchX = "hitPosX_cm";
    branchY = "hitPosY_cm";
    canvas->cd(i+1);
	dados->Draw(branchX +":" + branchY + ">>" + HistNome, "detectorID=="+ TString::Itoa(i, 10),"colz");
    histo[i]->SetTitle(HistNome);
    histo[i]->Write();

	}


}
