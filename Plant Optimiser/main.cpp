#include <iostream>

#include "Plant.h"
#include "Proposal.h"

#include "Stage.hpp"

using namespace std;

int main( int argc, const char * argv[] )
{
    vector<Plant> fPlants;
    int lCost;
    int lNumberOfPlants;
    
    cout <<  "Please enter a cost: ";
    cin >> lCost;
    cout <<  "Please enter a number of plants required: ";
    cin >> lNumberOfPlants;
    
    for ( int i = 1; i <= lNumberOfPlants; i++ )
    {
        int lNumberOfProposal;

        cout << "Please enter number of proposals for plant " << i << " : ";
        cin >> lNumberOfProposal;
        cout << endl;
        
        fPlants.push_back( Plant( lNumberOfProposal ) );
    }
    
    Stage lOldStage;
    
    for ( size_t i = 0; i < fPlants.size(); i++ )
    {
        Stage lNewStage;

        lNewStage.buildStage( fPlants[i], lOldStage, lCost, i+1 );
        cout << "Stage " << i+1 << endl;
        cout << lNewStage;
        lOldStage = lNewStage;
    }
    return 0;
}











