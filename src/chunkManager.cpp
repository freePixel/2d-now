#include "chunkManager.h"
#include "scene.h"
#include <fstream>


bool chunkManager::force_load(p2d<int> id)
{
    set(id , new chunk(id));
    return false;
}

void chunkManager::derived_remove(p2d<int> id)
{
    delete map[id];
    map.erase(id);
}

void chunkManager::loadFromFile(const char* name)
{
    std::ifstream file(name);

    if(file.is_open())
    {
        std::string line;
        while(getline(file , line))
        {
            std::vector<std::string>* data = split(line);
            
            int x    = std::stoi(data->at(0).c_str());
            int y    = std::stoi(data->at(1).c_str());
            int type = std::stoi(data->at(2).c_str());
            int subtype = std::stoi(data->at(3).c_str());

            p2d<int> target = chunk::find_chunk(p2d<float>((float)x , (float)y));

            entity* e = create(x ,  y , type , subtype);
            int id = e->get_id();
            scene::vars->entity_manager->set(id , e);
            chunk* tmp = get(target);
            tmp->get_objects().push_back(id);


        }
    }

}

entity* chunkManager::create(int x , int y , int type , int subtype)
{
    switch(type)
    {
        case 1:
        return new block((BLOCKS)subtype , p2d<float>((float)x,(float)y));
        break;
    }

    return nullptr;
}


std::vector<std::string>* chunkManager::split(std::string& input)
{
    std::vector<std::string>* vec = new std::vector<std::string>();
    int idx = 0;
    for(int i=0;i<input.size();i++)
    {
        if(input[i] != ' ' && input[i+1] == ' ')
        {
            vec->push_back(input.substr(idx , i - idx));
        }
        if(input[i] == ' ' && input[i+1] != ' ') idx = i+1;
    }
    return vec;
}