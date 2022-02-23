#pragma once


#include <string.h>
#include <iostream>
#include <SDL2/SDL.h>

#include "textureManager.h"
#include "hitboxManager.h"
#include "entityManager.h"
#include "chunkManager.h"
#include "timer.h"
#include "camera.h"


enum scene_id
{
    menu = 0 , game , end
};




class textureManager;
class hitboxManager ;
class entityManager ;
class chunkManager  ;
class timer         ;
class camera        ;

struct scene_objects
{
    scene_objects();
    ~scene_objects();
    void initialize_variables(SDL_Renderer* r , SDL_Window* w);


    textureManager*        texture_manager;
    hitboxManager *        hitbox_manager;
    entityManager *        entity_manager;
    chunkManager  *        chunk_manager;
    timer         *        clock;
    camera        *        view;
    SDL_Renderer  *        renderer;
    SDL_Window    *        window;
};




/*
scene class implements a generic game loop.
It contains all objects necessary  to run the game.

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

        static scene_objects* vars;
        
    protected:

        void show_screen_info();

    scene_id next_scene;
    bool isRunning = true;
    SDL_Event event;
    

    private:
};

