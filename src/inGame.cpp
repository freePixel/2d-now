#include "inGame.h"

void inGame::init()
{
    std::cout << "Entering inGame scene" << "\n";
    b1 = new  block(BLOCKS::GRASS , p2d<float>(0,0) , texture_manager);
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
    _camera->render(b1);
    SDL_RenderPresent(renderer);
}

scene_id inGame::quit()
{
    std::cout << "Exiting inGame scene" << "\n";
    delete b1;
    return scene_id::end;
}