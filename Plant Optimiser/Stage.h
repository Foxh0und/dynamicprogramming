//
//  Stage.hpp
//  Plant
//
//  Created by Adam Miritis on 30/10/2015.
//  Copyright © 2015 Adam Miritis. All rights reserved.
//

#pragma once

#include <map>

#include "Plant.h"

class Stage
{
public:
    std::map<int,int> fInvestmentPlan;

public:
    void buildStage( const Plant& aStagePlant, const Stage& aPreviousStage, int aCost, int aStageNr );
    
    std::pair<int,int> getBestRevenue( int aAvailableCosts ) const;
    
    const std::map<int,int>& getInvestmentPlan();
};
std::ostream& operator<<( std::ostream& aOstream, Stage& aObject );