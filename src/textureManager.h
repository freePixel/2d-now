#pragma once


#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <SDL2/SDL_image.h>
#include <map>
#include "manager.h"
#include "point.h"





enum class TEXTURES
{
    NONE = 0, BACK1 , BACK2 , BUTTON , T1 , T2 , T3 , DIRT , GRASS
};



enum class UNIT
{
    PX ,    //Pixels 
    PER,     //Percentage
    INHERT,
    CENTERED
};

struct CVTMAP       //Conversion map
{
    static std::map<TEXTURES , std::string> TEXTURE;
};

struct textureInfo
{

    textureInfo(p2d<float> _size);
    textureInfo();
    int id; //texture id
    p2d<float> position = {0,0}; //position based on context
    p2d<float> size = {0 , 0}; //size
    UNIT position_unit = UNIT::PX;
    UNIT size_unit     = UNIT::INHERT; 

};

struct textureSet
{
    public:
        textureSet(textureInfo info)
        {
            set.push_back(info);
        }

        textureSet()
        {

        }
        

        std::vector<textureInfo>& get_set()
        {
            return set;
        }
        void add_texture(textureInfo info , int priority)   //priority==0 means that the texture with t_id will be rendered first
        {
            if(priority >= set.size())
            {
                set.push_back(info);
            }
            else{
                set.insert(set.begin() + priority , info);
            }
        }
        void remove_from_set_by_priority(int priority)
        {
            set.erase(set.begin() + priority);
        }
        std::vector<textureInfo> set;
};


class textureManager : public manager<int , SDL_Texture*>
{
    public:
        ~textureManager();
        textureManager();

        void add_texture(int id , const char* path);
        void add_texture(TEXTURES texture); //add texture by TEXTURES enum id
        void add_text(int  id , const char* text);

        void derived_remove(int id) override;

        bool force_load(int id) override;
        
        p2d<float> get_text_size(std::string text);

    protected:
        
        void on_set(int id) override{}
        SDL_Texture* load_texture(const char* path);
        SDL_Texture* load_text(const char* text);
        TTF_Font* font = nullptr;

        
};