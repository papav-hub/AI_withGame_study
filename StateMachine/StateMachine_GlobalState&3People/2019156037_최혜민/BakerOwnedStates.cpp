#include "BakerOwnedStates.h"
#include "State.h"
#include "Baker.h"
#include "BakerLocation.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

//define this to output to a file
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





//--------------------------------------methods for EnterMineAndDigForNugget

Baking_Oven* Baking_Oven::Instance()
{
    static Baking_Oven instance;

    return &instance;
}

void Baking_Oven::Enter(Baker* pBaker)
{
    //if the miner is not already located at the goldmine, he must
    //change location to the gold mine
    if (pBaker->Location() != Oven)
    {
        SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "-> OVEN";

        pBaker->ChangeLocation(Oven);
    }
}


void Baking_Oven::Execute(Baker* pBaker)
{
    //the miner digs for gold until he is carrying in excess of MaxNuggets. 
    //If he gets thirsty during his digging he packs up work for a while and 
    //changes state to go to the saloon for a whiskey.
    pBaker->makeCookies();

    pBaker->decreaseHealth();

    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "make Cookies";

    //if enough gold mined, go and put it in the bank
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



//----------------------------------------methods for VisitBankAndDepositGold

Selling_Bakery* Selling_Bakery::Instance()
{
    static Selling_Bakery instance;

    return &instance;
}


void Selling_Bakery::Enter(Baker* pBaker)
{
    //on entry the miner makes sure he is located at the bank
    if (pBaker->Location() != Bakery)
    {
        SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "->Bakery";

        pBaker->ChangeLocation(Bakery);
    }
}


void Selling_Bakery::Execute(Baker* pBaker)
{

    //deposit the gold
    pBaker->sellCookies();

    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": "
        << "Total displayed now: " << pBaker->currentCookie();

    //wealthy enough to have a well earned rest?
    if (pBaker->displayEmpty())
    {
        SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": "
            << "Displayed Empty";

        pBaker->GetFSM()->ChangeState(Baking_Oven::Instance());
    }
}


void Selling_Bakery::Exit(Baker* pBaker)
{
    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Complete Selling";
}


//----------------------------------------methods for GoHomeAndSleepTilRested

Rest_Home* Rest_Home::Instance()
{
    static Rest_Home instance;

    return &instance;
}

void Rest_Home::Enter(Baker* pBaker)
{
    if (pBaker->Location() != Home)
    {
        SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "->Home";

        pBaker->ChangeLocation(Home);
    }
}

void Rest_Home::Execute(Baker* pBaker)
{
    //if miner is not fatigued start to dig for nuggets again.
    if (!pBaker->checkHealth())
    {
        SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": "
            << "Go to Bakery";

        pBaker->GetFSM()->ChangeState(Baking_Oven::Instance());
    }

    else
    {
        //sleep
        pBaker->increaseHealth();

        SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "ZZZZ... ";
    }
}

void Rest_Home::Exit(Baker* pBaker)
{
    SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Leaving the house";
}




//------------------------------------------------methods for QuenchThirst

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

        SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "->ShoppingMall";
    }
}

void Buy_ShoppingMall::Execute(Baker* pBaker)
{
    if (pBaker->noIngredient())
    {
        pBaker->buyIngredient();

        SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Buy Ingredient!";

        pBaker->GetFSM()->ChangeState(Baking_Oven::Instance());
    }
}

void Buy_ShoppingMall::Exit(Baker* pBaker)
{
    SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Complete Shopping";
}

