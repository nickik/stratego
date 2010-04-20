#include "timer.h"

timer::timer()
{
    start_ticks = 0;
    paused_ticks = 0;
    paused = false;
    started = false;
}

void timer::start()
{
    started = true;
    paused = false;

    start_ticks = SDL_GetTicks();
}

void timer::stop()
{
    started = false;
    paused = false;
}

void timer::pause()
{
    if ( ( started == true && ( paused == false ) ) )
    {
        paused = true;
        paused_ticks = SDL_GetTicks() - start_ticks;
    }
}

void timer::unpause()
{
    if( paused == true )
    {
        paused == false;
        start_ticks = SDL_GetTicks() - paused_ticks;
        paused_ticks = 0;
    }
}

int timer::ticks_getter()
{
    if ( started == true )
    {

        if( paused == true )
        {
            return paused_ticks;
        }
        else
        {
            return SDL_GetTicks() - start_ticks;
        }
    }
    return 0;
}

bool timer::is_started()
{
    return started;
}

bool timer::is_paused()
{
    return paused;
}
