#include "hitboxManager.h"


void hitboxManager::mouse_click(p2d<float> position)
{
    for(auto iter : manager::map)
    {
        if(!entity::exists(iter.second->_entity)) //check if entity still exists
        {
            remove(iter.first);
        }
        else if(iter.second->check_collision(position))
        {
            iter.second->onclick();

            break;      //multiple hitbox collision isn't expected
        }
    }
}

void hitboxManager::new_hitbox(int id , entity* _entity , std::function<void()> onclick_foo)
{
    map[id] = new hitbox(_entity , onclick_foo);
}

void hitboxManager::remove(int id)
{
    delete map[id];
    map.erase(id);
}