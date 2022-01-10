#pragma once

#include "scene.h"

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