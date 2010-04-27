#ifndef FELD_H_INCLUDED
#define FELD_H_INCLUDED

#include "token.h"
#include "helper.h"

class feld{
private:
    boden bodenbeschafenheit;
    int kx;
    int ky;
    token spielstein;
    bool stein;
public:
    feld();
    feld(boden,int,int,token);
    feld(boden, int, int);
    ~feld();
    void bodenbeschafenheit_setter(boden);
    boden bodenbeschafenheit_getter();
    void spielstein_setter(token);
    token spielstein_getter();
    bool valid();
    bool stein_getter();
    void stein_setter(bool);
    void draw();
    void kx_setter( int );
    int kx_getter();
    void ky_setter( int );
    int ky_getter();
};

#endif // FELD_H_INCLUDED
