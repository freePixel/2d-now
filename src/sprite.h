#pragma once

#include "stdexcept"
#include <vector>
#include "textureManager.h"


namespace sprite_texture
{
    namespace player
    {
        static std::vector<int> sp1 = {(int)TEXTURES::T1,(int)TEXTURES::T2, (int)TEXTURES::T3};
    };
}

enum sprite_speed
{
    normal = 750,
    medium = 500,
    fast = 250,
};



/*
sprite is should not be used in objects with multiple textures (textureSet size > 1)
*/

class sprite
{
    public:
        /*
        _texture_ids -> vector containing a list of texture ids of a given sprite
        sprite_speed -> time needed in ms to update sprite animation
        */
        sprite(int _entity_id ,  std::vector<textureInfo>& _texture_ids, sprite_speed _speed); 
         
        ~sprite();
        

        

    protected:

    private:
        int speed = sprite_speed::normal; //default value
        int size;
        int entity_id;
        int vec_pos_counter;
        std::vector<textureInfo>& texture_ids;

        void update(); //next-texture (updated with timer)
        

};