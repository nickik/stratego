#include "token.h"

token::token()
{
}

token::token(figur f, teamfarbe t)
{
    figur_setter(f);
    team_setter(t);
}

token::~token()
{
    //weisi nanig
}

void token::figur_setter(figur spielstei)
{
    spielfigur = spielstei;
}

figur token::figur_getter()
{
    return spielfigur;
}

void token::team_setter(teamfarbe farb)
{
    team = farb;
}

teamfarbe token::team_getter()
{
    return team;
}
/*
void token::position_setter(feld spielfeld);
{
    spielfeld.spielfigur_setter(this);
    position = spielfeld;
}

feld token::position_getter();
{
    return position;
}
*/
