#include <SDL_image.h>
#include <iostream>

#include "../Managers/AssetManager.h"

void AssetManager::load(SDL_Renderer* renderer)
{
    // load font
    loadFont();
    // load textures
    loadTexture(renderer, Texture::MenuBack_Cartoon, "assets/menu_title.png");
    loadTexture(renderer, Texture::Metal_Cartoon, "resources/muro_metal.jpg");
    loadTexture(renderer, Texture::Stone_Cartoon, "resources/muro_piedra_01.png");
    loadTexture(renderer, Texture::Grass_Cartoon, "resources/suelo_cesped_01.png");
    loadTexture(renderer, Texture::Brick_Cartoon, "resources/muro_ceramica_01.png");
    loadTexture(renderer, Texture::Player_Cartoon, "assets/player_Cartoon.png");
    loadTexture(renderer, Texture::Enemy1_Cartoon, "assets/enemy_1.png");
    loadTexture(renderer, Texture::Enemy2_Cartoon, "assets/enemy_2.png");
    loadTexture(renderer, Texture::Enemy3_Cartoon, "assets/enemy_3.png");
    loadTexture(renderer, Texture::Bomb_Cartoon, "assets/bomb.png");
    loadTexture(renderer, Texture::Explosion_Cartoon, "assets/explosion.png");
    loadTexture(renderer, Texture::Door_Cartoon, "assets/door.png");



    loadTexture(renderer, Texture::MenuBack_Clasico, "assets/menu_title.png");
    loadTexture(renderer, Texture::Metal_Clasico, "resources/muro_metal.jpg");
    loadTexture(renderer, Texture::Stone_Clasico, "resources/muro_piedra_01.png");
    loadTexture(renderer, Texture::Grass_Clasico, "resources/suelo_cesped_01.png");
    loadTexture(renderer, Texture::Brick_Clasico, "resources/muro_ceramica_01.png");
    loadTexture(renderer, Texture::Player_Clasico, "assets/player_Clasico.png");
    loadTexture(renderer, Texture::Enemy1_Clasico, "assets/enemy_1.png");
    loadTexture(renderer, Texture::Enemy2_Clasico, "assets/enemy_2.png");
    loadTexture(renderer, Texture::Enemy3_Clasico, "assets/enemy_3.png");
    loadTexture(renderer, Texture::Bomb_Clasico, "assets/bomb.png");
    loadTexture(renderer, Texture::Explosion_Clasico, "assets/explosion.png");
    loadTexture(renderer, Texture::Door_Clasico, "assets/door.png");

    loadTexture(renderer, Texture::MenuBack_Personalizado, "assets/menu_title.png");
    loadTexture(renderer, Texture::Metal_Personalizado, "resources/muro_metal.jpg");
    loadTexture(renderer, Texture::Stone_Personalizado, "resources/muro_piedra_01.png");
    loadTexture(renderer, Texture::Grass_Personalizado, "resources/suelo_cesped_01.png");
    loadTexture(renderer, Texture::Brick_Personalizado, "resources/muro_ceramica_01.png");
    loadTexture(renderer, Texture::Player_Personalizado, "assets/player_Clasico.png");
    loadTexture(renderer, Texture::Enemy1_Personalizado, "assets/enemy_1.png");
    loadTexture(renderer, Texture::Enemy2_Personalizado, "assets/enemy_2.png");
    loadTexture(renderer, Texture::Enemy3_Personalizado, "assets/enemy_3.png");
    loadTexture(renderer, Texture::Bomb_Personalizado, "assets/bomb.png");
    loadTexture(renderer, Texture::Explosion_Personalizado, "assets/explosion.png");
    loadTexture(renderer, Texture::Door_Personalizado, "assets/door.png");

    loadTexture(renderer, Texture::MenuBack_Realista, "assets/menu_title.png");
    loadTexture(renderer, Texture::Metal_Realista, "resources/muro_metal.jpg");
    loadTexture(renderer, Texture::Stone_Realista, "resources/muro_piedra_01.png");
    loadTexture(renderer, Texture::Grass_Realista, "resources/suelo_cesped_01.png");
    loadTexture(renderer, Texture::Brick_Realista, "resources/muro_ceramica_01.png");
    loadTexture(renderer, Texture::Player_Realista, "assets/player_Clasico.png");
    loadTexture(renderer, Texture::Enemy1_Realista, "assets/enemy_1.png");
    loadTexture(renderer, Texture::Enemy2_Realista, "assets/enemy_2.png");
    loadTexture(renderer, Texture::Enemy3_Realista, "assets/enemy_3.png");
    loadTexture(renderer, Texture::Bomb_Realista, "assets/bomb.png");
    loadTexture(renderer, Texture::Explosion_Realista, "assets/explosion.png");
    loadTexture(renderer, Texture::Door_Realista, "assets/door.png");
    // load music
    loadMusic(MusicEnum::MainMenu, "assets/main_theme.ogg");
    loadMusic(MusicEnum::Level, "assets/level.ogg");
    // load sounds
    loadSound(SoundEnum::Win, "assets/win.wav");
    loadSound(SoundEnum::Lose, "assets/lose.wav");
    loadSound(SoundEnum::Explosion, "assets/explosion.wav");
    if (auto explosionSound = getSound(SoundEnum::Explosion))
    {
        Mix_VolumeChunk(explosionSound.get(), 35);
    }
}

std::shared_ptr<TTF_Font> AssetManager::getFont() const
{
    return font;
}

std::shared_ptr<SDL_Texture> AssetManager::getTexture(Texture texture)
{
    return textures[texture];
}

std::shared_ptr<Mix_Music> AssetManager::getMusic(MusicEnum music)
{
    return musics[music];
}

std::shared_ptr<Mix_Chunk> AssetManager::getSound(SoundEnum sound)
{
    return sounds[sound];
}

void AssetManager::loadFont()
{
    // load font
    font = std::shared_ptr<TTF_Font>(TTF_OpenFont("assets/font.ttf", 32), TTF_CloseFont);
    if(!font)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
    }
}

void AssetManager::loadTexture(SDL_Renderer* renderer, Texture texture, const std::string& filePath)
{
    textures[texture] =
        std::shared_ptr<SDL_Texture>(IMG_LoadTexture(renderer, filePath.c_str()), SDL_DestroyTexture);
    if(!textures[texture])
    {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
}


void AssetManager::loadMusic(MusicEnum music, const std::string& filePath)
{
    musics[music] = std::shared_ptr<Mix_Music>(Mix_LoadMUS(filePath.c_str()), Mix_FreeMusic);
    if(!musics[music])
    {
        std::cout << "loadMusic Error: " << Mix_GetError() << std::endl;
    }
}

void AssetManager::loadSound(SoundEnum sound, const std::string& filePath)
{
    sounds[sound] = std::shared_ptr<Mix_Chunk>(Mix_LoadWAV(filePath.c_str()), Mix_FreeChunk);
    if(!sounds[sound])
    {
        std::cout << "loadSound Error: " << Mix_GetError() << std::endl;
    }
}
