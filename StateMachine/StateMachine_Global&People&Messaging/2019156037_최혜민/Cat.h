#ifndef CAT_H
#define CAT_H

#include <string>
#include <cassert>

#include "BaseGameEntity.h"
#include "BakerLocation.h"
#include "CatOwnedStates.h"
#include "StateMachine.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif
#include <misc/utils.h>





class Cat : public BaseGameEntity
{
private:

    StateMachine<Cat>* m_pStateMachine;

    location_type         m_Location;

    int                   m_Hungry;

    int                   m_Tired;

public:

    Cat(int id) :BaseGameEntity(id),
        m_Location(Home),
        m_Hungry(0),
        m_Tired(0)
    {
        m_pStateMachine = new StateMachine<Cat>(this);
        m_pStateMachine->SetCurrentState(Playwith_mouse::Instance());
        m_pStateMachine->SetGlobalState(CatByGlobalState::Instance());
    }


    ~Cat() { delete m_pStateMachine; }

    //this must be implemented
    void Update();

    //so must this
    virtual bool  HandleMessage(const Telegram& msg);



    StateMachine<Cat>* GetFSM()const { return m_pStateMachine; }



    location_type Location()const { return m_Location; }
    void ChangeLocation(const location_type loc) { m_Location = loc; }

    void Play() {

        switch (RandInt(0, 1))
        {
        case 0:
            m_Hungry += 1;
            break;
        case 1:
            m_Tired += 1;
            break;
        }

    }

    bool CatHungry() const;
    bool CatTired() const;

    void IncreaseHungry() { m_Hungry += 2; }
    void IncreaseTired() { m_Tired += 2; }

    void Rest() { m_Tired = 0; };

    void Feed() { m_Hungry = 0; };

};

#endif
