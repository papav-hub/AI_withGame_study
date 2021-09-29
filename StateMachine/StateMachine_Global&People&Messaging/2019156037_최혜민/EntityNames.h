#ifndef NAMES_H
#define NAMES_H

#include <string>

enum
{
    ent_Mr_Baker,
    ent_PasserBy,
    ent_Cutty_Cat
};

inline std::string GetNameOfEntity(int n)
{
    switch (n)
    {
    case ent_Mr_Baker:

        return "Mr.Baker";

    case ent_PasserBy:

        return "Mr.PasserBy";

    case ent_Cutty_Cat:

        return "CAT";

    default:

        return "UNKNOWN!";
    }
}

#endif