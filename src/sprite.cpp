#include "sprite.h"



sprite::sprite(entity* e , std::vector<int>& _texture_ids , sprite_speed speed , timer* clock)
{
    texture_ids = &_texture_ids;
    this->speed = speed;
    this->clock = clock;
    this->_entity = e;
    if(speed < 0){
        throw std::runtime_error("Invalid sprite speed");
    }

    _entity->set_texture((texture_id)texture_ids->at(0));
    vec_pos_counter = 0;
    size = texture_ids->size();
    std::function<void()> foo = std::bind(&sprite::update , this);
    clock->newTimeEvent(_entity->get_id() , (double)speed , foo);

}

void sprite::update()
{
    if(vec_pos_counter < size - 1 ) vec_pos_counter++;
    else{
        vec_pos_counter = 0;
    }

    _entity->set_texture((texture_id)texture_ids->at(vec_pos_counter));
}

sprite::~sprite()
{
    clock->removeTimeEvent(_entity->get_id());
}