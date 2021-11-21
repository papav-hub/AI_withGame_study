#ifndef RUNAWAYSEARCHITEM_EVALUATOR/**/
#define RUNAWAYSEARCHITEM_EVALUATOR/**/
#pragma warning (disable:4786)

//-----------------------------------------------------------------------------
//
//  Name:   RunAway_Evaluator.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:  class to calculate how desirable the goal of exploring is
//-----------------------------------------------------------------------------

#include "goals/Goal_Evaluator.h"
#include "Raven_Bot.h"


class RunAway_Evaluator : public Goal_Evaluator
{
public:

    RunAway_Evaluator(double bias) :Goal_Evaluator(bias) {}

    double CalculateDesirability(Raven_Bot* pBot);

    void  SetGoal(Raven_Bot* pEnt);

    void RenderInfo(Vector2D Position, Raven_Bot* pBot);
};

#endif 