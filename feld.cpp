#include "feld.h"

void feld::stein_setter(bool b)
{
    stein = b;
}

bool feld::stein_getter()
{
    return stein;
}

feld::feld(boden b, koordinaten k, token t)
{
    bodenbeschafenheit_setter(b);
    kords_setter(k);
    spielstein_setter(t);
    stein_setter(true);
}
feld::feld(boden b, int i, int n, token t)
{
    bodenbeschafenheit_setter(b);
    kords_setter(i,n);
    spielstein_setter(t);
    stein_setter(true);
}
feld::feld(boden b, int i, int n)
{
    bodenbeschafenheit_setter(b);
    kords_setter(i,n);
    stein_setter(false);
}

feld::feld()
{
    stein_setter(false);
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

void feld::kords_setter(int i, int n){
    koordinaten k;
    k.x = i;
    k.y = n;
    kords = k;
}

koordinaten feld::kords_getter(){
    return kords;
}

void feld::spielstein_setter(token t)
{
    stein_setter(true);
    spielstein = t;
}

token feld::spielstein_getter()
{
        return spielstein;
}

bool feld::valid()
{
    stein=true;
    if(bodenbeschafenheit_getter() == land)
    {
        return true;
    }
    return false;
}


