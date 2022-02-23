#include "entityManager.h"

bool entityManager::force_load(int id)
{
    return false;
}

void entityManager::derived_remove(int id)
{
    delete map[id];
    map.erase(id);
}

void entityManager::on_set(int id)
{
    get(id)->set_id(id);
}

