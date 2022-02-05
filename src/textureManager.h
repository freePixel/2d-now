#pragma once

#include "manager.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <SDL2/SDL_image.h>

#include <map>

enum TEXTURE
{
    NONE = 0,
    T1,
    T2,
    T3,
    BUTTON
};

struct textureSet
{
    public:
        textureSet(int t_id)
        {
            set.push_back(t_id);
        }

        textureSet()
        {

        }
        

        std::vector<int>& get_set()
        {
            return set;
        }
        void add_texture(int t_id , int priority)   //priority==0 means that the texture with t_id will be rendered first , priority is the seconds etc...
        {
            if(priority >= set.size())
            {
                set.push_back(t_id);
            }
            else{
                set.insert(set.begin() + priority , t_id);
            }
        }
        void remove_from_set_by_priority(int priority)
        {
            set.erase(set.begin() + priority);
        }
    private:
        std::vector<int> set;
};


class textureManager : public manager<SDL_Texture*>
{
    public:
        ~textureManager();
        textureManager(SDL_Renderer* renderer);

        void add_texture(int id , const char* path);
       
        void add_text(int id , const char* text);

        void remove(int id) override;


    private:
        

        SDL_Texture* load_texture(const char* path);
        SDL_Texture* load_text(const char* text);

        SDL_Renderer* renderer = nullptr;

        TTF_Font* font = nullptr;

        
};