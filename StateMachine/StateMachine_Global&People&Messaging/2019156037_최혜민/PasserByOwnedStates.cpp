#include "PasserByOwnedStates.h"
#include "PasserBy.h"
#include "BakerLocation.h"
#include "EntityNames.h"

#include "fsm/State.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageType.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include "winuser.h"


#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------------
PasserByGlobalState* PasserByGlobalState::Instance()
{
    static PasserByGlobalState instance;

    return &instance;
}


void PasserByGlobalState::Execute(PasserBy* pb)
{
    if (RandFloat() < 0.5)
    {
        pb->GetFSM()->ChangeState(Takea_Look::Instance());
    }
}

bool PasserByGlobalState::OnMessage(PasserBy* pb, const Telegram& msg) { return false; }


//-----------------------------------------------------------------------------

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

    SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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

bool Takea_Walk::OnMessage(PasserBy* pb, const Telegram& msg) { return false; }




//-----------------------------------------------------------------------------
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

    SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pb->ID()) << ": Takea_Look";

    pb->GetFSM()->RevertToPreviousState();
}

void Takea_Look::Exit(PasserBy* pb)
{
    Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, pb->ID(), ent_Mr_Baker, mesg_HEY, (void*)NO_ADDITIONAL_INFO);/////////////////////////////////////////////
}

bool Takea_Look::OnMessage(PasserBy* pb, const Telegram& msg) { return false; }




//-----------------------------------------------------------------------------
HiTo_Owner* HiTo_Owner::Instance()
{
    static HiTo_Owner instance;

    return &instance;
}


void HiTo_Owner::Enter(PasserBy* pb)
{

}


void HiTo_Owner::Execute(PasserBy* pb)
{
}

void HiTo_Owner::Exit(PasserBy* pb)
{

}

bool HiTo_Owner::OnMessage(PasserBy* pb, const Telegram& msg) { return false; }
