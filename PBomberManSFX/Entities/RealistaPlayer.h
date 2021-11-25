
#pragma once
#include "Player.h"
class RealistaPlayer :
    public Player
{
public:
    RealistaPlayer(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer);
};

