#include "feld.h"

void feld::stein_setter(bool b)
{
    stein = b;
}

bool feld::stein_getter()
{
    return stein;
}

feld::feld(boden b, int i, int n, token t)
{
    bodenbeschafenheit_setter(b);
    kx_setter( i );
    ky_setter( n );
    spielstein_setter(t);
    stein_setter(true);
}
feld::feld(boden b, int i, int n)
{
    bodenbeschafenheit_setter(b);
    kx_setter( i );
    ky_setter( n );
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

void feld::draw()
{
    drawengine de;
    //de.draw_token(kords_getter(), spielstein_getter().figur_getter(), spielstein_getter().team_getter());
}

void feld::kx_setter( int x )
{
    kx = x;
}

int feld::kx_getter()
{
    return kx;
}

void feld::ky_setter( int y )
{
    ky = y;
}

int feld::ky_getter()
{
    return ky;
}
