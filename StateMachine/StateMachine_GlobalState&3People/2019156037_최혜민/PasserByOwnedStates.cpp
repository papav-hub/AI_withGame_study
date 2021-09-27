#include "PasserByOwnedStates.h"
#include "PasserBy.h"
#include "BakerLocation.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------Global state
PasserByGlobalState* PasserByGlobalState::Instance()
{
    static PasserByGlobalState instance;

    return &instance;
}


void PasserByGlobalState::Execute(PasserBy* pb)
{
    //1 in 10 chance of needing the bathroom
    if (RandFloat() < 0.5)
    {
        pb->GetFSM()->ChangeState(Takea_Look::Instance());
    }
}

//---------------------------------------DoHouseWork

Takea_Walk* Takea_Walk::Instance()
{
    static Takea_Walk instance;

    return &instance;
}


void Takea_Walk::Enter(PasserBy* pb)
{
}


void Takea_Walk::Execute(PasserBy* pb)
{
    switch (RandInt(0, 1))
    {
    case 0:

        cout << "\n" << GetNameOfEntity(pb->ID()) << ": Takea_Walk 0";

        break;

    case 1:

        cout << "\n" << GetNameOfEntity(pb->ID()) << ": Takea_Walk 1";

        break;

    }
}

void Takea_Walk::Exit(PasserBy* pb)
{
}



//------------------------------------------------------------------------VisitBathroom
Takea_Look* Takea_Look::Instance()
{
    static Takea_Look instance;

    return &instance;
}


void Takea_Look::Enter(PasserBy* pb)
{
    
}


void Takea_Look::Execute(PasserBy* pb)
{
    cout << "\n" << GetNameOfEntity(pb->ID()) << ": Takea_Look";

    pb->GetFSM()->RevertToPreviousState();
}

void Takea_Look::Exit(PasserBy* pb)
{
    
}