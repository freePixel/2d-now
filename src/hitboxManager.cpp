#include "scene.h"
#include "hitboxManager.h"


hitbox::hitbox(std::function<void()> _onclick) //assign an entity to hitbox object
{
        onclick = _onclick;
}

bool hitbox::check_collision(int e_id , p2d<float> point)
    {
        const SDL_FRect* r = scene::vars->entity_manager->get(e_id)->get_dimension();
        return (
            point.x <= r->x + r->w &&
            point.x >= r->x        &&
            point.y <= r->y + r->h &&
            point.y >= r->y);
        
    }



void hitboxManager::mouse_click(p2d<float> position)
{
    for(auto iter : manager::map)
    {
        if(iter.second->check_collision(iter.first , position))
        {
            iter.second->onclick();

            break;      //multiple hitbox collision isn't expected
        }
    }
}

void hitboxManager::new_hitbox(int e_id , std::function<void()> onclick_foo)
{
    map[e_id] = new hitbox(onclick_foo);
}

void hitboxManager::derived_remove(int id)
{
    delete map[id];
    map.erase(id);
}