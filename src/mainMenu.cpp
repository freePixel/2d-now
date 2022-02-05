#include "mainMenu.h"

void mainMenu::test_foo()
{
    std::cout << "BUTTON PRESSED! IT WORKS!" << "\n";
}


void mainMenu::init()
{
    hit_manager = new hitboxManager();
    texture_manager->add_texture(TEXTURE::BUTTON , "../resources/textures/button.png");
    std::cout << "Entered main Menu" << "\n";
    std::function<void()> foo = std::bind(&mainMenu::test_foo , this);
    _button = new button(std::string("hello world"), texture_manager , hit_manager , foo);
    _button->set_position(p2d<float>(0.0f, 200.0f));
    _button->set_size(p2d<float>(300.0f , 100.0f));

    
    
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
                case SDL_KeyCode::SDLK_w:

                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            int x , y;
            SDL_GetMouseState(&x , &y);
            hit_manager->mouse_click(p2d<float>((float)x , (float)y));

        }

    }
}


void mainMenu::updateLogic()
{

}

void mainMenu::updateGraphics()
{

    SDL_RenderClear(renderer);
    
    _camera->render(_button);

    SDL_RenderPresent(renderer);
}

scene_id mainMenu::quit()
{
    std::cout << "exiting main menu scene" << "\n";
    return next_scene;
}
