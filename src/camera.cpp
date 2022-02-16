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

p2d<float> camera::cameraToWorldCoordinate(p2d<float> pos)
{
    p2d<float> scale(window_size.x / dimension->w, window_size.y / dimension->h);

    return p2d<float>(dimension->x + pos.x/scale.x , dimension->y + pos.y/scale.y);
}

void camera::update_window_size()
{

    int x = SDL_GetWindowSurface(window)->w;
    int y = SDL_GetWindowSurface(window)->h;
    window_size = p2d<float>((float)x , (float)y);
}

void camera::render(entity* _entity)
{

    std::vector<textureInfo>& info_vec = _entity->texSet->get_set();

    p2d<float> src_pos = _entity->get_position();
    p2d<float> src_size = _entity->get_size();

    for(int i=0;i<info_vec.size();i++)
    {
        UNIT size_unit = info_vec.at(i).size_unit;
        UNIT pos_unit  = info_vec.at(i).position_unit;
        p2d<float> pos_target = info_vec.at(i).position;
        p2d<float> size_target = info_vec.at(i).size;

        p2d<float> size = get_size_by_unit(size_unit , src_size , size_target);
        p2d<float> pos  = get_position_by_unit(pos_unit , src_pos , src_pos , pos_target);

        const SDL_FRect* src_rect = new SDL_FRect{size.x , size.y , pos.x , pos.y};
        SDL_FRect* dst_rect = worldToCameraCoordinate(src_rect);

        SDL_Texture* texture = texture_manager->get(info_vec.at(i).id);
        SDL_RenderCopyF(renderer , texture , NULL , dst_rect);

        delete src_rect;
        delete dst_rect;
    }
}

inline p2d<float> camera::get_position_by_unit(UNIT unit , p2d<float> ctx_size , p2d<float> ctx_pos , p2d<float> target)
{
    switch(unit)
    {
        case UNIT::PX:
            return ctx_pos + target;
            break;
        case UNIT::PER:
            return ctx_pos + target * ctx_size;
            break;
        default:
            throw(std::runtime_error("get_position_by_unit() does not recognize unit"));
            return p2d<float>(0,0);
    }
}

inline p2d<float> camera::get_size_by_unit(UNIT unit , p2d<float> ctx_size , p2d<float> target)
{
    switch(unit)
    {
        case UNIT::PX:
            return target; 
            break;
        case UNIT::PER:
            return target * ctx_size;
            break;
        default:
            throw(std::runtime_error("get_size_by_unit() does not recognize unit"));
            return p2d<float>(0,0);
    }
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