#include "textureManager.h"




textureManager::textureManager(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    font = TTF_OpenFont("../resources/fonts/gothic.ttf" , 20);
    if(font == nullptr)
    {
        throw std::runtime_error(TTF_GetError());
    }
    add_texture(TEXTURE::NONE , "../resources/textures/undefined.png");

}



void textureManager::add_text(int id , const char* text)
{
    SDL_Texture* t = load_text(text);
    manager::set(id , t);
}

void textureManager::add_texture(int id , const char* path)
{
    SDL_Texture* t = load_texture(path);
    manager::set(id , t);
}



SDL_Texture* textureManager::load_texture(const char* path)
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
            return nullptr;
        }
        else{
            std::cout << "Successfully loaded texture from " << path << "\n";
            
            
            return texture;
        }
    }
}

SDL_Texture* textureManager::load_text(const char* text)
{
    SDL_Color color = SDL_Color{255,255,255};
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
            return nullptr;
        }
        else{
            std::cout << "Successfully loaded text \" " << text << " \" " << "\n";
            return texture;
        }
    }
}

void textureManager::remove(int id)
{
    SDL_DestroyTexture(map[id]);
    map.erase(id);
}

textureManager::~textureManager()
{
    for(const auto &key : map) remove(key.first);
}