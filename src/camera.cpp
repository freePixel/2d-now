#include "camera.h"

camera::camera(SDL_Renderer* _renderer , textureManager* _texture_manager , SDL_Window* _window)
{
    
    this->renderer = _renderer;
    this->texture_manager = _texture_manager;
    this->window = _window;

    entity::set_position(p2d<float>(0.0f,0.0f));
    entity::set_size(p2d<float>(640.0f,360.0f));

    update_window_size();
}

void camera::update_window_size()
{

    int x = SDL_GetWindowSurface(window)->w;
    int y = SDL_GetWindowSurface(window)->h;
    window_size = p2d<float>((float)x , (float)y);
}

void camera::render(entity* _entity)
{

    std::vector<int>& textures = _entity->texSet->get_set();

    SDL_FRect* r = worldToCameraCoordinate(_entity->get_dimension());
    for(int i=0;i<textures.size();i++)
    {
        SDL_Texture* t = texture_manager->get(textures[i]);
        SDL_RenderCopyF(renderer , t , NULL , r);
    }
    delete r;
}

SDL_FRect* camera::worldToCameraCoordinate(const SDL_FRect* rect) //rect should be delected
{

    p2d<float> scale(window_size.x / dimension->w, window_size.y / dimension->h);

    return new SDL_FRect{
        (rect->x - dimension->x) * scale.x,
        (rect->y - dimension->y) * scale.y,
        rect->w * scale.x,
        rect->h * scale.y};

    
}

bool camera::contains(SDL_FRect* rect)
{
    return (rect->x + rect->w >= dimension->x &&
    rect->x <= dimension->x + dimension->w &&
    
    rect->y + rect->h >= dimension->y &&
    rect->y <= dimension->y + dimension->h);
}