#ifndef MESSAGE_TYPE
#define MESSAGE_TYPE

#include <string>

enum message_type
{
    mesg_HOME,
    mesg_MEOW,
    mesg_HEY,
    mesg_NO
};


inline std::string MsgToStr(int msg)
{
    switch (msg)
    {
    case mesg_HOME:

        return "I'm home";

    case mesg_MEOW:

        return "MEOWWWWWWW";

    case mesg_HEY:

        return "HEY Good Day!";

    case mesg_NO:

        return "MR.BREAD is not exist";

    default:

        return "Not recognized!";
    }
}

#endif