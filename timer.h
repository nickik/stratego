#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include "SDL/SDL.h"
#include <sstream>

class timer{
public:
        timer();
        void start();
        void stop();
        void pause();
        void unpause();
        int ticks_getter();
        bool is_started();
        bool is_paused();

private:
        int start_ticks;
        int paused_ticks;
        bool paused;
        bool started;
};

#endif // TIMER_H_INCLUDED
