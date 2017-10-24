//
//  Proposal.hpp
//  Plant
//
//  Created by Adam Miritis on 6/10/2015.
//  Copyright © 2015 Adam Miritis. All rights reserved.
//

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