#include "sprite.h"



sprite::sprite(std::vector<int>& _texture_ids , sprite_speed speed , timer* clock)
{
    texture_ids = &_texture_ids;
    this->speed = speed;
    this->clock = clock;
    if(speed < 0){
        throw std::runtime_error("Invalid sprite speed");
    }

    
    vec_pos_counter = 0;
    size = texture_ids->size();
    std::function<void()> foo = std::bind(&sprite::update , this);
    clock->newTimeEvent(entity::id , (double)speed , foo);

}

void sprite::update()
{
    if(vec_pos_counter >= size) vec_pos_counter = 0;
    else{
        vec_pos_counter++;
    }

    current_texture = (texture_id)texture_ids->at(vec_pos_counter);
}