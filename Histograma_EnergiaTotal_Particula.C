void Histograma_EnergiaTotal_Particula(){

TFile *ficheiro = new TFile("energia_por_particula.root","READ");
       TFile *ficheiroGravar = new TFile("histograma_particula.root","RECREATE");
       TTree *dados = (TTree*) ficheiro->Get("Soma");
    
        Int_t nBIns = 500; 
        Double_t minBIn = 0.0;
        Double_t maxBin = 80000;
        Double_t maxBinM = 18000;
        Double_t maxBinR=90000;
 
        
        Int_t number_Hist = 3;
        TCanvas *janelas[number_Hist];
    
        TH1D* Histo_Pioes = new TH1D("Histo_Pioes","Histo_Pioes",nBIns,minBIn,maxBin);
        janelas[0] = new TCanvas("Pioes", "Pioes");
        dados->Draw("soma>>Histo_Pioes","particlePDG==211 || particlePDG==-211");
        Histo_Pioes->SetFillColor(5);
        Histo_Pioes->Write();
        Histo_Pioes->SetTitle("Pioes ; log(EdepDet0_keV)");
        gPad->SetLogy();
        
        TH1D* Histo_Muoes = new TH1D("Histo_Muoes","Histo_Muoes",nBIns,minBIn,maxBinM);
        janelas[1] = new TCanvas("Muoes", "Muoes");
        dados->Draw("soma>>Histo_Muoes","particlePDG==13 || particlePDG==-13");
        Histo_Muoes->SetFillColor(6);
        Histo_Muoes->Write();
        Histo_Muoes->SetTitle("Muoes ; log(EdepDet0_keV)");
        gPad->SetLogy();
        
        TH1D* Histo_Outras = new TH1D("Histo_Outras","Histo_Outras",nBIns,minBIn,maxBinR);
        janelas[2] = new TCanvas("Outras", "Outras");
        dados->Draw("soma>>Histo_Outras","particlePDG!=13 || particlePDG!=-13 || particlePDG!=211 || particlePDG!=-211");
        Histo_Outras->SetFillColor(7);
        Histo_Outras->Write();
        Histo_Outras->SetTitle("Outras; log(EdepDet0_keV)");
        gPad->SetLogy();
		
}