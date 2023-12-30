#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
	G4Track *track = aStep->GetTrack();
	
	track->SetTrackStatus(fStopandKill);
	
	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

	G4ThreeVector posElectron = preStepPoint->GetPosition();
	
	G4ThreeVector momElectron = track->GetMomentum();
	
	
	G4cout << "Electron position: " << posElectron << G4endl;
	
	G4cout << "Electron momentum: " << momElectron << G4endl;
	
	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0, evt);
	man->FillNtupleDColumn(1, posElectron [0]);
	man->FillNtupleDColumn(2, posElectron [1]);
	man->FillNtupleDColumn(3, posElectron [2]);
	man->FillNtupleDColumn(4, momElectron [0]);
	man->FillNtupleDColumn(5, momElectron [1]);
	man->FillNtupleDColumn(6, momElectron [2]);
	
	man->AddNtupleRow(0);
}
