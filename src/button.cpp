#include "button.h"

button::button(std::string text , textureManager* _tManager , hitboxManager* hitbox_manager , std::function<void()> onclick)
{
    entity::world_coordinate = false;
    this->text = text;
    this->t_manager = _tManager;
    this->hitbox_manager = hitbox_manager;

    t_manager->add_text(entity::id , text.c_str());
    
    

    texSet->add_texture(TEXTURE::BUTTON, 0);
    texSet->add_texture(entity::id , 1);
    hitbox_manager->new_hitbox(entity::id , this , onclick);
}

button::~button()
{
    //deassociate from hitbox_manager
    hitbox_manager->remove(entity::id);
    t_manager->remove(entity::id);
}