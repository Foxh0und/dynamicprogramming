#include "Proposal.h"

Proposal::Proposal( int aIndex, int aCost, int aRevenue )
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
