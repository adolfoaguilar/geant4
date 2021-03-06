//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: G4FieldTrackUpdator.cc 68795 2013-04-05 13:24:46Z gcosmo $
//
//   M. Asai - first implementation Apr/28/2006
//
//---------------------------------------------------------------
//
// G4FieldTrackUpdator.cc
//
//---------------------------------------------------------------

#include "globals.hh"
#include "G4FieldTrackUpdator.hh"
#include "G4ThreeVector.hh"
#include "G4Track.hh"
#include "G4DynamicParticle.hh"
#include "G4TrackStatus.hh"
#include "G4FieldTrack.hh"

G4FieldTrack* G4FieldTrackUpdator::CreateFieldTrack(const G4Track* trk)
{
  G4FieldTrack* ftrk = new G4FieldTrack(
    trk->GetPosition(),
    trk->GetGlobalTime(),
    trk->GetMomentumDirection(),
    trk->GetKineticEnergy(),
    trk->GetDynamicParticle()->GetMass(),
    trk->GetDynamicParticle()->GetCharge(),
    trk->GetDynamicParticle()->GetPolarization(),
    0.0                   // magnetic dipole moment to be implemented
    );
  return ftrk;
}

void G4FieldTrackUpdator::Update(G4FieldTrack* ftrk,const G4Track* trk)
{
  ftrk->UpdateState(
    trk->GetPosition(),     
    trk->GetGlobalTime(),
    trk->GetMomentumDirection(),
    trk->GetKineticEnergy()
    );
  const G4DynamicParticle* ptDynamicParticle= trk->GetDynamicParticle();

  ftrk->SetChargeAndMoments( ptDynamicParticle->GetCharge() );
   // The charge can change during tracking
  ftrk->SetSpin( ptDynamicParticle->GetPolarization() );

  // The following properties must be updated ONCE for each new track (at least)
  ftrk->SetRestMass(ptDynamicParticle->GetMass());   
}


