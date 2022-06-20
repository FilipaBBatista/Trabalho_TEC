void Pioes_Muoes_Outras_Detetor2(){

TFile *ficheiro = new TFile("AmberTarget_Run_0.root","READ");						                    //Reads a file
       TFile *ficheiroGravar = new TFile("Analise_Pioes_Muoes_2.root","RECREATE");		            	//Saves a file
       TTree *dados = (TTree*) ficheiro->Get("tracksData");						                        //TTree - List of independent columns or branches, represented by the TBranch class
    
        Int_t nBIns = 100; 
        Double_t minBIn = 0.0;
        Double_t maxBin = 80000;
        Double_t maxBinM = 18000;
        Double_t maxBinO=90000; 
        

        Int_t nHistos = 3;
        TCanvas *janelas[nHistos];
    
        TH1D* Histograma_Pioes = new TH1D("Histograma_Pioes","Histograma_Pioes",nBIns,minBIn,maxBin);	//Create a 1-Dim histogram with fix bins of type double
        janelas[0] = new TCanvas("Pioes", "Pioes");
        dados->Draw("EdepDet2_keV>>Histograma_Pioes","particlePDG==211 || particlePDG==-211");
        Histograma_Pioes->SetFillColor(30);
        Histograma_Pioes->Write();
        Histograma_Pioes->SetTitle("Pioes - Detetor2 ; log(EdepDet2_keV)");
        gPad->SetLogy();
        
        TH1D* Histograma_Muoes = new TH1D("Histograma_Muoes","Histograma_Muoes",nBIns,minBIn,maxBinM);
        janelas[1] = new TCanvas("Muoes", "Muoes");
        dados->Draw("EdepDet2_keV>>Histograma_Muoes","particlePDG==13 || particlePDG==-13");
        Histograma_Muoes->SetFillColor(8);
        Histograma_Muoes->Write();
        Histograma_Muoes->SetTitle("Muoes - Detetor2 ; log(EdepDet2_keV)");
        gPad->SetLogy();
        
        TH1D* Histograma_Outras = new TH1D("Histograma_Outras","Histograma_Outras",nBIns,minBIn,maxBinO);
        janelas[2] = new TCanvas("Outras", "Outras");
        dados->Draw("EdepDet2_keV>>Histograma_Outras","particlePDG!=13 || particlePDG!=-13 || particlePDG!=211 || particlePDG!=-211");
        Histograma_Outras->SetFillColor(85);
        Histograma_Outras->Write();
        Histograma_Outras->SetTitle("Outras - Detetor2 ; log(EdepDet2_keV)");
        gPad->SetLogy();
		
}