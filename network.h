#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED
//#include "SDL/SDL.h"
#include "SDL/SDL_net.h"

class network{
public:
        network();
        TCPsocket open_connection( IPaddress* );
        void close_connection( TCPsocket );
        TCPsocket accept_connection( TCPsocket );
        IPaddress* get_connection( TCPsocket );
        bool send_data( TCPsocket, void*, int );
        bool recv_data( TCPsocket, void*, int );
private:
        bool is_connected;
        bool is_client;
        bool is_server;
        IPaddress* ip;
        TCPsocket client;
        TCPsocket server;
};


#endif // NETWORK_H_INCLUDED
