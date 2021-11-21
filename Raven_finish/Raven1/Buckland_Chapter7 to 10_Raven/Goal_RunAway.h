#ifndef GOAL_RUNAWAYSEARCHITEM/**/
#define GOAL_RUNAWAYSEARCHITEM/**/
#pragma warning (disable:4786)

#include "Goals/Goal_Composite.h"
#include "goals/Raven_Goal_Types.h"

class Raven_Bot;

class Goal_RunAway : public Goal_Composite<Raven_Bot>
{
private:

public:

    Goal_RunAway(Raven_Bot* pOwner) :Goal_Composite<Raven_Bot>(pOwner, goal_RunAway) {}

    void Activate();
    int Process();
    void Terminate();

};

#endif