#pragma once


#include <vector>
#include "entity.h"
#include "timer.h"
#include "point.h"
#include <SDL2/SDL.h>


enum animationType
{

    /*
    linear function where:
    v(t) is constant

    */

    linear = 0 ,

    /*
    cubic function where:
    v(0)=0
    v(duration)=0
    
    implementation:
        u(t) = (2/d^3)(p1-p2)t^3 + (3/d^2)(p2-p1)t^2 + p1
        
        d->duration
        t->elapsed time
        p2->destination position
        p1->source position

    */

    cubic = 1
};

struct animationInfo
{
    std::vector<p2d<float>> trajectory;
    std::vector<double> time_vec;
    bool repeat = false;
    bool absolute = true;
    double duration = 0.0;
    int vidx = 0; //current vector index
    animationType type = animationType::linear;

    void generate_time_vec()
    {
        //find path length
        float len = 0.0f;
        for(int i=0;i<trajectory.size() - 1;i++)
        {
            len += p2d<float>::distance(trajectory[i] , trajectory[i+1]);
        }
        
        for(int i=0;i<trajectory.size() - 1;i++)
        {
            time_vec.push_back((p2d<float>::distance(trajectory[i],trajectory[i+1]) * duration) / len);
        }
    }

    

};


/*
    Class animation should be directly associated with an entity
*/

class animation
{
    public:
        animation(entity* e , timer* t , animationInfo anim_info);
        ~animation();
        void update(double dt);
    private:


        entity* _entity = nullptr;
        timer* _timer = nullptr;

        animationInfo info;

        
        p2d<float> calculate_type_linear(double dt);
        p2d<float> calculate_type_cubic(double dt);
        

};