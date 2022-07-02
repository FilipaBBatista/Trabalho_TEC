void Histogramas_MZ_P_PS(TString ficheiroLido){

TFile *ficheiro = new TFile("AmberTarget_Run_0.root","READ");
TString novoFicheiro=ficheiroLido;
novoFicheiro.ReplaceAll("AmberTarget_Run_","Analise_Histogramas_MZ_P_PS_");
    
TFile *ficheiroGravar = new TFile(novoFicheiro,"RECREATE");
TTree *dados = (TTree*) ficheiro->Get("tracksData");

Int_t nBinP = 215; 
Double_t minBinP = -5;
Double_t maxBinP = 220;

    
Int_t nHistos = 2;

TH1D* Histo_Pioes[nHistos];
TCanvas *canvas = new TCanvas("canvas",novoFicheiro,900,700);
gStyle->SetOptStat(0);
canvas->Divide(2,1,0,0);


for(Int_t i=0; i<nHistos; i++){


	if(i==0){
   		TString HistoNome = "Pioes Primarios";
   		Histo_Pioes[i] = new TH1D(HistoNome,HistoNome,nBinP,minBinP,maxBinP); 		
   		canvas->cd(i+1);
   		dados->Draw("pZ_GeV>>" + HistoNome ,"particlePDG==211 || particlePDG==-211 && IsPrimary==1");
   		Histo_Pioes[i]->SetFillColor(2);
   		Histo_Pioes[i]->Write();
   		gPad->SetLogy();
   		TF1 *landouFitP = new TF1 ("landouFitP", "landau", 0, 30000);
    	Histo_Pioes[i]->Fit("landouFitP");
       	}
   	
   	else{
   		TString HistoNome = "Pioes Secundarios";
   		Histo_Pioes[i] = new TH1D(HistoNome,HistoNome,nBinP,minBinP,maxBinP);
   		canvas->cd(i+1);
   		dados->Draw("pZ_GeV>>" + HistoNome ,"particlePDG==211 || particlePDG==-211 && IsPrimary==0");
   		Histo_Pioes[i]->SetFillColor(3);
   		Histo_Pioes[i]->Write();
   		gPad->SetLogy();
   		TF1 *landouFitP = new TF1 ("landouFitP", "landau", 0, 30000);
    	Histo_Pioes[i]->Fit("landouFitP");

      	}
    }
		
}
