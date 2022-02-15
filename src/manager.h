#pragma once

#include <map>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <typeinfo>


template <class T>
class manager
{
    public:
        void set(int id , T obj)
        {
            if(map.count(id) != 0) throw std::runtime_error("Id aldready exists!");
            else{
            manager::map[id] = obj;
            }
        }

        T   get(int id)
        {
            if(map.count(id) == 0)
            {
                throw std::runtime_error("Id not found!");
                return nullptr;
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
        virtual void remove(int id) = 0;
        std::map<int , T> map;
};



