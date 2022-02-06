#pragma once

#include "scene.h"
#include "sprite.h"
#include "button.h"
#include "animation.h"

class mainMenu : public scene
{
    public:

        void init();
        void handleEvents();
        void updateLogic();
        void updateGraphics();
        scene_id quit();
        
    private:
        std::vector<entity*> buttons;
        hitboxManager* hit_manager = nullptr;
};


