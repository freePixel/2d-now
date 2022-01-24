#pragma once


#include "entity.h"
#include "timer.h"
#include "vector"


enum class animation_type
{
    linear ,            // y = ax
    negative_quadratic  // y = -(x-k)^2
};

struct animation_info
{
    /*
    true -> repeat after animation ends
    false -> after animation ends, it is destroyed
    */
    bool repeat;

    std::vector<SDL_FRect> dest_rect; //store all positions
    animation_type type; //if repeat is 'true' type function
    double duration; //duration represents the time taken to execute all animation
    
    void update(double dt)
    {
        
    }

    private:

    std::vector<SDL_FRect> dest_rect_dt;
};

class animation
{
    public:
        animation(entity* ent , timer* _timer);

        void set_animation(animation_type type , double duration);
        
        
    private:
        entity* _entity = nullptr;
        timer* clock = nullptr;
        void update();
    
};