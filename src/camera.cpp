#include "camera.h"

camera::camera(SDL_Renderer* _renderer , textureManager* _texture_manager , SDL_Window* _window)
{
    
    this->renderer = _renderer;
    this->texture_manager = _texture_manager;
    this->window = window;

    entity::set_position(p2d<float>(0.0f,0.0f));
    entity::set_size(p2d<float>(500.0f,500.0f));

    update_window_size();
}

void camera::update_window_size()
{
    int x , y;
    SDL_GetWindowSize(window , &x , &y);
    window_size = p2d<float>((float)x , (float)y);
}

void camera::render(entity* _entity)
{
    SDL_Texture* t = texture_manager->get(_entity->get_texture_id());
    SDL_FRect* r = worldToCameraCoordinate(_entity->get_dimension());
    SDL_RenderCopyF(renderer , t , NULL , _entity->get_dimension());
}

SDL_FRect* camera::worldToCameraCoordinate(const SDL_FRect* rect)
{
    //normalize basis

    p2d<float> scale((dimension->w / rect->w) / window_size.x, (dimension->h / rect->h) / window_size.y);


    return new SDL_FRect{
        (rect->x - dimension->x) * scale.x,
        (rect->y - dimension->y) * scale.y,
        scale.x,
        scale.y};

    
}

bool camera::contains(SDL_FRect* rect)
{
    return (rect->x + rect->w >= dimension->x &&
    rect->x <= dimension->x + dimension->w &&
    
    rect->y + rect->h >= dimension->y &&
    rect->y <= dimension->y + dimension->h);
}