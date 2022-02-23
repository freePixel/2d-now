#pragma once
#include "entity.h"

#define BLOCK_SIZE 32


enum class BLOCKS
{
    DIRT = 0 , GRASS
};

class block : public entity
{
    public:
    block(BLOCKS type , p2d<float> position)
    {
        set_size(p2d<float>((float)BLOCK_SIZE , (float)BLOCK_SIZE));
        set_position(position);
        
        textureInfo info = textureInfo();
        info.position_unit = UNIT::PX;
        info.position = p2d<float>(0.0f,0.0f);
        info.size_unit     = UNIT::INHERT;
    
        
        switch(type)
        {
            case BLOCKS::DIRT:
            info.id = (int)TEXTURES::DIRT;
            break;
            case BLOCKS::GRASS:
            info.id = (int)TEXTURES::GRASS;
            break;
        }

        texSet->add_texture(info , 0);
    }

    void on_id_change(int lastid , int newid) override
    {
        
    }

    private:
};