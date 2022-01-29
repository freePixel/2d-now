#pragma once

#include "timer.h"
#include <iostream>
#include "SDL2/SDL.h"
#include "camera.h"
#include "textureManager.h"


enum scene_id
{
    menu = 0 , game , end
};


/*
scene class implements a generic game loop.
It contains all objects necessary (or unecessary) to run the game.

()

*/


class scene
{
    public:
    ~scene();
         scene_id process(SDL_Renderer* _renderer, SDL_Window* _window);
         void update_logic_function();
         virtual void init() = 0;
         virtual void handleEvents() = 0;
         virtual void updateLogic() = 0;
         virtual void updateGraphics() = 0;
         virtual scene_id quit() = 0;

        
    protected:



    scene_id next_scene;
    timer* clock = nullptr;
    bool isRunning = true;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Event event;

    camera* _camera = nullptr;


    //MANAGERS VARIABLES
    textureManager* texture_manager = nullptr;

    

    private:
    



    

};

