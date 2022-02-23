#include "entity.h"

entity::~entity()
{
    delete dimension;
    delete texSet;
}

void entity::move(p2d<float> point)
{
    dimension->x += point.x;
    dimension->y += point.y;
}

void entity::set_position(p2d<float> point)
{
    dimension->x = point.x;
    dimension->y = point.y;
}

void entity::set_size(p2d<float>  point)
{
    dimension->w = point.x;
    dimension->h = point.y;
}

void entity::scale(p2d<float> point)
{
    dimension->w *= point.x;
    dimension->h *= point.y;
}

p2d<float> entity::get_position()
{
    return p2d<float>(dimension->x , dimension->y);
}

p2d<float> entity::get_size()
{
    return p2d<float>(dimension->w , dimension->h);
}

const SDL_FRect* entity::get_dimension()
{
    return dimension;
}

entity::entity()
{
    dimension = new SDL_FRect{0,0,0,0};
    texSet = new textureSet();
    id_c += 50;
    this->id = id_c;
}

int entity::id_c = 3000;

bool entity::is_world_coordinate()
{
    return world_coordinate;
}

int entity::get_id()
{
    return this->id;
}

void entity::set_id(int _id)
{
    on_id_change(id, _id);
    this->id = _id;
}