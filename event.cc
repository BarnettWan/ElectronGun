#include "event.hh"

MyEventAction::MyEventAction(MyRunAction*)
{

}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{

}

void MyEventAction::EndOfEventAction(const G4Event* event)
{
	//Initial Registration
	G4PrimaryVertex *vert = event->GetPrimaryVertex();
	G4PrimaryParticle *part = vert->GetPrimary();
	
	G4double InitEnergy = part->GetKineticEnergy();
	G4ThreeVector InitPos = vert->GetPosition();
	G4ThreeVector InitMom = part->GetMomentum();
	
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->FillNtupleDColumn(1, InitEnergy);
	man->FillNtupleDColumn(2, InitPos [0]);
	man->FillNtupleDColumn(3, InitPos [1]);
	man->FillNtupleDColumn(4, InitPos [2]);
	man->FillNtupleDColumn(5, InitMom [0]);
	man->FillNtupleDColumn(6, InitMom [1]);
	man->FillNtupleDColumn(7, InitMom [2]);
}
