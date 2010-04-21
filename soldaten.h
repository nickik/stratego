#ifndef SOLDATEN_H_INCLUDED
#define SOLDATEN_H_INCLUDED

#include "token.h"
#include "feld.h"

class soldaten : public token{
private:
    bool fight(feld);
public:
    bool move(feld);
    void highlight();
};

#endif // SOLDATEN_H_INCLUDED
