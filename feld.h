#ifndef FELD_H_INCLUDED
#define FELD_H_INCLUDED

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
    boden bodenbeschafenheit;
    koordinaten kords;
    token spielstein; // C irgendwie false or einbauen???
public:
    feld();
    feld(boden, koordinaten, token);
    ~feld();
    void bodenbeschafenheit_setter(boden);
    boden bodenbeschafenheit_getter();
    void kords_setter(koordinaten);
    koordinaten kords_getter();
    void spielstein_setter(token);
    token spielstein_getter();
    bool valid();
};

#endif // FELD_H_INCLUDED
