#include "BakerOwnedStates.h"
#include "State.h"
#include "Baker.h"
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


BakerByGlobalState* BakerByGlobalState::Instance() {
    static BakerByGlobalState instance;

    return &instance;
}

void BakerByGlobalState::Enter(Baker* baker) {}

void BakerByGlobalState::Execute(Baker* baker) {

}

void BakerByGlobalState::Exit(Baker* baker){}

bool BakerByGlobalState::OnMessage(Baker* baker, const Telegram& msg) { 

    if (baker->Location() != Bakery)
    {
        return false;
    }
    else {
        return false;
    }


}





//-----------------------------------------------------------------------------

Baking_Oven* Baking_Oven::Instance()
{
    static Baking_Oven instance;

    return &instance;
}

void Baking_Oven::Enter(Baker* pBaker)
{
    if (pBaker->Location() != Oven)
    {
        SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "-> OVEN";

        pBaker->ChangeLocation(Oven);
    }
}


void Baking_Oven::Execute(Baker* pBaker)
{
    pBaker->makeCookies();

    pBaker->decreaseHealth();

    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "make Cookies";

    if (pBaker->pocketFull())
    {
        pBaker->GetFSM()->ChangeState(Selling_Bakery::Instance());
    }

    else if (pBaker->noIngredient())
    {
        pBaker->GetFSM()->ChangeState(Buy_ShoppingMall::Instance());
    }

    else if (pBaker->checkHealth())
    {
        pBaker->GetFSM()->ChangeState(Rest_Home::Instance());
    }
}


void Baking_Oven::Exit(Baker* pBaker)
{
    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": "
        << "Leaving Oven";
}

bool Baking_Oven::OnMessage(Baker* baker, const Telegram& msg) { 
    switch (msg.Msg)
    {
    case mesg_HEY:
        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, baker->ID(), ent_PasserBy, mesg_NO, (void*)NO_ADDITIONAL_INFO);
        return true;
    }

    return false;
}



//-----------------------------------------------------------------------------

Selling_Bakery* Selling_Bakery::Instance()
{
    static Selling_Bakery instance;

    return &instance;
}


void Selling_Bakery::Enter(Baker* pBaker)
{
    if (pBaker->Location() != Bakery)
    {
        SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "->Bakery";

        pBaker->ChangeLocation(Bakery);
    }
}


void Selling_Bakery::Execute(Baker* pBaker)
{

    pBaker->sellCookies();

    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": "
        << "Total displayed now: " << pBaker->currentCookie();

    if (pBaker->displayEmpty())
    {
        SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": "
            << "Displayed Empty";

        pBaker->GetFSM()->ChangeState(Baking_Oven::Instance());
    }
}


void Selling_Bakery::Exit(Baker* pBaker)
{
    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Complete Selling";
}


bool Selling_Bakery::OnMessage(Baker* baker, const Telegram& msg) { 


    switch (msg.Msg)
    {
    case mesg_HEY:
        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, baker->ID(), ent_PasserBy, mesg_NO, (void*)NO_ADDITIONAL_INFO);
        return true;
    }

    return false;
}


//-----------------------------------------------------------------------------

Rest_Home* Rest_Home::Instance()
{
    static Rest_Home instance;

    return &instance;
}

void Rest_Home::Enter(Baker* pBaker)
{
    if (pBaker->Location() != Home)
    {
        SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "->Home";

        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, pBaker->ID(), ent_Cutty_Cat, mesg_HOME, (void*)NO_ADDITIONAL_INFO);


        pBaker->ChangeLocation(Home);
    }
}

void Rest_Home::Execute(Baker* pBaker)
{
    if (!pBaker->checkHealth())
    {
        SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": "
            << "Go to Bakery";

        pBaker->GetFSM()->ChangeState(Baking_Oven::Instance());
    }

    else
    {
        pBaker->increaseHealth();

        SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "ZZZZ... ";
    }
}

void Rest_Home::Exit(Baker* pBaker)
{
    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Leaving the house";
}

bool Rest_Home::OnMessage(Baker* baker, const Telegram& msg) {

    switch (msg.Msg)
    {
    case mesg_HEY:
        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, baker->ID(), ent_PasserBy, mesg_NO, (void*)NO_ADDITIONAL_INFO);
        return true;
    }

    return false;
}



//-----------------------------------------------------------------------------

Buy_ShoppingMall* Buy_ShoppingMall::Instance()
{
    static Buy_ShoppingMall instance;

    return &instance;
}

void Buy_ShoppingMall::Enter(Baker* pBaker)
{
    if (pBaker->Location() != ShoppingMall)
    {
        pBaker->ChangeLocation(ShoppingMall);

        SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "->ShoppingMall";
    }
}

void Buy_ShoppingMall::Execute(Baker* pBaker)
{
    if (pBaker->noIngredient())
    {
        pBaker->buyIngredient();

        SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Buy Ingredient!";

        pBaker->GetFSM()->ChangeState(Baking_Oven::Instance());
    }
}

void Buy_ShoppingMall::Exit(Baker* pBaker)
{
    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Complete Shopping";
}

bool Buy_ShoppingMall::OnMessage(Baker* baker, const Telegram& msg) {
    switch (msg.Msg)
    {
    case mesg_HEY:
        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, baker->ID(), ent_PasserBy, mesg_NO, (void*)NO_ADDITIONAL_INFO);
        return true;
    }

    return false;
}




//-----------------------------------------------------------------------------

HiWithPasserBy* HiWithPasserBy::Instance()
{
    static HiWithPasserBy instance;

    return &instance;
}

void HiWithPasserBy::Enter(Baker* pBaker)
{

}

void HiWithPasserBy::Execute(Baker* pBaker)
{
    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "HI PasserBy";

    pBaker->GetFSM()->RevertToPreviousState();
}

void HiWithPasserBy::Exit(Baker* pBaker)
{
}

bool HiWithPasserBy::OnMessage(Baker* b, const Telegram& msg) {

    return false;
}
