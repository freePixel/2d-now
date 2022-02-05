#pragma once

#include "SDL2/SDL.h"
#include <utility>
#include "entity.h"
#include "textureManager.h"

/*
camera class is responsible for rendering all entity's inside a scene.
*/

class camera : public entity    
{
    public:
        camera(SDL_Renderer* _renderer , textureManager* _texture_manager , SDL_Window* _window);
        void render(entity* _entity);
        void update_window_size();
        p2d<float> cameraToWorldCoordinate(p2d<float> pos);
        bool contains(SDL_FRect* rect); //check if a given rect intersects camera

    private:



        p2d<float> window_size = p2d<float>(1280 , 720); //default value
        
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        textureManager* texture_manager = nullptr;
        SDL_FRect* worldToCameraCoordinate(const SDL_FRect* rect); //convert world coordinate into camera coordinate


    
        
};