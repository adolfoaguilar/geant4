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
// $Id$

// Structure containing the information related to Xml ntuple
//
// Author: Ivana Hrivnacova, 04/07/2012  (ivana@ipno.in2p3.fr)

#ifndef G4XmlNtupleDescription_h
#define G4XmlNtupleDescription_h 1

#include "tools/waxml/ntuple"

#include <fstream>
#include <map>

namespace tools { 
class ntuple_booking; 
}  

struct G4XmlNtupleDescription
{
  G4XmlNtupleDescription() 
    :  fFile(0),
       fNtuple(0),
       fNtupleBooking(0),
       fNtupleIColumnMap(),
       fNtupleFColumnMap(),
       fNtupleDColumnMap() {}
       
  ~G4XmlNtupleDescription() 
     { delete fFile;  
       delete fNtuple;
       delete fNtupleBooking;
     }  

  std::ofstream* fFile;
  tools::waxml::ntuple* fNtuple; 
  tools::ntuple_booking*  fNtupleBooking; 
  std::map<G4int, tools::waxml::ntuple::column<int>* >    fNtupleIColumnMap;           
  std::map<G4int, tools::waxml::ntuple::column<float>* >  fNtupleFColumnMap;           
  std::map<G4int, tools::waxml::ntuple::column<double>* > fNtupleDColumnMap;           
};

#endif  

