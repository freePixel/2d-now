#include "scene.h"

scene::~scene()
{
    delete scene::vars;
}

void scene::show_screen_info()
{
    double fps = scene::vars->clock->get_fps();
    const SDL_FRect* dim = scene::vars->view->get_dimension();
    std::string str = "FPS:" + std::to_string(fps) + "| x:" + std::to_string((int)dim->x) + ",y:" +
    std::to_string((int)dim->y) + ",w:"+std::to_string((int)dim->w)+",h:"+std::to_string((int)dim->h);
    
    SDL_SetWindowTitle(scene::vars->window , str.c_str());

}

scene_id scene::process(SDL_Renderer* _renderer , SDL_Window* _window)
{
    if(_renderer == nullptr || _window == nullptr)
    {
        throw std::runtime_error("RENDERER OR WINDOW == NULLPTR");
        return scene_id::end;
    }
    
    scene::vars = new scene_objects();
    vars->initialize_variables(_renderer , _window);
    
    std::function<void()> f = std::bind(&scene::show_screen_info , this);
    scene::vars->clock->newTimeEvent(EVENTS::SHOW_SCREEN_FPS , 1000 , f);

    init();
    while(isRunning)
    {
       scene::vars->clock->start_frame();
        
        handleEvents();

        if(scene::vars->clock->canTickCps())
        {

            scene::vars->clock->cpsTick();
            updateLogic();
            scene::vars->clock->process_time_events();
            scene::vars->clock->update_dt_functions();
        }
        if(scene::vars->clock->canTickFps())
        {

            scene::vars->clock->fpsTick();
            updateGraphics();
        }

        scene::vars->clock->end_frame();
        scene::vars->clock->wait();
    }

    return quit();
}

scene_objects::scene_objects()
{

}

void scene_objects::initialize_variables(SDL_Renderer* r , SDL_Window* w)
{
    renderer = r;
    window   = w;
    clock = new timer(60.0 , 60.0);

    texture_manager = new textureManager();

    hitbox_manager = new hitboxManager();

    entity_manager = new entityManager();

    chunk_manager = new chunkManager();

    view = new camera();

}

scene_objects::~scene_objects()
{
    delete texture_manager;
    delete hitbox_manager;
    delete entity_manager;
    delete chunk_manager;
    delete clock;
    delete view;
}

scene_objects* scene::vars = nullptr;