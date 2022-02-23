#include "mainMenu.h"



void mainMenu::init()
{
    std::cout << "Entered main Menu" << "\n";

    scene::vars->view->set_position(p2d<float>(0,0));
    scene::vars->view->set_size(p2d<float>(1280.0f , 720.0f));

    


    //initialize buttons
    entity *b1 = new button(std::string("Play"),
    //(pass lambda function)
    [this](){
        next_scene = scene_id::game;
        isRunning = false;}
    
    );
    b1->set_position(p2d<float>(800.0f, 100.0f));
    b1->set_size(p2d<float>(300.0f , 120.0f));

    entity *b2 = new button(std::string("Credits"),
    [](){
        std::cout << "CREDITS NOT ADDED YET" << "\n";
        }
    );
    b2->set_position(p2d<float>(800.0f, 250.0f));
    b2->set_size(p2d<float>(300.0f , 120.0f));

    entity *b3 = new button(std::string("Quit"), 
    
    [this](){
        next_scene = scene_id::end;
        isRunning = false;
    }        
    
    );

    b3->set_position(p2d<float>(800.0f, 400.0f));
    b3->set_size(p2d<float>(300.0f , 120.0f));


    scene::vars->entity_manager->set(100 , b1);
    scene::vars->entity_manager->set(150 ,b2);
    scene::vars->entity_manager->set(200 , b3);

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

    animation* anim1 = new animation(100, info1);
    animation* anim2 = new animation(150, info2);
    animation* anim3 = new animation(200, info3);
    
    
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
                scene::vars->view->move(p2d<float>(0,4.0f));
                break;
                case SDL_KeyCode::SDLK_s:
                scene::vars->view->move(p2d<float>(0,-4.0f));
                break;
                case SDL_KeyCode::SDLK_a:
                scene::vars->view->move(p2d<float>(4.0f,0));
                break;
                case SDL_KeyCode::SDLK_d:
                scene::vars->view->move(p2d<float>(-4.0f,0));
                break;
                case SDL_KeyCode::SDLK_r:
                scene::vars->view->scale(p2d<float>(1.05f , 1.05f));
                break;
                case SDL_KeyCode::SDLK_t:
                scene::vars->view->scale(p2d<float>(0.95f , 0.95f));
                break;

                
            }
            case SDL_MOUSEBUTTONDOWN:
            if(event.button.button == SDL_BUTTON_LEFT){
                int x , y;
                SDL_GetMouseState(&x , &y);
                p2d<float> position((float)x,(float)y);
                scene::vars->hitbox_manager->mouse_click(scene::vars->view->cameraToWorldCoordinate(position));
            }

        }

    }
}


void mainMenu::updateLogic()
{

}

void mainMenu::updateGraphics()
{

    SDL_RenderClear(scene::vars->renderer);
    

    scene::vars->view->render(100);
    scene::vars->view->render(150);
    scene::vars->view->render(200);


    SDL_RenderPresent(scene::vars->renderer);
}

scene_id mainMenu::quit()
{
    std::cout << "exiting main menu scene" << "\n";
    return next_scene;
}
