void energia_por_particula() {

Int_t particlePDG;
Double_t EdepDet0_keV;
Double_t EdepDet1_keV;
Double_t EdepDet2_keV;
Double_t EdepDet3_keV;
Double_t soma;


TFile *file = new TFile("AmberTarget_Run_0.root","READ");
TFile *ficheiroGravar = new TFile("energia_por_particula.root","RECREATE");
TTree *dados = (TTree*) file->Get("tracksData");

dados->SetBranchStatus("*",0);
dados->SetBranchStatus("particlePDG",1);
dados->SetBranchStatus("EdepDet0_keV",1);
dados->SetBranchStatus("EdepDet1_keV",1);
dados->SetBranchStatus("EdepDet2_keV",1);
dados->SetBranchStatus("EdepDet3_keV",1);

dados->SetBranchAddress("particlePDG",&particlePDG);
dados->SetBranchAddress("EdepDet0_keV",&EdepDet0_keV);
dados->SetBranchAddress("EdepDet1_keV",&EdepDet1_keV);
dados->SetBranchAddress("EdepDet2_keV",&EdepDet2_keV);
dados->SetBranchAddress("EdepDet3_keV",&EdepDet3_keV);


TTree *newTree = new TTree("Soma", "Soma de energias por Particula");
newTree->Branch("soma",&soma, "soma/D");
newTree->Branch("particlePDG",&particlePDG,"particlePDG/I");

Long64_t Nentries = dados->GetEntries();
for (int i = 0; i < Nentries; i++){
	dados->GetEntry(i);
	soma = EdepDet0_keV + EdepDet1_keV + EdepDet2_keV + EdepDet3_keV;
	newTree->Fill();
	}
	
newTree->Write();
}




