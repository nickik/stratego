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
    token spielstein;
    bool stein;
public:
    feld();
    feld(boden, koordinaten, token);
    feld(boden, int, int);
    feld(boden,int,int,token);
    ~feld();
    void bodenbeschafenheit_setter(boden);
    boden bodenbeschafenheit_getter();
    void kords_setter(koordinaten);
    void kords_setter(int,int);
    koordinaten kords_getter();
    void spielstein_setter(token);
    token spielstein_getter();
    bool valid();
    bool stein_getter();
    void stein_setter(bool);
};

#endif // FELD_H_INCLUDED
