#include "feld.h"

feld::feld(boden b, koordinaten k, token t)
{
    bodenbeschafenheit_setter(b);
    kords_setter(k);
    spielstein_setter(t);
}

feld::feld()
{
}

feld::~feld(){
    //kei ahnig was da ahne chunt
}

void feld::bodenbeschafenheit_setter(boden b){
    bodenbeschafenheit = b;
}

boden feld::bodenbeschafenheit_getter(){
    return bodenbeschafenheit;
}

void feld::kords_setter(koordinaten k){
    kords = k;
}

koordinaten feld::kords_getter(){
    return kords;
}

void feld::spielstein_setter(token t)
{
    spielstein = t;
}

token feld::spielstein_getter()
{
    return spielstein;
}

bool feld::valid()
{
    if(bodenbeschafenheit_getter() == land)
    {
        return true;
    }
    return false;
}
