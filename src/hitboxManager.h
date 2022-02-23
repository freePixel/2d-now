#pragma once

#include "entity.h"
#include "map"
#include <functional>
#include "textureManager.h"


struct hitbox
{
    std::function<void()> onclick;

    hitbox(std::function<void()> _onclick); //assign an entity to hitbox object
    bool check_collision(int e_id , p2d<float> point);
    

};


class hitboxManager : public manager<int , hitbox*> 
{
    public:
    hitboxManager()
    {
        forceLoad = false;
    }
    void new_hitbox(int e_id , std::function<void()> onclick_foo);
    void derived_remove(int id) override;
    void mouse_click(p2d<float> position);
    bool force_load(int id) override {return false;};
    void on_set(int id) override{}

    /*
    Add in future:
    ->efficient mouse movement hitbox detection

    */
};
