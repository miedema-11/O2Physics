// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

// jet finder D+ mcd charged task
//
/// \author Nima Zardoshti <nima.zardoshti@cern.ch>

#include "PWGJE/JetFinders/jetFinderHF.cxx"

#include "PWGJE/DataModel/Jet.h"

#include <Framework/AnalysisTask.h>
#include <Framework/ConfigContext.h>
#include <Framework/DataProcessorSpec.h>
#include <Framework/runDataProcessing.h>

#include <vector>

using JetFinderDstarMCDetectorLevelCharged = JetFinderHFTask<aod::CandidatesDstarData, aod::CandidatesDstarMCD, aod::CandidatesDstarMCP, aod::JetTracksSubDstar, aod::JetParticlesSubDstar, aod::DstarChargedMCDetectorLevelJets, aod::DstarChargedMCDetectorLevelJetConstituents, aod::DstarChargedMCDetectorLevelEventWiseSubtractedJets, aod::DstarChargedMCDetectorLevelEventWiseSubtractedJetConstituents>;

WorkflowSpec defineDataProcessing(ConfigContext const& cfgc)
{
  std::vector<o2::framework::DataProcessorSpec> tasks;

  tasks.emplace_back(adaptAnalysisTask<JetFinderDstarMCDetectorLevelCharged>(cfgc,
                                                                             SetDefaultProcesses{{{"processChargedJetsMCD", true}}},
                                                                             TaskName{"jet-finder-dstar-mcd-charged"}));

  return WorkflowSpec{tasks};
}
