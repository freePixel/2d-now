#pragma once

#include "manager.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <SDL2/SDL_image.h>

#include <map>



enum TEXTURES
{
    NONE , BACK1 , BACK2 , NONE , BUTTON
};

struct CVTMAP       //Conversion map
{
    static std::map<TEXTURES , std::string> TEXTURE;
};

std::map<TEXTURES , std::string> CVTMAP::TEXTURE = {
    {NONE , "../resources/textures/undefined.png"}
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
        void add_texture(TEXTURES texture); //add texture by TEXTURES enum id
        void add_text(int  id , const char* text);

        void remove(int id) override;

        void force_load(int id) override;

    private:
        

        SDL_Texture* load_texture(const char* path);
        SDL_Texture* load_text(const char* text);

        SDL_Renderer* renderer = nullptr;

        TTF_Font* font = nullptr;

        
};