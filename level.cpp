#include "level.h"

level::level()
{
}

level::~level()
{
}

bool level::move(feld source,feld destination)
{
    return validmove(source, destination);
}

bool level::validmove(feld source_feld,feld ziel_feld)
{
    if(source_feld.valid() and ziel_feld.valid())
    {
        if(source_feld.spielstein_getter().team_getter() != ziel_feld.spielstein_getter().team_getter())
        {
            return true;
        }
    }
    return false;
}

bool level::load_aufstellung( char filename )
{
    return false;
}

bool level::init_feld()
{
    return false;
}
