#include "mainMenu.h"



void mainMenu::init()
{

    _camera->set_position(p2d<float>(0,0));
    _camera->set_size(p2d<float>(1280.0f , 720.0f));


    hit_manager = new hitboxManager();
    std::cout << "Entered main Menu" << "\n";
    


    //initialize buttons
    entity *b1 = new button(std::string("Play"), texture_manager , hit_manager ,
    [this](){
        next_scene = scene_id::game;
        isRunning = false;}
    
    );
    b1->set_position(p2d<float>(800.0f, 100.0f));
    b1->set_size(p2d<float>(300.0f , 120.0f));

    entity *b2 = new button(std::string("Credits"), texture_manager , hit_manager ,

    [](){
        std::cout << "CREDITS NOT ADDED YET" << "\n";
        }
    );
    b2->set_position(p2d<float>(800.0f, 250.0f));
    b2->set_size(p2d<float>(300.0f , 120.0f));

    entity *b3 = new button(std::string("Quit"), texture_manager , hit_manager , 
    //(pass lambda function)
    [this](){
        next_scene = scene_id::end;
        isRunning = false;
    }        
    
    );
    b3->set_position(p2d<float>(800.0f, 400.0f));
    b3->set_size(p2d<float>(300.0f , 120.0f));

    buttons = {b1  , b2 , b3};

    animationInfo info1 , info2 , info3;
    info1.duration = 3500;
    info1.trajectory.push_back(b1->get_position());
    info1.trajectory.push_back(b1->get_position() - p2d<float>(600.0f , 0.0f));
    info1.repeat = false;
    info1.type = animationType::cubic;

    info2.duration = 3000;
    info2.trajectory.push_back(b2->get_position());
    info2.trajectory.push_back(b2->get_position() - p2d<float>(600.0f , 0.0f));
    info2.repeat = false;
    info2.type = animationType::cubic;

    info3.duration = 2500;
    info3.trajectory.push_back(b3->get_position());
    info3.trajectory.push_back(b3->get_position() - p2d<float>(600.0f , 0.0f));
    info3.repeat = false;
    info3.type = animationType::cubic;
    animation* anim1 = new animation(b1,clock, info1);
    animation* anim2 = new animation(b2,clock, info2);
    animation* anim3 = new animation(b3,clock, info3);
    
    
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
            p2d<float> position((float)x,(float)y);
            hit_manager->mouse_click(_camera->cameraToWorldCoordinate(position));

        }

    }
}


void mainMenu::updateLogic()
{

}

void mainMenu::updateGraphics()
{

    SDL_RenderClear(renderer);
    
    for(int i=0;i<buttons.size();i++)
    {
        _camera->render(buttons[i]);
    }

    SDL_RenderPresent(renderer);
}

scene_id mainMenu::quit()
{
    std::cout << "exiting main menu scene" << "\n";
    return next_scene;
}
