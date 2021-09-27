#include "Cat.h"
#include "misc/ConsoleUtils.h"


#include <misc/utils.h>


//-----------------------------------------------------------------------------
void Cat::Update()
{
    SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

    m_pStateMachine->Update();
}


//-----------------------------------------------------------------------------

bool Cat::CatHungry()const {
    if (m_Hungry >= 5) {
        return true;
    }

    return false;
}

bool Cat::CatTired()const {
    if (m_Tired >= 5) {
        return true;
    }

    return false;
}