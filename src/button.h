#pragma once


#include "entity.h"
#include <string>
#include "animation.h"
#include "scene.h"
/*
    button is a rectangle with a text inside

*/
class button : public entity
{
    public:
        button(std::string text , std::function<void()> onclick);
        ~button();
    private:
    std::string text;

    void on_id_change(int lastid , int newid) override;


};