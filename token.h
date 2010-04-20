#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include "helpder.h"
#include "feld.h"

enum teamfarbe
{
    blue = 0,
    red
};

enum figur
{
    Feldmarschall = 1,
    General,
    Oberst,
    Major,
    Hauptmann,
    Leutnant,
    Unteroffizier,
    Mineur,
    Aufklaehrer,
    Spion,
    Bombe
}

class token {
private:
    figur spielfigur;
    teamfarbe team;
    feld position;
public:
    token(figur, teamfarbe, feld);
    ~token();
    void figur_setter(figur);
    figur figur_getter();
    void team_setter(teamfarbe);
    teamfarbe team_getter();
    void position_setter(feld);
    feld position_getter();
};

#endif // TOKEN_H_INCLUDED
