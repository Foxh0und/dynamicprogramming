//
//  Plant.hpp
//  Plant
//
//  Created by Adam Miritis on 6/10/2015.
//  Copyright © 2015 Adam Miritis. All rights reserved.
//

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