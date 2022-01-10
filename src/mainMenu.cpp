#include "mainMenu.h"


void mainMenu::init()
{
    std::cout << "Entered main Menu" << "\n";

    texture_manager->add_texture(texture_id::t1 , "../resources/textures/t1.png");
    texture_manager->add_texture(texture_id::t2 , "../resources/textures/t2.png");
    texture_manager->add_texture(texture_id::t3 , "../resources/textures/t3.png");
    
    player = new sprite(sprite_texture::player::sp1 , sprite_speed::normal , clock);

    player->set_position(p2d<float>(20.0f,20.0f));
    player->set_size(p2d<float>(50.0f,50.0f));
    
}

void mainMenu::handleEvents()
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


void mainMenu::updateLogic()
{
    
}

void mainMenu::updateGraphics()
{
    SDL_RenderClear(renderer);
    
    _camera->render(player);

    SDL_RenderPresent(renderer);
}

scene_id mainMenu::quit()
{
    std::cout << "exiting main menu scene" << "\n";
    return next_scene;
}
