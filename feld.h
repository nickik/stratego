#ifndef FELD_H_INCLUDED
#define FELD_H_INCLUDED

#include "game.h"
#include "helpder.h"
#include "token.h"

enum boden
{
    land = 0,
    wasser
};

struct koordinaten
{
    int x;
    int y;
};

class feld{
private:
    bool besetzt;
    boden bodenbeschafenheit;
    token spielstein;
    koordinaten kords;
public:
    feld(bool, boden, token);
    ~feld();
    void besetzt_setter(bool);
    bool besetzt_getter();
    void bodenbeschafenheit_setter(boden);
    boden bodenbeschafenheit_getter();
    void spielstein_setter(token);
    token spielstein_getter();
    void kords_setter(koordinaten);
    koordinaten kords_setter();
};


#endif // FELD_H_INCLUDED
