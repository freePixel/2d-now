#pragma once

#include "entity.h"
#include "animation.h"
#include "textureManager.h"

class background : public entity
{
    public:
        background(textureManager* manager , timer* t)
        {
            animationInfo info;
            info.trajectory.push_back(p2d<float>(0,0));
            info.trajectory.push_back(p2d<float>(1000 , 0));
            info.repeat = true;
            info.type = animationType::linear;
            info.duration = 5000.0;

            
            if(!manager->contains(TEXTURES::BACK1))
            {
                
            }

            anim = new animation(this , t , info);
        }

        ~background()
        {

        }
    private:
        textureManager* t_manager = nullptr;
        animation* anim = nullptr;
        
};

