#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "feld.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "libxml2/libxml/parser.h"
#include "libxml2/libxml/xmlmemory.h"
#include "token.h"
#include "drawengine.h"

class level{
private:
    feld spielfeld[10][10];
public:
    level();
    ~level();
    bool move(feld,feld);
    bool validmove(feld,feld);
    bool load_aufstellung( std::string filename );
    bool feldadd(std::string, int, std::string);
    bool init_feld();
    void parse_aufstellung(std::string);
    void parse_feld(xmlDocPtr, xmlNodePtr);
    figur string_to_figur(std::string);
    bool draw_spielfeld();
};

#endif // LEVEL_H_INCLUDED
