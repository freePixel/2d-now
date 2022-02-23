#pragma once

#include "scene.h"
#include "block.h"

class inGame : public scene
{
    public:
        void init();
        void handleEvents();
        void updateLogic();
        void updateGraphics();
        scene_id quit();
    private:

    

};