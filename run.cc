#include "run.hh"

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->OpenFile("output.root");
	
	man->CreateNtuple("Hits", "Hits");
	man->CreateNtupleIColumn("fEvent");
	man->CreateNtupleDColumn("pos_X");
	man->CreateNtupleDColumn("pos_Y");
	man->CreateNtupleDColumn("pos_Z");
	man->CreateNtupleDColumn("mom_X");
	man->CreateNtupleDColumn("mom_Y");
	man->CreateNtupleDColumn("mom_Z");
	
	man->FinishNtuple(0);
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
	G4AnalysisManager *man - G4AnalysisManager::Instance();
	
	man->Write();
	man->CloseFile();
}
