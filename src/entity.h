#pragma once

#include "point.h"
#include <SDL2/SDL.h>
#include "textureManager.h"

struct textureSet;

enum ID_OFFSET
{
    SPRITE = 0,
    ANIMATION = 1,
    HITBOX = 2

};


class entity
{
    public:
        int get_id();
        void set_id(int id);
        bool is_world_coordinate();
        void move(p2d<float> point);
        void set_position(p2d<float> point);
        void set_size(p2d<float> point);
        void scale(p2d<float> point);
        void set_texture(int texture_id);
        p2d<float> get_position();
        p2d<float> get_size();
        const SDL_FRect* get_dimension();


        entity();
        ~entity();
        

        textureSet* texSet = nullptr;

    protected:
        virtual void on_id_change(int lastid , int newid) = 0;
        SDL_FRect* dimension = nullptr;
        bool world_coordinate = true;       /*when 'true', entity coordinate must be interpreted such that it is contained in the world
                                            when 'false' entity coordinate must be absolute in screen coordinate (used in objects stuck in the camera)*/
        int id;

    private:
    static int id_c;


};