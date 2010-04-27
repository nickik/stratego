#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include "drawengine.h"
#include "helper.h"


class token{
private:
    figur spielfigur;
    teamfarbe team;
public:
    token();
    token(figur, teamfarbe);
    ~token();
    void figur_setter(figur);
    figur figur_getter();
    void team_setter(teamfarbe);
    teamfarbe team_getter();
};

#endif // TOKEN_H_INCLUDED
