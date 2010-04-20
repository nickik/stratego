#include "feld.h"

feld(bool b, boden bo, token t){
    besetzt_setter(bool b);
    bodenbeschafenheit_setter(boden bo);
    spielstein_setter(token t);
}

~token(){
    //kei ahnig was da ahne chunt
}

void besetzt_setter(bool b){
    besetzt = b;
}

bool besetzt_getter(){
    return besetzt;
}

void bodenbeschafenheit_setter(boden b){
    bodenbeschafenheit = b;
}

boden bodenbeschafenheit_getter(){
    return bodenbeschafenheit;
}

void spielstein_setter(token t){
    spielstein = t;
}

token spielstein_getter(){
    return spielstein;
}

void kords_setter(koordinaten){
    kords = koordinaten;
}

koordinaten kords_setter(){
    return koordinaten;
}
