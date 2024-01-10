#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();
	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
	
	G4Box *solidWorld = new G4Box("solidWorld", 0.5*m ,0.5*m , 2.5*m); //Change to rectangle (Shoot in z-direction)
	
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
	
	
	//Detector
	G4Box *solidDetector = new G4Box("solidDetector", 0.005*m, 0.005*m, 0.01*m);
	
	logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");
	
	G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(0.5*m ,0.5*m , 2.49*m), logicDetector, "physDetector", logicWorld, false, 0, true);
	
	return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
	MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

	logicDetector->SetSensitiveDetector(sensDet);
}
