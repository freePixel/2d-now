#pragma once

#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdexcept>


//Future changes:  add TTF_Font manager


enum texture_id
{
    none = 5000 , t1 , t2 , t3
};

class textureManager
{
    public:
        ~textureManager();
        textureManager(SDL_Renderer* renderer);
        void add_texture(int id , const char* path);
        void add_text(int id , const char* text , SDL_Color color);
        void remove_texture(int id);
        SDL_Texture* get_texture(int id);
        
    private:
        std::map<int , SDL_Texture*> textureMap; //id 0 is reserved for 'unknown texture'
        SDL_Renderer* renderer = nullptr;

        bool add_map(int id , SDL_Texture* t); //throws an error if id is aldready being used

        TTF_Font* font = nullptr;

      
};