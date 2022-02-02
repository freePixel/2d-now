#include "entity.h"
#include <string>
#include "animation.h"
#include "hitboxManager.h"
#include "textureManager.h"
/*
    button is a rectangle with a text inside

*/
class button : public entity
{
    public:
        button(std::string text , textureManager* _tManager , hitboxManager* hitbox_manager , std::function<void()> onclick);
        ~button();
    private:
    std::string text;
    textureManager* t_manager = nullptr;
    hitboxManager* hitbox_manager = nullptr;


};