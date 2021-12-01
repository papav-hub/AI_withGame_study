#include "Goal_Think.h"
#include <list>
#include "misc/Cgdi.h"
#include "../Raven_ObjectEnumerations.h"
#include "misc/utils.h"
#include "../lua/Raven_Scriptor.h"

#include "Goal_MoveToPosition.h"
#include "Goal_Explore.h"
#include "Goal_GetItem.h"
#include "Goal_Wander.h"
#include "Raven_Goal_Types.h"
#include "Goal_AttackTarget.h"
/**/
#include "../Goal_RunAway.h"
/**/


#include "GetWeaponGoal_Evaluator.h"
#include "GetHealthGoal_Evaluator.h"
#include "ExploreGoal_Evaluator.h"
#include "AttackTargetGoal_Evaluator.h"
/**/
#include "../RunAway_Evaluator.h"
/**/


Goal_Think::Goal_Think(Raven_Bot* pBot):Goal_Composite<Raven_Bot>(pBot, goal_think)
{
  
  //these biases could be loaded in from a script on a per bot basis
  //but for now we'll just give them some random values
  const double LowRangeOfBias = 0.5;
  const double HighRangeOfBias = 1.5;

  double HealthBias = RandInRange(LowRangeOfBias, HighRangeOfBias);
  double ShotgunBias = RandInRange(LowRangeOfBias, HighRangeOfBias);
  double RocketLauncherBias = RandInRange(LowRangeOfBias, HighRangeOfBias);
  double RailgunBias = RandInRange(LowRangeOfBias, HighRangeOfBias);
  double ExploreBias = RandInRange(LowRangeOfBias, HighRangeOfBias);
  double AttackBias = RandInRange(LowRangeOfBias, HighRangeOfBias);
  /**/
  double RunAwayBias = RandInRange(LowRangeOfBias, HighRangeOfBias);/**/
  /**/

  //create the evaluator objects // Goal_think에서 우선순위 판단할거 6개 // 6개 중에서 고른다.
  m_Evaluators.push_back(new GetHealthGoal_Evaluator(HealthBias)); //2
  m_Evaluators.push_back(new ExploreGoal_Evaluator(ExploreBias)); //1
  m_Evaluators.push_back(new AttackTargetGoal_Evaluator(AttackBias)); //6
  m_Evaluators.push_back(new GetWeaponGoal_Evaluator(ShotgunBias,
                                                     type_shotgun)); //4
  m_Evaluators.push_back(new GetWeaponGoal_Evaluator(RailgunBias,
                                                     type_rail_gun)); //5
  m_Evaluators.push_back(new GetWeaponGoal_Evaluator(RocketLauncherBias,
                                                     type_rocket_launcher)); //3
  /**/
  m_Evaluators.push_back(new RunAway_Evaluator(RunAwayBias));/**/
  /**/
}


/**/
//----------------------------- AddGoal_RunAwayGoal ------------------------------------------
//-----------------------------------------------------------------------------
void Goal_Think::AddGoal_RunAway()
{
    if (notPresent(goal_RunAway))
    {
        RemoveAllSubgoals();
        AddSubgoal(new Goal_RunAway(m_pOwner));
    }
}
/**/
//----------------------------- dtor ------------------------------------------
//-----------------------------------------------------------------------------
Goal_Think::~Goal_Think()
{
  GoalEvaluators::iterator curDes = m_Evaluators.begin();
  for (curDes; curDes != m_Evaluators.end(); ++curDes)
  {
    delete *curDes;
  }
}

//------------------------------- Activate ------------------------------------
//-----------------------------------------------------------------------------
void Goal_Think::Activate()
{
  if (!m_pOwner->isPossessed())
  {
    Arbitrate();
  }

  m_iStatus = active;
}

//------------------------------ Process --------------------------------------
//
//  processes the subgoals
//-----------------------------------------------------------------------------
int Goal_Think::Process()
{
  ActivateIfInactive(); // 프로세스에 들어왔을 때 꺼져있으면 초기화 // state에서 enter하면서 초기화 하는 것과 비슷하다. // Activate()에 해당한다.
  // Goal마다 하는 일이 다르다. Pattern은 비슷하다.
  
  int SubgoalStatus = ProcessSubgoals(); // 주요 사항 // think가 거느리고 있는 부모를 처리한다.

  if (SubgoalStatus == completed || SubgoalStatus == failed)
  {
    if (!m_pOwner->isPossessed())
    {
      m_iStatus = inactive;
    }
  }

  return m_iStatus;
}

//----------------------------- Update ----------------------------------------
// 
//  this method iterates through each goal option to determine which one has
//  the highest desirability.
//-----------------------------------------------------------------------------
void Goal_Think::Arbitrate()
{
  double best = 0;
  Goal_Evaluator* MostDesirable = 0;

  //iterate through all the evaluators to see which produces the highest score
  GoalEvaluators::iterator curDes = m_Evaluators.begin();
  for (curDes; curDes != m_Evaluators.end(); ++curDes)
  {
    double desirabilty = (*curDes)->CalculateDesirability(m_pOwner); // 점수 높은거 계산하기

    if (desirabilty >= best)
    {
      best = desirabilty;
      MostDesirable = *curDes;
    }
  }

  assert(MostDesirable && "<Goal_Think::Arbitrate>: no evaluator selected");

  MostDesirable->SetGoal(m_pOwner);
}


//---------------------------- notPresent --------------------------------------
//
//  returns true if the goal type passed as a parameter is the same as this
//  goal or any of its subgoals
//-----------------------------------------------------------------------------
bool Goal_Think::notPresent(unsigned int GoalType)const /////////////// 내가 지금 AttackTarget 하고 있음? 물어봄
// 내가 판단할 때가 되었을때 우선순위가 똑같은지 파악
{
  if (!m_SubGoals.empty())
  {
    return m_SubGoals.front()->GetType() != GoalType;
  }

  return true;
}

void Goal_Think::AddGoal_MoveToPosition(Vector2D pos)
{
  AddSubgoal( new Goal_MoveToPosition(m_pOwner, pos));
}

void Goal_Think::AddGoal_Explore()
{
  if (notPresent(goal_explore)) // 우선순위가 바뀜
  {
    RemoveAllSubgoals(); // 다 지우고 
    AddSubgoal( new Goal_Explore(m_pOwner)); // 다른 서브 골을 넣는다.
  }
}

void Goal_Think::AddGoal_GetItem(unsigned int ItemType)
{
  if (notPresent(ItemTypeToGoalType(ItemType)))
  {
    RemoveAllSubgoals();
    AddSubgoal( new Goal_GetItem(m_pOwner, ItemType));
  }
}

void Goal_Think::AddGoal_AttackTarget()////////////////////////////////////////////
{
  if (notPresent(goal_attack_target)) 
  {
    RemoveAllSubgoals();
    AddSubgoal( new Goal_AttackTarget(m_pOwner));
  }
}

//-------------------------- Queue Goals --------------------------------------
//-----------------------------------------------------------------------------
void Goal_Think::QueueGoal_MoveToPosition(Vector2D pos)
{
   m_SubGoals.push_back(new Goal_MoveToPosition(m_pOwner, pos));
}



//----------------------- RenderEvaluations -----------------------------------
//-----------------------------------------------------------------------------
void Goal_Think::RenderEvaluations(int left, int top)const
{
  gdi->TextColor(Cgdi::black);
  
  std::vector<Goal_Evaluator*>::const_iterator curDes = m_Evaluators.begin();
  for (curDes; curDes != m_Evaluators.end(); ++curDes)
  {
    (*curDes)->RenderInfo(Vector2D(left, top), m_pOwner);

    left += 75;
  }
}

void Goal_Think::Render()
{
  std::list<Goal<Raven_Bot>*>::iterator curG;
  for (curG=m_SubGoals.begin(); curG != m_SubGoals.end(); ++curG)
  {
    (*curG)->Render();
  }
}


   
