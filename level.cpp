#include "level.h"


bool level::move(feld source,feld destination)
{
    return validmove(source, destination);
}

bool level::validmove(feld source_feld,feld ziel_feld)
{
    if(source_feld.valid() and ziel_feld.valid())
    {
        if(source_feld.spielstein_getter().team_getter() != ziel_feld.spielstein_getter().team_getter())
        {
            return true;
        }
    }
    return false;
}

bool level::init_feld()
{
    for(int i=0;i!=10;i++){
        for(int n=0;n!=10;n++){
            spielfeld[i][n] = feld(land, i, n);
        }
    }
    return true;
}

level::level()
{
    //init_feld();
    load_aufstellung("beispiel.xml");
}

level::~level()
{
}

bool level::load_aufstellung( std::string filename )
{
    parse_aufstellung(filename);
    return false;
}

void level::parse_feld(xmlDocPtr doc, xmlNodePtr cur) {

    std::string team;
    int id;
    char * teams;
    std::string sf;

	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"id"))) {
            id = atoi((char *) xmlNodeListGetString(doc, cur->xmlChildrenNode, 1));
 	    }
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"team"))) {
		    //team =   team.insert(0, (char*)xmlNodeListGetString(doc, cur->xmlChildrenNode, 1));
            teams = (char*)xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            team = team.insert(0, teams);
 	    }
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"spielfigur"))) {
		    sf = sf.insert(0, (char*)xmlNodeListGetString(doc, cur->xmlChildrenNode, 1));
 	    }
 	    feldadd(team, id, sf);

	cur = cur->next;
	}
    return;
}

void level::parse_aufstellung(std::string docname) {

	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile( docname.c_str());

	if (doc == NULL ) {
		//fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}

	cur = xmlDocGetRootElement(doc);

	if (cur == NULL) {
		//fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "stratego")) {
		//fprintf(stderr,"document of the wrong type, root node != stratego");
		xmlFreeDoc(doc);
		return;
	}
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"feld"))){
			parse_feld(doc, cur);
		}
	cur = cur->next;
	}

    draw_spielfeld();

	xmlFreeDoc(doc);
	return;
}

bool level::feldadd(std::string team, int id, std::string spielfigur)
{
    teamfarbe t;

    if(team == "rot" or team == "blau")
    {
        if(team == "rot"){
            t = red;
        }
        if(team == "blau"){
            t = blue;
        }
    }
    else
    {
        t = empty;
    }
    figur f;
    if( t != empty )
    {
        f = string_to_figur(spielfigur);
    }

    int x;
    int y;

    if(id <= 100 or id >= 0)
    {
        y = id / 10;
        if( id % 10 > 0)
        {
             y++;
        }
        if( id % 10 == 0 )
        {
            x = 10;
        }
        else
        {
            x = id % 10;
        }
    }

    boden b = land;
    if(x >= 5 and x <= 6)
    {
        if(y >= 2 and y <= 3)
            b = wasser;

        if(y >= 7 and y <= 8)
            b = wasser;
    }

    if(b == land)
    {
        if( t == empty )
        {
            spielfeld[x][y]  = feld(b, x, y);
        }
        else
        {
            spielfeld[x][y] = feld(b, x, y, token(f,t));
        }
    }else{
        spielfeld[x][y]  = feld(b, x, y);
    }

    return true;
}


figur level::string_to_figur(std::string spielfigur)
{
    if (spielfigur == "1")
        return Feldmarschall;
    else if (spielfigur == "2")
        return General;
    else if (spielfigur == "3")
        return Oberst;
    else if (spielfigur == "4")
        return Major;
    else if (spielfigur == "5")
        return Hauptmann;
    else if (spielfigur == "6")
        return Leutnant;
    else if (spielfigur == "7")
        return Unteroffizier;
    else if (spielfigur == "8")
        return Mineur;
    else if (spielfigur == "9")
        return Aufklaehrer;
    else if (spielfigur == "B")
        return Bombe;
    else if (spielfigur == "S")
        return Spion;
    else if (spielfigur == "F")
        return Fahne;
    else
        return Leer;
}

bool level::draw_spielfeld()
{
    drawengine de;

    for(int i=0;i!=10;i++){
        for(int n=0;n!=10;n++){
            if(spielfeld[i][n].stein_getter() == true)
            {
                feld f = spielfeld[i][n];
                int x = i;
                int y = n;
                //de.draw_token(x, y, f, f.spielstein_getter().team_getter());
            }
        }
    }
    return true;
}
