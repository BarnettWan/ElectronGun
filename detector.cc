#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
	G4Track *track = aStep->GetTrack();
	
	
	
	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	

	//Detector Registration
	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
	G4ThreeVector posElectron = preStepPoint->GetPosition();
	G4ThreeVector momElectron = track->GetMomentum();
	
	
	
	
	G4cout << "Electron position: " << posElectron << G4endl;
	
	G4cout << "Electron momentum: " << momElectron << G4endl;
	
	
	
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0, evt);
	
	man->FillNtupleDColumn(8, posElectron [0]);
	man->FillNtupleDColumn(9, posElectron [1]);
	man->FillNtupleDColumn(10, posElectron [2]);
	man->FillNtupleDColumn(11, momElectron [0]);
	man->FillNtupleDColumn(12, momElectron [1]);
	man->FillNtupleDColumn(13, momElectron [2]);
	
	man->AddNtupleRow(0);
}
