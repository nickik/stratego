#ifndef HELPDER_H_INCLUDED
#define HELPDER_H_INCLUDED

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

enum teamfarbe
{
    blue = 0,
    red
};

struct move
{
    //feld startfeld;
    //feld endfeld;
    int start;
    int endefeld;
};


#endif // HELPDER_H_INCLUDED
