#include <fstream>
#include <time.h>

#include "BakerLocation.h"
#include "Baker.h"
#include "PasserBy.h"
#include "Cat.h"

#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "misc/ConsoleUtils.h"

#include "misc/ConsoleUtils.h"
#include "EntityNames.h"



std::ofstream os;

int main()
{
#ifdef TEXTOUTPUT
    os.open("output.txt");
#endif

    //-----------------------------------------------------------------------------
    srand((unsigned)time(NULL));

    //-----------------------------------------------------------------------------
    Baker* bake = new Baker(ent_Mr_Baker);

    PasserBy* pass = new PasserBy(ent_PasserBy);

    Cat* cat = new Cat(ent_Cutty_Cat);

    //-----------------------------------------------------------------------------
    EntityMgr->RegisterEntity(bake);
    EntityMgr->RegisterEntity(pass);
    EntityMgr->RegisterEntity(cat);

    //-----------------------------------------------------------------------------
    for (int i = 0; i < 30; ++i)
    {
        bake->Update();
        pass->Update();
        cat->Update();

//-----------------------------------------------------------------------------
        Dispatch->DispatchDelayedMessages();

        Sleep(800);
    }

    //-----------------------------------------------------------------------------
    delete bake;
    delete pass;
    delete cat;

    //-----------------------------------------------------------------------------
    PressAnyKeyToContinue();


    return 0;
}