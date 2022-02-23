#include "chunkManager.h"


bool chunkManager::force_load(p2d<int> id)
{
    return false;
}

void chunkManager::derived_remove(p2d<int> id)
{
    delete map[id];
    map.erase(id);
}

