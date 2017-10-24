#pragma once

#include "Proposal.h"
#include <vector>

class Plant
{
private:
    std::vector<Proposal> fProposals;
    
public:
    Plant( int aNumberOfProposal );
    
    const std::vector<Proposal>& getProposals() const;
    size_t getNumberOfProposals() const;
};
