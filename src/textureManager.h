#pragma once

#include "manager.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

enum texture_id
{
    none = 0 , t1 , t2 , t3
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