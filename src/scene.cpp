#include "scene.h"

scene::~scene()
{
    delete clock;
}



scene_id scene::process(SDL_Renderer* _renderer , SDL_Window* _window)
{
    this->window = _window;
    this->renderer = _renderer;

    clock = new timer(60.0 , 60.0);
    texture_manager = new textureManager(_renderer);

    _camera = new camera(_renderer , texture_manager , _window);
    

    init();

    while(isRunning)
    {
       clock->start_frame();

        handleEvents();

        if(clock->canTickCps())
        {
            clock->cpsTick();
            updateLogic();
            clock->process_time_events();
            clock->update_dt_functions();
        }
        if(clock->canTickFps())
        {
            clock->fpsTick();
            updateGraphics();
        }

        clock->end_frame();
        clock->wait();



       clock->end_frame();
       clock->wait();
    }

    return quit();
}