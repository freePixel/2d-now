#include "animation.h"


animation::animation(entity* e , timer* t , animationInfo anim_info)
{
    //assign variables
    this->_entity = e;
    this->_timer = t;
    this->info = anim_info;
    
    //asssign update function
    std::function<void(double)> foo = std::bind(&animation::update , this , std::placeholders::_1); //placeholder is used to avoid passing double parameter now (it is known only when function is called)
    _timer->new_dt_function(_entity->get_id() + ID_OFFSET::ANIMATION, foo );

    


}


animation::~animation()
{
    _timer->remove_dt_function(_entity->get_id() + ID_OFFSET::ANIMATION);

}

void animation::update(double dt)
{
    p2d<float> next_position;
    double t = _timer->get_dt_elapsed_time(_entity->get_id() + ID_OFFSET::ANIMATION);
    int idx = info.vidx;
    if(t > info.time_vec[idx])
    {
        _timer->reset_dt_elaped_time(_entity->get_id() + ID_OFFSET::ANIMATION);
        t = info.time_vec[idx];
        info.vidx++;

        if(info.vidx >= info.trajectory.size() && info.repeat == false)
        {
            this->~animation();
        }
        else if(info.vidx >= info.trajectory.size())
        {
            info.vidx = 0;
        }
    }
    
    switch(info.type)
    {
        case animationType::linear:
            next_position = calculate_type_linear(t);
            break;
        case animationType::cubic:
            next_position = calculate_type_cubic(t);
            break;
    }
    _entity->set_position(next_position);
}

p2d<float> animation::calculate_type_linear(double t)
{
    float x , y;
    double d = info.duration;
    float p1x = info.trajectory[info.vidx].x;
    float p1y = info.trajectory[info.vidx].y;
    float p2x = info.trajectory[info.vidx + 1].x;
    float p2y = info.trajectory[info.vidx + 1].y;

    x = t*(p2x-p1x)/d + p1x;
    y = t*(p2y-p1y)/d + p1y;
    return p2d<float>(x,y);
}

p2d<float> animation::calculate_type_cubic(double t)
{
    float x , y;
    double d = info.duration;
    float p1x = info.trajectory[info.vidx].x;
    float p1y = info.trajectory[info.vidx].y;
    float p2x = info.trajectory[info.vidx + 1].x;
    float p2y = info.trajectory[info.vidx + 1].y;


    x = 2*(p1x-p2x)*t*t*t/(d*d*d)+3*(p2x-p1x)*t*t/(d*d)+p1x;
    y = 2*(p1y-p2y)*t*t*t/(d*d*d)+3*(p2y-p1y)*t*t/(d*d)+p1y;

    return p2d<float>(x,y);
}