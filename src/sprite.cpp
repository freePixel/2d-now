#include "scene.h"
#include "sprite.h"



sprite::sprite(int _entity_id , std::vector<textureInfo>& _texture_ids , sprite_speed _speed)
    : texture_ids(_texture_ids)
{
    entity_id = _entity_id;
    speed = _speed;


    if(speed < 0){
        throw std::runtime_error("Invalid sprite speed");
    }

    scene::vars->entity_manager->get(entity_id)->texSet->add_texture(texture_ids.at(0) , 0);
    vec_pos_counter = 0;
    size = texture_ids.size();
    std::function<void()> foo = std::bind(&sprite::update , this);
    scene::vars->clock->newTimeEvent(entity_id + ID_OFFSET::SPRITE , (double)speed , foo);

}

void sprite::update()
{
    if(vec_pos_counter < size - 1 ) vec_pos_counter++;
    else{
        vec_pos_counter = 0;
    }

    scene::vars->entity_manager->get(entity_id)->texSet->remove_from_set_by_priority(0);
    scene::vars->entity_manager->get(entity_id)->texSet->add_texture(texture_ids.at(vec_pos_counter), 0);
}

sprite::~sprite()
{
    scene::vars->clock->removeTimeEvent(entity_id + ID_OFFSET::SPRITE);
}