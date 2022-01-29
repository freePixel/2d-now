#pragma once

#include "SDL2/SDL.h"
#include "mainMenu.h"
#include "inGame.h"
#include <stdexcept>

/*
engine class is able to change between scenes.
It's the most 'abstract' class in the program.
*/


class engine
{
    public:
        engine(); //initialize components
        void run(); //enter main loop
    private:

    //variables
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    scene* current_scene = nullptr;
    bool isRunning;
    

    void init();


};
