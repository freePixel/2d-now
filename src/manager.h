#pragma once

#include <map>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <typeinfo>
#include <iostream>



template <typename U , class T>
class manager
{
    public:

        manager()
        {
            
        }

        void set(U id , T obj)
        {
            if(contains(id))
             std::cout << id <<  " id aldready exists!" << "\n";
            else{
                manager::map[id] = obj;
                on_set(id);
            }
        }

        T   get(U id)
        {
            if(contains(id) == false)
            {
                if(force_load(id))
                {
                    return map[id];
                }
                else{
                    std::cout << id <<  " id not found!" << "\n";
                    
                    return NULL;
                }
            }
            else{
                return map[id];
            }
        }

        void transfer(U id1 , U id2)
        {
            T obj = get(id1);
            set(id2 , obj);
            map.erase(id1);
        }

        bool contains(U id)
        {
            return map.count(id) != 0;
        }
        
        void remove(U id)
        {
            if(contains(id))
            {
                derived_remove(id);
            }
            else{
                std::cout << "Remove failed because the id " << id << " is unknown" << "\n";
            }
        }

    protected:
        bool forceLoad;
        virtual bool force_load(U id) = 0; //the derived class will try to load object by id (ex: textureManager)
        virtual void derived_remove(U id) = 0;
        virtual void on_set(U id) = 0;
        std::map<U , T> map;
};



