//
//  Stage.cpp
//  PlantOptimiser
//
//  Created by Adam Miritis on 30/10/2015.
//  Copyright © 2015 Adam Miritis. All rights reserved.
//

#include "Stage.h"

using namespace std;

void Stage::buildStage( const Plant& aStagePlant, const Stage& aPreviousStage, int aCost, int aStageNr )
{
    const vector<Proposal>& lProposals = aStagePlant.getProposals();
    vector<Proposal>::const_iterator iter = lProposals.cbegin();

    if ( aStageNr == 1 )
    {    
        for ( ; iter != lProposals.cend(); iter++ )
        {
            int lCost = (*iter).getCost();
            int lRevenue = (*iter).getRevenue();
        
            if ( lCost <= aCost )
            {
                if ( fInvestmentPlan[lCost] < lRevenue )
                    fInvestmentPlan[lCost] = lRevenue;
            }
        }
    }
    else
    {    
        for( ; iter != lProposals.cend(); iter++ )
        {
            int lCost = (*iter).getCost();
            int lRevenue = (*iter).getRevenue();
        
            if ( lCost <= aCost )
            {
                int lCostRemaing = aCost - lCost;
            
				if ( lCostRemaing > 0 )
                {
                    pair<int,int> lBestIminus1 = aPreviousStage.getBestRevenue( lCostRemaing );
                    int lSequenceCost = lCost + lBestIminus1.first;
                    int lSequenceRevenue = lRevenue + lBestIminus1.second;
                
                    if ( fInvestmentPlan[lSequenceCost] < lSequenceRevenue )
                        fInvestmentPlan[lSequenceCost] = lSequenceRevenue;
                }
            }
        }
    }
}

pair<int,int> Stage::getBestRevenue( int aAvailableCosts ) const
{
    typedef map<int,int>::const_iterator const_iterator;
    
    const_iterator lBest = fInvestmentPlan.cend();
    
    for ( const_iterator iter = fInvestmentPlan.cbegin(); iter != fInvestmentPlan.cend(); iter++ )
    {
        if ( (*iter).first <= aAvailableCosts )
        {
            if ( lBest != fInvestmentPlan.cend() )
            {
                if ( (*lBest).second < (*iter).second )
                {
                    lBest = iter;
                }
            }
            else
            {
                lBest = iter;
            }
        }
    }
    
    if ( lBest != fInvestmentPlan.cend() )
        return (*lBest);
    else
        return pair<int,int>(0,0);
}

const std::map<int,int>& Stage::getInvestmentPlan()
{
    return fInvestmentPlan;
}

std::ostream& operator<<(std::ostream& aOstream, Stage& aObject)
{
    typedef map<int,int>::const_iterator const_iterator;
    
    for ( const_iterator iter = aObject.getInvestmentPlan().cbegin(); iter != aObject.getInvestmentPlan().cend(); iter++ )
    {
        int lCost = ( *iter ).first;
        int lRevenue = ( *iter ).second;
        aOstream << "Cost: " << lCost <<" Revenue: " << lRevenue << "." << endl;
    }
    return aOstream;
};
