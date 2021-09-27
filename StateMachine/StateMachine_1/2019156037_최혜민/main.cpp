#include "BakerLocation.h"
#include "Baker.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"


int main()
{
    //create a miner
    Baker baker(ent_Mr_Baker);

    //simply run the miner through a few Update calls
    for (int i = 0; i < 20; ++i)
    {
        baker.Update();

        Sleep(800);
    }

    //wait for a keypress before exiting
    PressAnyKeyToContinue();

    return 0;
}