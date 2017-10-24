#include "Plant.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Plant::Plant( int aProposalNumber )
{
    int lCost;
    int lRevenue;
    int lIndex = 1;
    
    while ( aProposalNumber-- )
    {
        cout << "For propsoal " << lIndex << ", please enter a cost: ";
        cin >> lCost;
        cout << "Now, it's revenue: ";
        cin >> lRevenue;
        cout << endl;
        
        fProposals.push_back( Proposal( lIndex++, lCost, lRevenue ) );
    }
}

const vector<Proposal>& Plant::getProposals() const
{
    return fProposals;
}

size_t Plant::getNumberOfProposals() const
{
    return fProposals.size();
}
