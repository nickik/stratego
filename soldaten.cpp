#include "soldaten.h"

bool soldaten::move(feld zug)
{
     if(isGround(zug) == true)
     {
         return false;
     }

     if(isTeam(zug) == true)
     {
         return false;
     }

     if(isEmpty(zug) == true)
     {
         makemove(zug);
         return true;
     }

     if(isEnemy(zug) == true)
     {
         if(fight(zug) == true)
         {
             makemove(zug);
             return true;
         }
         else
         {
            return true;
            //soldat löschen!
         }
     }
}

bool soldaten::isGround(feld zug)
{
    if(zug.bodenbeschaffenheit_getter() == land)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool soldaten::isTeam(feld zug)
{
    token zielstein;
    zielstein = zug.spielstein_getter();
    if (zielstein.team_getter() == this.team_getter())
    {
        return true;
    }
    else
    {
        return true;
    }
}

bool soldaten::isEmpty(feld zug)
{
    token zielstein;
    zielstein = zug.spielstein_getter();
    if (zielstein == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool soldaten::fight(feld zug)
{
    //hier werden die fights ausgetragen
    return true;
}


void soldaten::highlight()
{
    //hier wird voresrst nichts implementiert

}
