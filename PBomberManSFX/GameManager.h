#pragma once
#include<iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include "Bomber.h"
#include "MuroMetalico.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
  
class GameManager
{
private:
    //The window we'll be rendering to
    SDL_Window* gWindow;

    //The window renderer
    SDL_Renderer* gRenderer;

    //Current displayed texture
    SDL_Texture* gTexture = nullptr;

    Texture* texturaBomber1;
    Texture* texturaBomber2;
    Texture* texturaMuroMetalico;

    vector<GameObject*> actoresJuego;
    
public:
    GameManager();
	int onExecute();
    bool onInit();
    void close();
    
    //Loads individual image as texture
    SDL_Texture* loadTexture(std::string path);

    bool loadMedia();
};
