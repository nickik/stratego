#include "network.h"

network::network()
{
    //nothing to be done (yet)
}

TCPsocket network::open_connection( IPaddress* addr )
{
    client = SDLNet_TCP_Open( &addr );
    if( client != NULL )
    {
        return client;
    }
}

void network::close_connection( TCPsocket socket )
{
    SDLNet_TCP_Close( socket );
}

TCPsocket network::accept_connection( TCPsocket socket, IPaddress* addr )
{
    socket = NULL;
    socket = open_connection( &addr );
    if( socket != NULL )
    {
        server = SDLNet_TCP_Accept( socket );
        while( server == NULL )
        {
            SDL_Delay( 1000 );
            server = SDLNet_TCP_Accept( socket );
        }
        return server;
    }
}

IPaddress* network::get_connection( TCPsocket socket )
{
    if( socket != NULL )
    {
        return SDLNet_TCP_GetPeerAdress( socket );
    }
}

bool network::send_data( TCPsocket socket, void* data, int length )
{
    if( socket != NULL )
    {
        SDLNet_TCP_Send( socket, data, length );
        return true;
    }
    else
    {
        return false;
    }
}

bool network::recv_data( TCPsocket socket, void* data, int maxlength )
{
    if( socket != NULL )
    {
        SDLNet_TCP_Recv( socket, data, maxlength );
        return true;
    }
    else
    {
        return false;
    }
}
