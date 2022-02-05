#include "animation.h"


animation::animation(p2d<float> dst_position , entity* e , timer* t ,  double duration)
{
    this->_entity = e;
    this->_timer = t;
    this->repeat = repeat;
    this->dest_position = dst_position;
    std::function<void(double)> foo = std::bind(&animation::update , this , std::placeholders::_1); //placeholder is used to avoid passing double parameter now (it is known only when function is called)
    _timer->new_dt_function(_entity->get_id() + ID_OFFSET::ANIMATION, foo );

    this->duration = duration;
}


animation::~animation()
{
    _timer->remove_dt_function(_entity->get_id() + ID_OFFSET::ANIMATION);
}

void animation::update(double dt)
{

    
    if(_timer->get_dt_elapsed_time(_entity->get_id() + ID_OFFSET::ANIMATION) > duration)
    {
        this->~animation();
    }
    _entity->move(p2d<float>(2.0f,0.0f));
    
    
}

void animation::calculate_derivate()
{
    p2d<float> origin = _entity->get_position();
    p2d<float> dest   = dest_position;

    derivate = p2d<float>((dest.x - origin.x) / duration , (dest.y - origin.y) / duration);
}