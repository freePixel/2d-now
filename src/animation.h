#pragma once


#include <vector>
#include "entity.h"
#include "timer.h"
#include "point.h"
#include <SDL2/SDL.h>
/*
    Class animation is directly associated with an entity
*/

class animation
{
    public:
        animation(p2d<float> dst_position , entity* e , timer* t ,  double duration);
        ~animation();
        void update(double dt);
    private:

        void calculate_derivate();

        entity* _entity = nullptr;
        timer* _timer = nullptr;
        
        double duration = 0.0;

        bool repeat = false;

        p2d<float> dest_position;

        double progress = 0.0;
        p2d<float> derivate;

};