#ifndef MINER_OWNED_STATES_H
#define MINER_OWNED_STATES_H
#include "State.h"
#include "fsm/State.h"

class Baker;
struct Telegram;

class BakerByGlobalState : public State<Baker> 
{
private:
    BakerByGlobalState(){}

    BakerByGlobalState(const BakerByGlobalState&);
    BakerByGlobalState& operator=(const BakerByGlobalState&);

public:

    static BakerByGlobalState* Instance();

    virtual void Enter(Baker* baker);

    virtual void Execute(Baker* baker);

    virtual void Exit(Baker* baker);

    virtual bool OnMessage(Baker* agent, const Telegram& msg);
};

//-----------------------------------------------------------------------------


class Baking_Oven : public State<Baker>
{
private:

    Baking_Oven() {}

    Baking_Oven(const Baking_Oven&);
    Baking_Oven& operator=(const Baking_Oven&);

public:

    static Baking_Oven* Instance();

    virtual void Enter(Baker* baker);

    virtual void Execute(Baker* baker);

    virtual void Exit(Baker* baker);

    virtual bool OnMessage(Baker* agent, const Telegram& msg);

};

//------------------------------------------------------------------------
class Selling_Bakery : public State<Baker>
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

    virtual bool OnMessage(Baker* agent, const Telegram& msg);

};

//-----------------------------------------------------------------------------
class Rest_Home : public State<Baker>
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

    virtual bool OnMessage(Baker* agent, const Telegram& msg);

};


//-----------------------------------------------------------------------------
class Buy_ShoppingMall : public State<Baker>
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

    virtual bool OnMessage(Baker* agent, const Telegram& msg);

};

//-----------------------------------------------------------------------------
class HiWithPasserBy : public State<Baker>
{
private:

    HiWithPasserBy() {}

    //copy ctor and assignment should be private
    HiWithPasserBy(const HiWithPasserBy&);
    HiWithPasserBy& operator=(const HiWithPasserBy&);

public:

    //this is a singleton
    static HiWithPasserBy* Instance();

    virtual void Enter(Baker* baker);

    virtual void Execute(Baker* baker);

    virtual void Exit(Baker* baker);

    virtual bool OnMessage(Baker* agent, const Telegram& msg);

};





#endif