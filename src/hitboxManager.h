#pragma once

#include "entity.h"
#include "map"
#include <functional>
#include "manager.h"

struct hitbox
{
    std::function<void()> onclick;
    entity* _entity;

    hitbox(entity* _entity , std::function<void()> _onclick) //assign an entity to hitbox object
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


class hitboxManager : public manager<hitbox*> 
{
    public:
    hitboxManager()
    {
        forceLoad = false;
    }
    void new_hitbox(int id , entity* _entity , std::function<void()> onclick_foo);
    void remove(int id) override;
    void mouse_click(p2d<float> position);
    bool force_load(int id) override {return false;};

    /*
    Add in future:
    ->efficient mouse movement hitbox detection

    */
};
