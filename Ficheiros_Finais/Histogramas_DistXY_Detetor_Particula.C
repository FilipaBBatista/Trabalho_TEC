void Histogramas_DistXY_Detetor_Particula(TString ficheiroLido){

TFile *ficheiro = new TFile("AmberTarget_Run_0.root","READ");
	
TString novoFicheiro=ficheiroLido;
novoFicheiro.ReplaceAll("AmberTarget_Run_","Analise_Hitogramas_DistXY_Detetor_Particula_");
	
TFile *ficheiroGravar = new TFile(novoFicheiro,"RECREATE");
TTree *dados = (TTree*) ficheiro->Get("Hits");
	   

Int_t nBins = 100;
//Como vai até 40 deu-se um intervalo de 5 para se ver o final
Double_t minBin = -45.0;
Double_t maxBin = 45.0;

Int_t nHistos = 4;

//NEUTRAS
TH2D* histoN[nHistos];
TCanvas *canvasN = new TCanvas("canvasN",novoFicheiro,3000,700);
gStyle->SetOptStat(0);
canvasN->Divide(4,0,0,0);

TString branchXN;
TString branchYN; 
	

for(Int_t i = 0; i < nHistos; i++){
	
	TString HistNome = "Histograma " + TString::Itoa(i+1, 10) + ", Particulas Neutras";
	histoN[i] = new TH2D(HistNome, HistNome, nBins, minBin, maxBin, nBins, minBin, maxBin);
	branchXN = "hitPosX_cm";
    branchYN = "hitPosY_cm";
    canvasN->cd(i+1);
	dados->Draw(branchXN +":" + branchYN + ">>" + HistNome, "detectorID=="+ TString::Itoa(i, 10) + " && particleCharge == 0","colz");
    histoN[i]->SetTitle(HistNome);
    histoN[i]->Write();

	}




//CARREGADAS
TH2D* histoC[nHistos];
TCanvas *canvasC = new TCanvas("canvasC",novoFicheiro,3000,700);
gStyle->SetOptStat(0);
canvasC->Divide(4,0,0,0);

TString branchXC;
TString branchYC; 
	

for(Int_t i = 0; i < nHistos; i++){
	
	TString HistNome = "Histograma " + TString::Itoa(i+1, 10) + ", Particulas Carregadas";
	histoC[i] = new TH2D(HistNome, HistNome, nBins, minBin, maxBin, nBins, minBin, maxBin);
	branchXC = "hitPosX_cm";
    branchYC = "hitPosY_cm";
    canvasC->cd(i+1);
	dados->Draw(branchXC +":" + branchYC + ">>" + HistNome, "detectorID=="+ TString::Itoa(i, 10) + " && particleCharge != 0","colz");
    histoC[i]->SetTitle(HistNome);
    histoC[i]->Write();

	}

    	
}
