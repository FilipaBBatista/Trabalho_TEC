void Pioes_Muoes_Restantes(){

TFile *ficheiro = new TFile("AmberTarget_Run_0.root","READ");
       TFile *ficheiroGravar = new TFile("Analise_Pioes_Muoes.root","RECREATE");
       TTree *dados = (TTree*) ficheiro->Get("tracksData");
    
        Int_t nBIns = 100; 
        Double_t minBIn = 0.0;
        Double_t maxBin = 80000;
        Double_t maxBinM = 18000;
        Double_t maxBinR=90000;
 
        
        Int_t number_Hist = 3;
        TCanvas *janelas[number_Hist];
    
        TH1D* Histograma_Pioes = new TH1D("Histograma_Pioes","Histograma_Pioes",nBIns,minBIn,maxBin);
        janelas[0] = new TCanvas("Pioes", "Pioes");
        dados->Draw("EdepDet0_keV>>Histograma_Pioes","particlePDG==211 || particlePDG==-211");
        Histograma_Pioes->SetFillColor(4);
        Histograma_Pioes->Write();
        Histograma_Pioes->SetTitle("Pioes - Detetor0 ; log(EdepDet0_keV)");
        gPad->SetLogy();
        
        TH1D* Histograma_Muoes = new TH1D("Histograma_Muoes","Histograma_Muoes",nBIns,minBIn,maxBinM);
        janelas[1] = new TCanvas("Muoes", "Muoes");
        dados->Draw("EdepDet0_keV>>Histograma_Muoes","particlePDG==13 || particlePDG==-13");
        Histograma_Muoes->SetFillColor(2);
        Histograma_Muoes->Write();
        Histograma_Muoes->SetTitle("Muoes - Detetor0 ; log(EdepDet0_keV)");
        gPad->SetLogy();
        
        TH1D* Histograma_Restantes = new TH1D("Histograma_Restantes","Histograma_Restantes",nBIns,minBIn,maxBinR);
        janelas[2] = new TCanvas("Restantes", "Restantes");
        dados->Draw("EdepDet0_keV>>Histograma_Restantes","particlePDG!=13 || particlePDG!=-13 || particlePDG!=211 || particlePDG!=-211");
        Histograma_Restantes->SetFillColor(3);
        Histograma_Restantes->Write();
        Histograma_Restantes->SetTitle("Restantes - Detetor0 ; log(EdepDet0_keV)");
        gPad->SetLogy();
		
}
