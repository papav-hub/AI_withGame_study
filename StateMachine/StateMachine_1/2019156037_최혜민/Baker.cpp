#include "Baker.h"
#include "BakerOwnedStates.h"

Baker::Baker(int id) :BaseGameEntity(id),
    m_Location(Oven),
    m_cookie(0),
    m_health(5),
    m_ingredient(1),
    m_money(5),
    m_pCurrentState(Baking_Oven::Instance())

{}

//--------------------------- ChangeState -------------------------------------
//-----------------------------------------------------------------------------
void Baker::ChangeState(State* pNewState)
{
    //make sure both states are both valid before attempting to 
    //call their methods
    assert(m_pCurrentState && pNewState);

    //call the exit method of the existing state
    m_pCurrentState->Exit(this);

    //change state to the new state
    m_pCurrentState = pNewState;

    //call the entry method of the new state
    m_pCurrentState->Enter(this);
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
void Baker::Update()
{

    if (m_pCurrentState)
    {
        m_pCurrentState->Execute(this);
    }
}


//-----------------------------------------------------------------------------
bool Baker::pocketFull()const
{
    if (m_cookie >= pocket_max)
    {
        return true;
    }

    return false;
}

bool Baker::noIngredient()const
{
    if (m_ingredient >= ingredient_min)
    {
        return false;
    }

    return true;
}

bool Baker::checkHealth()const
{
    if (m_health >= health_min)
    {
        return false;
    }

    return true;
}

bool Baker::displayEmpty()const
{
    if (m_cookie > 0)
    {
        return false;
    }

    return true;
}