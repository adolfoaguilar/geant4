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
// $Id: G4BinaryPiKBuilder.cc 66892 2013-01-17 10:57:59Z gunter $
//
//---------------------------------------------------------------------------
//
// ClassName:   G4BinaryPiKBuilder
//
// Author: 2002 H.P. Wellisch
//
// Modified:
// 02.04.2009 V.Ivanchenko remove add cross section, string builderis reponsible 
//
//----------------------------------------------------------------------------
//
#include "G4BinaryPiKBuilder.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4ProcessManager.hh"

G4BinaryPiKBuilder::
G4BinaryPiKBuilder() 
{
  thePiData = new G4PiNuclearCrossSection;
  theMin = 0*GeV;
  theMax = 1.3*GeV;
  theModel = new G4BinaryCascade();
  theModel->SetMinEnergy(theMin);
  theModel->SetMaxEnergy(theMax); 
}

G4BinaryPiKBuilder::
~G4BinaryPiKBuilder() 
{
}

void G4BinaryPiKBuilder::
Build(G4HadronElasticProcess * ) {}

void G4BinaryPiKBuilder::
Build(G4PionPlusInelasticProcess * aP)
{
  theModel->SetMinEnergy(theMin);
  theModel->SetMaxEnergy(theMax);
  aP->RegisterMe(theModel);
}

void G4BinaryPiKBuilder::
Build(G4PionMinusInelasticProcess * aP)
{
  theModel->SetMinEnergy(theMin);
  theModel->SetMaxEnergy(theMax);
  aP->RegisterMe(theModel);
}

void G4BinaryPiKBuilder::
Build(G4KaonPlusInelasticProcess * )
{
}

void G4BinaryPiKBuilder::
Build(G4KaonMinusInelasticProcess * )
{
}

void G4BinaryPiKBuilder::
Build(G4KaonZeroLInelasticProcess * )
{
}

void G4BinaryPiKBuilder::
Build(G4KaonZeroSInelasticProcess * )
{
}

// 2002 by J.P. Wellisch
