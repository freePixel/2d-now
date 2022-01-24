#pragma once

#include "scene.h"
#include "sprite.h"

class mainMenu : public scene
{
    public:

        void init();
        void handleEvents();
        void updateLogic();
        void updateGraphics();
        scene_id quit();
        
    private:
        entity* player = nullptr;
};


