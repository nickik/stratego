#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "feld.h"

class level{
private:
    //LEVEL MAP
    //map<feld>
public:
    level();
    ~level();
    bool move(feld,feld);
    bool validmove(feld,feld);
    bool load_aufstellung( /*string*/ char filename );
    bool init_feld();

};

#endif // LEVEL_H_INCLUDED
