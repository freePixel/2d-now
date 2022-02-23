#include "button.h"


void button::on_id_change(int lastid , int newid)
{
    texSet->set.at(1).id = newid;
    scene::vars->texture_manager->transfer(lastid , newid);
    scene::vars->hitbox_manager->transfer(lastid , newid);
}

button::button(std::string text , std::function<void()> onclick)
{
    entity::world_coordinate = false;
    this->text = text;

    scene::vars->texture_manager->add_text(entity::id , text.c_str());

    textureInfo info1(this->get_size());
    textureInfo info2(this->get_size());
    info1.id = entity::id;
    info1.size_unit = UNIT::PX;
    info1.size = scene::vars->texture_manager->get_text_size(text);
    info1.position_unit = UNIT::CENTERED;

    info2.id = (int)TEXTURES::BUTTON;


    texSet->add_texture(info2      , 0);
    texSet->add_texture(info1,       1);

    scene::vars->hitbox_manager->new_hitbox(entity::id ,onclick);
}

button::~button()
{
    //deassociate from hitbox_manager
    scene::vars->hitbox_manager->remove(entity::id);
    scene::vars->texture_manager->remove(entity::id);
}