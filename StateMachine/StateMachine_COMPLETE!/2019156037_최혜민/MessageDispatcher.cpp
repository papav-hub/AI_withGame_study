#include "MessageDispatcher.h"
#include "BaseGameEntity.h"

#include "CrudeTimer.h"


#include "EntityManager.h"
#include "BakerLocation.h"
#include "MessageType.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

using std::set;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

CrudeTimer* CrudeTimer::Instance()
{
    static CrudeTimer instance;

    return &instance;
}



//-----------------------------------------------------------------------------

MessageDispatcher* MessageDispatcher::Instance()
{
    static MessageDispatcher instance;

    return &instance;
}


//-----------------------------------------------------------------------------
void MessageDispatcher::Discharge(BaseGameEntity* pReceiver,
    const Telegram& telegram)
{
    if (!pReceiver->HandleMessage(telegram))
    {
        cout << " // Message not handled";///////////////////////////////////////////////////
    }
}

//-----------------------------------------------------------------------------
void MessageDispatcher::DispatchMessage(double  delay,
    int    sender,
    int    receiver,
    int    msg,
    void* ExtraInfo)
{
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
    BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);

    if (pReceiver == NULL)
    {
        cout << "\nWarning! No Receiver with ID of " << receiver << " found";

        return;
    }

    Telegram telegram(0, sender, receiver, msg, ExtraInfo);

    if (delay <= 0.0f)
    {
        cout << "\nInstant telegram dispatched at time: " << Clock->GetCurrentTime()
            << " by " << GetNameOfEntity(pSender->ID()) << " for " << GetNameOfEntity(pReceiver->ID())
            << ". Msg is " << MsgToStr(msg);

        Discharge(pReceiver, telegram);
    }

    else
    {
        double CurrentTime = Clock->GetCurrentTime();

        telegram.DispatchTime = CurrentTime + delay;

        PriorityQ.insert(telegram);

        cout << "\nDelayed telegram from " << GetNameOfEntity(pSender->ID()) << " recorded at time "
            << Clock->GetCurrentTime() << " for " << GetNameOfEntity(pReceiver->ID())
            << ". Msg is " << MsgToStr(msg);

    }
}


void MessageDispatcher::DispatchDelayedMessages()
{
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    double CurrentTime = Clock->GetCurrentTime();

    while (!PriorityQ.empty() &&
        (PriorityQ.begin()->DispatchTime < CurrentTime) &&
        (PriorityQ.begin()->DispatchTime > 0))
    {
        const Telegram& telegram = *PriorityQ.begin();

        BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);

        cout << "\nQueued telegram ready for dispatch: Sent to "
            << GetNameOfEntity(pReceiver->ID()) << ". Msg is " << MsgToStr(telegram.Msg);

        Discharge(pReceiver, telegram);

        PriorityQ.erase(PriorityQ.begin());
    }
}