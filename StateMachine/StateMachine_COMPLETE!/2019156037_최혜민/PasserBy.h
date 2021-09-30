#ifndef PASSERBY_H
#define PASSERBY_H

#include <string>

#include "State.h"
#include "BaseGameEntity.h"
#include "BakerLocation.h"
#include "PasserByOwnedStates.h"
#include "misc/ConsoleUtils.h"
#include "Baker.h"
#include "StateMachine.h"
#include "misc/Utils.h"



class PasserBy : public BaseGameEntity
{
private:

    StateMachine<PasserBy>* m_pStateMachine;

    location_type              m_Location;


public:

    PasserBy(int id) :BaseGameEntity(id),
        m_Location(Bakery)

    {
        m_pStateMachine = new StateMachine<PasserBy>(this);

        m_pStateMachine->SetCurrentState(Takea_Walk::Instance());

        m_pStateMachine->SetGlobalState(PasserByGlobalState::Instance());
    }

    ~PasserBy() { delete m_pStateMachine; }


    void Update();

    virtual bool  HandleMessage(const Telegram& msg);

    StateMachine<PasserBy>* GetFSM()const { return m_pStateMachine; }

    location_type Location()const { return m_Location; }
    void          ChangeLocation(const location_type loc) { m_Location = loc; }

};



#endif
