#pragma once

#include <map>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <typeinfo>


template <class T>
class manager
{
    public:

        manager()
        {
            
        }

        void set(int id , T obj)
        {
            if(contains(id)) throw std::runtime_error("Id aldready exists!");
            else{
            manager::map[id] = obj;
            }
        }

        T   get(int id)
        {
            if(map.count(id) == 0)
            {
                if(forceLoad == true)
                {
                    force_load(id);
                    return NULL;
                }
                else{
                    throw std::runtime_error("Id not found!");
                    return NULL;
                }
            }
            else{
                return map[id];
            }
        }

        bool contains(int id)
        {
            return map.count(id) != 0;
        }
        

    protected:

        virtual void force_load(int id) = 0; //when forceLoad variable is true, the derived class will try to load object by id (ex: textureManager)
        bool forceLoad;
        virtual void remove(int id) = 0;
        std::map<int , T> map;
};



