#include "inGame.h"

void inGame::init()
{
    std::cout << "Entering inGame scene" << "\n";
    entity* b1 = new  block(BLOCKS::GRASS , p2d<float>(0,0));
    scene::vars->entity_manager->set(100, b1);
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
    SDL_RenderClear(scene::vars->renderer);
    scene::vars->view->render(100);
    SDL_RenderPresent(scene::vars->renderer);
}

scene_id inGame::quit()
{
    std::cout << "Exiting inGame scene" << "\n";

    return scene_id::end;
}