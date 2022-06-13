void Pioes_Muoes_Outras_Det1(){

TFile *ficheiro = new TFile("AmberTarget_Run_0.root","READ");
       TFile *ficheiroGravar = new TFile("Analise_Pioes_Muoes_2.root","RECREATE");
       TTree *dados = (TTree*) ficheiro->Get("tracksData");
    
        Int_t nBIns = 100; 
        Double_t minBIn = 0.0;
        Double_t maxBin = 80000;
        Double_t maxBinM = 18000;
        Double_t maxBinR= 150000;
 
        
        Int_t number_Hist = 3;
        TCanvas *janelas[number_Hist];
    
        TH1D* Histo_Pioes = new TH1D("Histo_Pioes","Histo_Pioes",nBIns,minBIn,maxBin);
        janelas[0] = new TCanvas("Pioes", "Pioes");
        dados->Draw("EdepDet1_keV>>Histo_Pioes","particlePDG==211 || particlePDG==-211");
        Histo_Pioes->SetFillColor(5);
        Histo_Pioes->Write();
        Histo_Pioes->SetTitle("Pioes -> Detetor1 ; log(EdepDet1_keV)");
        gPad->SetLogy();
        
        TH1D* Histo_Muoes = new TH1D("Histo_Muoes","Histo_Muoes",nBIns,minBIn,maxBinM);
        janelas[1] = new TCanvas("Muoes", "Muoes");
        dados->Draw("EdepDet1_keV>>Histo_Muoes","particlePDG==13 || particlePDG==-13");
        Histo_Muoes->SetFillColor(6);
        Histo_Muoes->Write();
        Histo_Muoes->SetTitle("Muoes -> Detetor1 ; log(EdepDet1_keV)");
        gPad->SetLogy();
        
        TH1D* Histo_Restantes = new TH1D("Histo_Outras","Histo_Outras",nBIns,minBIn,maxBinR);
        janelas[2] = new TCanvas("Outras", "Outras");
        dados->Draw("EdepDet1_keV>>Histo_Outras","particlePDG!=13 || particlePDG!=-13 || particlePDG!=211 || particlePDG!=-211");
        Histo_Restantes->SetFillColor(7);
        Histo_Restantes->Write();
        Histo_Restantes->SetTitle("Outras -> Detetor1 ; log(EdepDet1_keV)");
        gPad->SetLogy();
		
}
