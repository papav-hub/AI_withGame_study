#include "Baker.h"
#include "misc/ConsoleUtils.h"


//-----------------------------------------------------------------------------
void Baker::Update()
{
    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

    m_pStateMachine->Update();
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