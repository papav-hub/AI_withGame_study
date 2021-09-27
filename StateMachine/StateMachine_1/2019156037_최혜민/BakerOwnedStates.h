#ifndef MINER_OWNED_STATES_H
#define MINER_OWNED_STATES_H
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


class Baker;


//------------------------------------------------------------------------
//
//  In this state the miner will walk to a goldmine and pick up a nugget
//  of gold. If the miner already has a nugget of gold he'll change state
//  to VisitBankAndDepositGold. If he gets thirsty he'll change state
//  to QuenchThirst
//------------------------------------------------------------------------
class Baking_Oven : public State
{
private:

    Baking_Oven() {}

    //copy ctor and assignment should be private
    Baking_Oven(const Baking_Oven&);
    Baking_Oven& operator=(const Baking_Oven&);

public:

    //this is a singleton
    static Baking_Oven* Instance();

    virtual void Enter(Baker* baker);

    virtual void Execute(Baker* baker);

    virtual void Exit(Baker* baker);
};

//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  miner is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class Selling_Bakery : public State
{
private:

    Selling_Bakery() {}

    //copy ctor and assignment should be private
    Selling_Bakery(const Selling_Bakery&);
    Selling_Bakery& operator=(const Selling_Bakery&);

public:

    //this is a singleton
    static Selling_Bakery* Instance();

    virtual void Enter(Baker* baker);

    virtual void Execute(Baker* baker);

    virtual void Exit(Baker* baker);
};


//------------------------------------------------------------------------
//
//  miner will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class Rest_Home : public State
{
private:

    Rest_Home() {}

    //copy ctor and assignment should be private
    Rest_Home(const Rest_Home&);
    Rest_Home& operator=(const Rest_Home&);

public:

    //this is a singleton
    static Rest_Home* Instance();

    virtual void Enter(Baker* baker);

    virtual void Execute(Baker* baker);

    virtual void Exit(Baker* baker);
};


//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
class Buy_ShoppingMall : public State
{
private:

    Buy_ShoppingMall() {}

    //copy ctor and assignment should be private
    Buy_ShoppingMall(const Buy_ShoppingMall&);
    Buy_ShoppingMall& operator=(const Buy_ShoppingMall&);

public:

    //this is a singleton
    static Buy_ShoppingMall* Instance();

    virtual void Enter(Baker* baker);

    virtual void Execute(Baker* baker);

    virtual void Exit(Baker* baker);
};





#endif