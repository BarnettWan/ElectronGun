#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1);
	
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName="electron";
	G4ParticleDefinition *particle = particleTable->FindParticle("electron"); //electron source
	
	G4ThreeVector pos(0.,0.,-2.5); //point source
	
	
	//Angular Distribution w/ random angle
	G4double cosTheta = -1.0 + 2.0*G4UniformRand(); // range of -1 to 1
	G4double phi = twopi*G4UniformRand(); // range of 0 to 2pi
	G4double sinTheta = sqrt(1-cosTheta*cosTheta); 
	
	G4ThreeVector mom(sinTheta*cos(phi), sinTheta*sin(phi), cosTheta); //change to random 
	
	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom);
	fParticleGun->SetParticleMomentum(100.*GeV); //change energy
	fParticleGun->SetParticleDefinition(particle);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	fParticleGun->GeneratePrimaryVertex(anEvent);
}
