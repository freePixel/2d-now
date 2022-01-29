#include "button.h"

button::button(std::string text , textureManager* _tManager , hitboxManager* hitbox_manager , std::function<void()> onclick)
{
    entity::world_coordinate = false;
    this->text = text;
    this->t_manager = _tManager;
    this->hitbox_manager = hitbox_manager;

    t_manager->add_text(entity::id , text.c_str());
    
    current_texture = entity::id;
    
    hitbox_manager->new_hitbox(entity::id , this , onclick);
}