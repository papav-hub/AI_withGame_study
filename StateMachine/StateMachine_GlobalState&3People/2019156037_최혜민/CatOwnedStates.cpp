#include "CatOwnedStates.h"
#include "State.h"
#include "Cat.h"
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





//--------------------------------------methods for EnterMineAndDigForNugget

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
    //the miner digs for gold until he is carrying in excess of MaxNuggets. 
    //If he gets thirsty during his digging he packs up work for a while and 
    //changes state to go to the saloon for a whiskey.
    cat->Play();


    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Play";

    //if enough gold mined, go and put it in the bank
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



//----------------------------------------methods for VisitBankAndDepositGold

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

    //deposit the gold
    cat->Rest();

    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Rest";

    cat->GetFSM()->ChangeState(Playwith_mouse::Instance());

}


void RestAnd_Sleep::Exit(Cat* cat)
{
}


//----------------------------------------methods for GoHomeAndSleepTilRested

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

    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Feed";

    cat->GetFSM()->ChangeState(Playwith_mouse::Instance());
}

void Eat_Feed::Exit(Cat* cat)
{
}