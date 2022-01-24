#include "hitboxManager.h"

void hitboxManager::mouse_click(p2d<float> position)
{
    for(auto iter : hitbox_map)
    {
        if(iter.second->check_collision(position))
        {
            iter.second->onclick();

            break;      //multiple hitbox collision isn't expected
        }
    }
}

void hitboxManager::new_hitbox(int id , entity* _entity , std::function<void()> onclick_foo)
{
    hitbox_map[id] = new hitbox(_entity , onclick_foo);
}

void hitboxManager::remove_hitbox(int id)
{
    delete hitbox_map[id];
    hitbox_map.erase(id);
}