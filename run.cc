#include "run.hh"

MyRunAction::MyRunAction()
{	

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->OpenFile("output.root");
	
	man->CreateNtuple("Hits", "Hits");
	man->CreateNtupleIColumn("fEvent");
	
	man->CreateNtupleDColumn("InitEnergy");
	man->CreateNtupleDColumn("init_pos_X");
	man->CreateNtupleDColumn("init_pos_Y");
	man->CreateNtupleDColumn("init_pos_Z");
	man->CreateNtupleDColumn("init_mom_X");
	man->CreateNtupleDColumn("init_mom_Y");
	man->CreateNtupleDColumn("init_mom_Z");
	
	man->CreateNtupleDColumn("pos_X");
	man->CreateNtupleDColumn("pos_Y");
	man->CreateNtupleDColumn("pos_Z");
	man->CreateNtupleDColumn("mom_X");
	man->CreateNtupleDColumn("mom_Y");
	man->CreateNtupleDColumn("mom_Z");
	
	man->FinishNtuple(0);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run){

    auto analysisManager = G4AnalysisManager::Instance();

    G4String fileName = "./outputs/output_"+std::to_string(time(NULL))+".root";
    analysisManager->OpenFile(fileName);
    G4cout << "Using" << analysisManager->GetType() <<G4endl;
}

void MyRunAction::EndOfRunAction(const G4Run*)
{	
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->Write();
	man->CloseFile();
	man->Reset();
}
