#include "button.h"

button::button(std::string text , textureManager* _tManager , hitboxManager* hitbox_manager , std::function<void()> onclick)
{
    entity::world_coordinate = false;
    this->text = text;
    this->t_manager = _tManager;
    this->hitbox_manager = hitbox_manager;

    t_manager->add_text(entity::id , text.c_str());
    
    textureInfo info1(this->get_size());
    textureInfo info2(this->get_size());
    info1.id = entity::id;
    info1.size_unit = UNIT::PX;
    info1.size = t_manager->get_text_size(text);
    info1.position_unit = UNIT::CENTERED;

    info2.id = TEXTURES::BUTTON;


    texSet->add_texture(info1,       1);
    texSet->add_texture(info2      , 0);
    hitbox_manager->new_hitbox(entity::id , this , onclick);
}

button::~button()
{
    //deassociate from hitbox_manager
    hitbox_manager->remove(entity::id);
    t_manager->remove(entity::id);
}