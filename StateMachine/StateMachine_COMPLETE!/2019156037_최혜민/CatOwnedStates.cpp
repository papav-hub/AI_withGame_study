#include "CatOwnedStates.h"
#include "State.h"
#include "Cat.h"
#include "BakerLocation.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"

#include "fsm/State.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageType.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif


CatByGlobalState* CatByGlobalState::Instance() {
    static CatByGlobalState instance;

    return &instance;
}

void CatByGlobalState::Enter(Cat* cat) {}

void CatByGlobalState::Execute(Cat* cat) {
    cat->IncreaseHungry();
    cat->IncreaseTired();
}

void CatByGlobalState::Exit(Cat* cat) {}

bool CatByGlobalState::OnMessage(Cat* cat, const Telegram& msg) { 
    Dispatch->DispatchMessage(0.5, cat->ID(), ent_Mr_Baker, mesg_MEOW, (void*)NO_ADDITIONAL_INFO);
    cat->GetFSM()->ChangeState(Meow_Meow::Instance());
    return true;
}


//-----------------------------------------------------------------------------

Playwith_mouse* Playwith_mouse::Instance()
{
    static Playwith_mouse instance;

    return &instance;
}

void Playwith_mouse::Enter(Cat* cat)
{

}


void Playwith_mouse::Execute(Cat* cat)
{
    cat->Play();


    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Play with Mouse";

    if (cat->CatHungry())
    {
        cat->GetFSM()->ChangeState(Eat_Feed::Instance());
    }

    else if (cat->CatTired())
    {
        cat->GetFSM()->ChangeState(RestAnd_Sleep::Instance());
    }

}


void Playwith_mouse::Exit(Cat* cat)
{

}

bool Playwith_mouse::OnMessage(Cat* cat, const Telegram& msg) { return false; }




//-----------------------------------------------------------------------------

RestAnd_Sleep* RestAnd_Sleep::Instance()
{
    static RestAnd_Sleep instance;

    return &instance;
}


void RestAnd_Sleep::Enter(Cat* cat)
{

}


void RestAnd_Sleep::Execute(Cat* cat)
{

    cat->Rest();

    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Gossip(°ñ°ñ°ñ)";

    cat->GetFSM()->ChangeState(Playwith_mouse::Instance());

}


void RestAnd_Sleep::Exit(Cat* cat)
{
}

bool RestAnd_Sleep::OnMessage(Cat* cat, const Telegram& msg) { return false; }



//-----------------------------------------------------------------------------

Eat_Feed* Eat_Feed::Instance()
{
    static Eat_Feed instance;

    return &instance;
}

void Eat_Feed::Enter(Cat* cat)
{

}

void Eat_Feed::Execute(Cat* cat)
{
    cat->Feed();

    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Cat's Eating Sounds";

    cat->GetFSM()->ChangeState(Playwith_mouse::Instance());
}

void Eat_Feed::Exit(Cat* cat)
{
}

bool Eat_Feed::OnMessage(Cat* cat, const Telegram& msg) { return false; }




//-----------------------------------------------------------------------------

Meow_Meow* Meow_Meow::Instance()
{
    static Meow_Meow instance;

    return &instance;
}

void Meow_Meow::Enter(Cat* cat)
{
    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Meow_Meow_Meow_Meow_Meow_Meow";
}

void Meow_Meow::Execute(Cat* cat)
{
    cat->GetFSM()->RevertToPreviousState();
}

void Meow_Meow::Exit(Cat* cat)
{
}

bool Meow_Meow::OnMessage(Cat* cat, const Telegram& msg) { return false; }
