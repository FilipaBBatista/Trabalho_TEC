void Histogramas_VH_PS_EmZ(TString ficheiroLido){

TFile *ficheiro = new TFile("AmberTarget_Run_0.root","READ");
	
TString novoFicheiro = ficheiroLido;
novoFicheiro.ReplaceAll("AmberTarget_Run_","Analise_Histogramas_VH_PS_EmZ_");
	
TFile *ficheiroGravar = new TFile(novoFicheiro,"RECREATE");
TTree *dados = (TTree*) ficheiro->Get("hadronicVertex");

	
Int_t nBins = 1100; 
Double_t minBin = -550;
Double_t maxBin = 550; 

Int_t nHistos = 2;
TH1D* Histogramas[nHistos]; 
TCanvas *canvas = new TCanvas("canvas",novoFicheiro,1800,700);
gStyle->SetOptStat(0);
canvas->Divide(2,1,0,0);
TString branchName;
TString canvasName;


for(Int_t i = 0; i<nHistos;i++){

   	if(i==0){
   		TString HistoNome = "Vertex Primario";
   		Histogramas[i] = new TH1D(HistoNome,HistoNome,nBins,minBin,maxBin);
  		branchName = "vertexPosZ_cm";
   		canvas->cd(i+1);
   		dados->Draw(branchName + ">>" + HistoNome, "IsPrimary==1");
   		Histogramas[i]->Write();
   		gPad->SetLogy();
       	}
   	
   	else{
   		TString HistoNome = "Vertex Secundario";
   		Histogramas[i] = new TH1D(HistoNome,HistoNome,nBins,minBin,maxBin);
  		branchName = "vertexPosZ_cm";
   		canvas->cd(i+1);
   		dados->Draw(branchName + ">>" + HistoNome);
   		Histogramas[i]->Write();
   		gPad->SetLogy();

      	}

    }


}
