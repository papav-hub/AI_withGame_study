#ifndef CAT_OWNED_STATES_H
#define CAT_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinerOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Miner class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "State.h"


class Cat;


//------------------------------------------------------------------------
//
//  In this state the miner will walk to a goldmine and pick up a nugget
//  of gold. If the miner already has a nugget of gold he'll change state
//  to VisitBankAndDepositGold. If he gets thirsty he'll change state
//  to QuenchThirst
//------------------------------------------------------------------------
class CatByGlobalState : public State<Cat>
{
private:
    CatByGlobalState() {}

    CatByGlobalState(const CatByGlobalState&);
    CatByGlobalState& operator=(const CatByGlobalState&);

public:

    static CatByGlobalState* Instance();

    virtual void Enter(Cat* cat);

    virtual void Execute(Cat* cat);

    virtual void Exit(Cat* cat);
};

/// <summary>
/// ////////////////// ////////////////// ////////////////// ////////////////// //////////////////
/// </summary>
class Playwith_mouse : public State<Cat>
{
private:

    Playwith_mouse() {}

    //copy ctor and assignment should be private
    Playwith_mouse(const Playwith_mouse&);
    Playwith_mouse& operator=(const Playwith_mouse&);

public:

    //this is a singleton
    static Playwith_mouse* Instance();


    virtual void Enter(Cat* cat);

    virtual void Execute(Cat* cat);

    virtual void Exit(Cat* cat);
};

//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  miner is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class RestAnd_Sleep : public State<Cat>
{
private:

    RestAnd_Sleep() {}

    //copy ctor and assignment should be private
    RestAnd_Sleep(const RestAnd_Sleep&);
    RestAnd_Sleep& operator=(const RestAnd_Sleep&);

public:

    //this is a singleton
    static RestAnd_Sleep* Instance();

    virtual void Enter(Cat* cat);

    virtual void Execute(Cat* cat);

    virtual void Exit(Cat* cat);
};


//------------------------------------------------------------------------
//
//  miner will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class Eat_Feed : public State<Cat>
{
private:

    Eat_Feed() {}

    //copy ctor and assignment should be private
    Eat_Feed(const Eat_Feed&);
    Eat_Feed& operator=(const Eat_Feed&);

public:

    //this is a singleton
    static Eat_Feed* Instance();

    virtual void Enter(Cat* cat);

    virtual void Execute(Cat* cat);

    virtual void Exit(Cat* cat);
};



#endif