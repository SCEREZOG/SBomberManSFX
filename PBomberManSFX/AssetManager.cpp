#include <SDL_image.h>
#include <iostream>

#include "AssetManager.h"

    void AssetManager::load(SDL_Renderer* renderer)
    {
        // cargar fuente
        loadFont();
        // cargar texturas
        loadTexture(renderer, Texture::MenuBack, "assets/menu_title.png");
        
     
    }

    std::shared_ptr<TTF_Font> AssetManager::getFont() const
    {
        return font;
    }

    std::shared_ptr<SDL_Texture> AssetManager::getTexture(Texture texture)
    {
        return textures[texture];
    }

   

    void AssetManager::loadFont()
    {
        // cargar fuente
        font = std::shared_ptr<TTF_Font>(TTF_OpenFont("assets/font.ttf", 32), TTF_CloseFont);
        if (!font)
        {
            std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        }
    }

    void AssetManager::loadTexture(SDL_Renderer* renderer, Texture texture, const std::string& filePath)
    {
        textures[texture] =
            std::shared_ptr<SDL_Texture>(IMG_LoadTexture(renderer, filePath.c_str()), SDL_DestroyTexture);
        if (!textures[texture])
        {
            std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
        }
    }

   


