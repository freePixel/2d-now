#pragma once

#include "entity.h"
#include <utility>
#include <memory>

/*
camera class is responsible for rendering all entity's inside a scene.
*/
enum class UNIT; //avoid circular dependency


class camera : public entity    
{
    public:
        camera();
        void render(int _entity_id);
        void render(p2d<int> _chunk);
        void update_window_size();
        p2d<float> cameraToWorldCoordinate(p2d<float> pos);
        bool contains(SDL_FRect* rect); //check if a given rect intersects camera
        
    private:

        void on_id_change(int lastid , int newid) override;

        inline p2d<float> get_position_by_unit(UNIT unit , p2d<float> ctx_size , p2d<float> ctx_pos , p2d<float> calculated_size , p2d<float> target);
        inline p2d<float> get_size_by_unit(UNIT unit , p2d<float> ctx_size  , p2d<float> target);
        p2d<float> window_size = p2d<float>(1280 , 720); //default value
        
        std::vector<p2d<int>> target_chunks;
        
        SDL_FRect* worldToCameraCoordinate(const SDL_FRect* rect); //convert world coordinate into camera coordinate
};