#include <fstream>
#include "BakerLocation.h"
#include "Baker.h"
#include "PasserBy.h"
#include "Cat.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"



std::ofstream os;

int main()
{
    //define this to send output to a text file (see locations.h)
#ifdef TEXTOUTPUT
    os.open("output.txt");
#endif

    //create a miner
    Baker bake(ent_Mr_Baker);

    //create his wife
    PasserBy pass(ent_PasserBy);

    Cat cat(ent_Cutty_Cat);

    //run Bob and Elsa through a few Update calls
    for (int i = 0; i < 20; ++i)
    {
        bake.Update();
        pass.Update();
        cat.Update();

        Sleep(800);
    }

    //wait for a keypress before exiting
    PressAnyKeyToContinue();

    return 0;
}






