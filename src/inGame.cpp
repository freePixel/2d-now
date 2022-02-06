#include "inGame.h"

void inGame::init()
{
    std::cout << "Entering inGame scene" << "\n";
}

void inGame::handleEvents()
{
    while(SDL_PollEvent(&event) != 0)
    {
        switch(event.type)
        {
            case SDL_QUIT:
            isRunning = false;
            next_scene = scene_id::end;
            break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

            }

        }

    }
}

void inGame::updateLogic()
{
    
}

void inGame::updateGraphics()
{
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

scene_id inGame::quit()
{
    std::cout << "Exiting inGame scene" << "\n";
    return scene_id::end;
}