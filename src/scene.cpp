#include "scene.h"

scene::~scene()
{
    delete clock;
}


scene_id scene::process(SDL_Renderer* _renderer , SDL_Window* _window)
{
    this->window = _window;
    this->renderer = _renderer;

    clock->newTimeEvent(time_event::logic , 1000.0 / 60.0 , updateLogic());
    clock->newTimeEvent(time_event::graphics , 1000.0 / 30.0 , updateGraphics());

    texture_manager = new textureManager(_renderer);

    _camera = new camera(_renderer , texture_manager , _window);
    

    init();

    while(isRunning)
    {
        clock->startFrame();

        clock->update_time_events();
        
        clock->endFrame();

        clock->wait();
    }

    return quit();
}