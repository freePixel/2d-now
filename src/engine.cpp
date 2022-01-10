#include "engine.h"


engine::engine() //initialize compontens
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("game" , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED , 800 , 800 , 0);
    renderer = SDL_CreateRenderer(window , -1 , 0);

}


void engine::run() //enter main loop
{
    isRunning = true;
    scene_id next_scene = scene_id::menu;
    while(isRunning)
    {
        switch(next_scene)
        {
            case scene_id::menu:
                current_scene = new mainMenu();
                break;

            case scene_id::game:
                current_scene = new inGame();
                break;

            case scene_id::end:
                isRunning = false;
                break;

            default:
                throw std::runtime_error("Unknown scene");
                isRunning = false;
                
        }
        if(next_scene != scene_id::end){
            next_scene = current_scene->process(renderer, window);
            delete current_scene;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

        
}

