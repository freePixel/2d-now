#include "scene.h"

scene::~scene()
{
    delete clock;
}


scene_id scene::process(SDL_Renderer* _renderer , SDL_Window* _window)
{
    this->window = _window;
    this->renderer = _renderer;

    clock = new timer(30,30);
    
    texture_manager = new textureManager(_renderer);

    _camera = new camera(_renderer , texture_manager , _window);

    init();

    while(isRunning)
    {
        clock->start_frame();

        if(clock->updateLogic())
        {
            handleEvents();
            updateLogic();
            clock->updateL();
        }
        if(clock->updateGraphics())
        {
            updateGraphics();
            clock->updateF();
        }

        clock->end_frame();
        clock->wait();
    }

    return quit();
}