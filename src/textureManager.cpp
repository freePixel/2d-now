#include "scene.h"
#include "textureManager.h"



textureInfo::textureInfo(p2d<float> _size)
{
        size = _size;
}

textureInfo::textureInfo()
{
    
}




std::map<TEXTURES , std::string> CVTMAP::TEXTURE = {
    {TEXTURES::NONE , "../resources/textures/undefined.png"} , 
    {TEXTURES::BUTTON , "../resources/textures/button.png"} ,
    {TEXTURES::DIRT , "../resources/textures/dirt.png"} , 
    {TEXTURES::GRASS , "../resources/textures/grass.png"}
};


textureManager::textureManager()
{
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    manager::forceLoad = true;
    font = TTF_OpenFont("../resources/fonts/gothic.ttf" , 50);
    if(font == nullptr)
    {
        throw std::runtime_error(TTF_GetError());
    }
    add_texture(TEXTURES::NONE);
    
}

bool textureManager::force_load(int id)
{
    if(CVTMAP::TEXTURE.count((TEXTURES)id) != 0){
        add_texture((TEXTURES)id);
        return true;
    }

    else{
        std::cout << "Unknown texture! ID = " << id << "\n";
        return false;
    }
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

void textureManager::add_texture(TEXTURES texture)
{
    SDL_Texture* t = load_texture(CVTMAP::TEXTURE[texture].c_str());
    manager::set((int)texture , t);
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
        SDL_Texture* texture = SDL_CreateTextureFromSurface(scene::vars->renderer , surface);

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
        SDL_Texture* texture = SDL_CreateTextureFromSurface(scene::vars->renderer, surface);
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

void textureManager::derived_remove(int id)
{
    SDL_DestroyTexture(map[id]);
    map.erase(id);
}

textureManager::~textureManager()
{
    for(const auto &key : map) remove(key.first);
}

p2d<float> textureManager::get_text_size(std::string text)
{
    int* w = new int();
    int* h = new int();
    TTF_SizeText(font , text.c_str() , w , h);
    p2d<float> size =  p2d<float>((float)*w , (float)*h);
    delete w;
    delete h;
    return size;

}