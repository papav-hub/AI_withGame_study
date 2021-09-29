#ifndef CAT_OWNED_STATES_H
#define CAT_OWNED_STATES_H

#include "State.h"
#include "fsm/State.h"


class Cat;
struct Telegram;

//-----------------------------------------------------------------------------


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

    virtual bool OnMessage(Cat* cat, const Telegram& msg);
};

//-----------------------------------------------------------------------------
class Playwith_mouse : public State<Cat>
{
private:

    Playwith_mouse() {}

    Playwith_mouse(const Playwith_mouse&);
    Playwith_mouse& operator=(const Playwith_mouse&);

public:

    static Playwith_mouse* Instance();


    virtual void Enter(Cat* cat);

    virtual void Execute(Cat* cat);

    virtual void Exit(Cat* cat);

    virtual bool OnMessage(Cat* cat, const Telegram& msg);

};

//-----------------------------------------------------------------------------
class RestAnd_Sleep : public State<Cat>
{
private:

    RestAnd_Sleep() {}

    RestAnd_Sleep(const RestAnd_Sleep&);
    RestAnd_Sleep& operator=(const RestAnd_Sleep&);

public:

    static RestAnd_Sleep* Instance();

    virtual void Enter(Cat* cat);

    virtual void Execute(Cat* cat);

    virtual void Exit(Cat* cat);

    virtual bool OnMessage(Cat* cat, const Telegram& msg);

};


//-----------------------------------------------------------------------------
class Eat_Feed : public State<Cat>
{
private:

    Eat_Feed() {}

    Eat_Feed(const Eat_Feed&);
    Eat_Feed& operator=(const Eat_Feed&);

public:

    static Eat_Feed* Instance();

    virtual void Enter(Cat* cat);

    virtual void Execute(Cat* cat);

    virtual void Exit(Cat* cat);

    virtual bool OnMessage(Cat* cat, const Telegram& msg);

};

//-----------------------------------------------------------------------------
class Meow_Meow : public State<Cat>
{
private:

    Meow_Meow() {}

    Meow_Meow(const Meow_Meow&);
    Meow_Meow& operator=(const Meow_Meow&);

public:

    static Meow_Meow* Instance();

    virtual void Enter(Cat* cat);

    virtual void Execute(Cat* cat);

    virtual void Exit(Cat* cat);

    virtual bool OnMessage(Cat* cat, const Telegram& msg);

};


#endif