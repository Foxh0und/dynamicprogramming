//
//  Proposal.cpp
//  Plant
//
//  Created by Adam Miritis on 13/10/2015.
//  Copyright © 2015 Adam Miritis. All rights reserved.
//

#include "Proposal.h"


Proposal::Proposal( int aIndex,int aCost, int aRevenue )
{
    fIndex = aIndex;
    fCost = aCost;
    fRevenue = aRevenue;
}
int Proposal::getIndex() const
{
    return fIndex;
}

int Proposal::getCost() const
{
    return fCost;
}

int Proposal::getRevenue() const
{
    return fRevenue;
}
