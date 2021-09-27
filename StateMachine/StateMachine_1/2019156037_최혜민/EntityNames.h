#ifndef NAMES_H
#define NAMES_H

#include <string>

enum
{
    ent_Mr_Baker,
    ent_Mr_Owner,
    ent_Cutty_Cat
};

inline std::string GetNameOfEntity(int n)
{
    switch (n)
    {
    case ent_Mr_Baker:

        return "Mr.Baker";

    case ent_Mr_Owner:

        return "Mr.Owner";

    case ent_Cutty_Cat:

        return "CAT";

    default:

        return "UNKNOWN!";
    }
}

#endif