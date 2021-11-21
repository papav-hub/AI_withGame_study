#include "RunAway_Evaluator.h"/**/
#include "navigation/Raven_PathPlanner.h"/**/
#include "Raven_ObjectEnumerations.h"
#include "lua/Raven_Scriptor.h"
#include "misc/Stream_Utility_Functions.h"
#include "goals/Raven_Feature.h"

#include "goals/Goal_Think.h"
#include "goals/Raven_Goal_Types.h"




//---------------- CalculateDesirability -------------------------------------
//-----------------------------------------------------------------------------
double RunAway_Evaluator::CalculateDesirability(Raven_Bot* pBot)
{
    double Desirability = 0.0;

    if (pBot->GetTargetSys()->isTargetPresent()) {// Ÿ���̶��

        Raven_Bot* target_enemy = pBot->GetTargetSys()->GetTarget();
        double mStrength = Raven_Feature::TotalWeaponStrength(pBot);
        double enemyStrength = Raven_Feature::TotalWeaponStrength(target_enemy);

        if (enemyStrength > mStrength) {//Ÿ���� ���ݷ��� �ڽź��� ������...
            Desirability = Raven_Feature::Strength_Bot(pBot); // ���� ����� ���� ��
        }

    }

    return Desirability;
}

//----------------------------- SetGoal ---------------------------------------
//-----------------------------------------------------------------------------
void RunAway_Evaluator::SetGoal(Raven_Bot* pBot)
{
    pBot->GetBrain()->AddGoal_RunAway();
}

//-------------------------- RenderInfo ---------------------------------------
//-----------------------------------------------------------------------------
void RunAway_Evaluator::RenderInfo(Vector2D Position, Raven_Bot* pBot)
{
    gdi->TextAtPos(Position, "TEST: " + ttos(CalculateDesirability(pBot), 2));
    return;

    std::string s = ttos(Raven_Feature::Health(pBot)) + ", " + ttos(Raven_Feature::TotalWeaponStrength(pBot));
    gdi->TextAtPos(Position + Vector2D(0, 12), s);
}