#pragma once

#include <iostream>

class Proposal
{
private:
    int fIndex;
    int fCost;
    int fRevenue;
public:
    Proposal( int aIndex, int aCost, int aRevenue );

    int getIndex() const;
    int getCost() const;
    int getRevenue() const;
};
