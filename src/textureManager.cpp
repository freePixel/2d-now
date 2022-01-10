#include "textureManager.h"


textureManager::textureManager(SDL_Renderer* renderer)
{
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);

    this->renderer = renderer;
    if(renderer == nullptr)
    {
        throw std::runtime_error("Invalid renderer");
        return;
    }

    font = TTF_OpenFont("../resources/fonts/gothic.ttf" , 20);
    if(font == nullptr)
    {
        throw std::runtime_error(TTF_GetError());
    }

    add_texture(texture_id::none , "../resources/textures/undefined.png");
}

void textureManager::add_texture(int id , const char* path)
{
    //load texture here
    SDL_Surface* surface = IMG_Load(path);
    if(surface == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }
    else{
        SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer , surface);
        if(texture == nullptr)
        {
            throw std::runtime_error(SDL_GetError());
        }
        else{
            if(add_map(id , texture))
            {
                std::cout << "Successfully loaded texture from " << path << "\n";
            }

            return;
        }
    }
    
    
}

void  textureManager::add_text(int id , const char* text , SDL_Color color)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font , text , color);
    if(surface == nullptr)
    {
        throw std::runtime_error(TTF_GetError());
    }
    else{
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if(texture == nullptr)
        {
            throw std::runtime_error(SDL_GetError());
        }
        else{
            if(add_map(id , texture))
            {
                std::cout << "Successfully loaded text \" " << text << " \" " << "\n";
            }

            return;
        }
    }
}


SDL_Texture* textureManager::get_texture(int id)
{
    if(textureMap.count(id) != 0)
    {
        return textureMap[id];
    }
    else{
        return textureMap[0];
    }
}

textureManager::~textureManager()
{
    for(const auto&key : textureMap)
    {
        remove_texture(key.first);
    }

    TTF_CloseFont(font);
    IMG_Quit();
    TTF_Quit();
}

bool textureManager::add_map(int id , SDL_Texture* t)
{
    if(textureMap.count(id))
    {
        throw std::runtime_error("The id(" + std::to_string(id) + ") is aldready being used");
        return false;
    }
    else{
        textureMap[id] = t;
        return true;
    }
}
void textureManager::remove_texture(int id)
{
    if(textureMap.count(id) == 0)
    {
        throw std::runtime_error("The id(" + std::to_string(id) + ") isn't being used");

    }
    else{
        SDL_DestroyTexture(textureMap[id]);
        textureMap.erase(id);

    }
}