#include "token.h"

token::token(figur toeggel, teamfarbe farb, position posi)
{
    figur_setter(toeggel);
    team_setter(farb);
    position_setter(posi);
}

token::~token()
{
    //weisi nanig
}

void token::figur_setter(figur spielstei);
{
    spielfigur = spielstei;
}

figur token::figur_getter();
{
    return spielfigur;
}

void token::team_setter(teamfarbe farb);
{
    team = farb;
}

teamfarbe token::team_getter();
{
    return team;
}

void token::position_setter(feld spielfeld);
{
    position = spielfeld;
}

feld token::position_getter();
{
    return position;
}
