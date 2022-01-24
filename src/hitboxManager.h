#pragma once

#include "entity.h"
#include "map"
#include <functional>

struct hitbox
{
    std::function<void()> onclick;
    entity* _entity;

    hitbox(entity* _entity , std::function<void()> _onclick)
    {
        this->_entity = _entity;
        onclick = _onclick;
    }

    bool check_collision(p2d<float> point)
    {
        const SDL_FRect* r = _entity->get_dimension();
        return (
            point.x <= r->x + r->w &&
            point.x >= r->x        &&
            point.y <= r->y + r->h &&
            point.y >= r->y);
        
    }

};


class hitboxManager
{
    public:
    void new_hitbox(int id , entity* _entity , std::function<void()> onclick_foo);
    void remove_hitbox(int id);

    void mouse_click(p2d<float> position);

    /*
    Add in future:
    ->efficient mouse movement hitbox detection

    */

    private:
    std::map<int , hitbox*> hitbox_map;
};
