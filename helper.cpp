#include "helper.h"

enum boden
{
    land = 0,
    wasser
};

struct kordinaten
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
    Feld startfeld;
    Feld endfeld;
};
