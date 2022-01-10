#include "entity.h"

entity::~entity()
{
    delete dimension;
}

void entity::move(p2d<float> point)
{
    dimension->w += point.x;
    dimension->h += point.y;
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
    id = id_counter;
    id_counter++;
}

texture_id entity::get_texture_id()
{
    return current_texture;
}

int entity::id_counter = 0;