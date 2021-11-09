#pragma once


#include <SDL.h>
#include <memory>

#include <queue>

#include <unordered_map>
#include "Scene.h"


#include "SceneManager.h"
#include "AssetManager.h"
#include "MenuScene.h"
#include<iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include "Bomberman.h"
#include "MuroMetal.h"
#include "MapGenerator.h"
#include "system/KeyboardInput.h"
#include "TilesGraph.h"

using namespace std;



const int SCREEN_WIDTH = 850;
const int SCREEN_HEIGHT = 510;
 

    class GameManager
    {
    private:
        //The window we'll be rendering to
        SDL_Window* gWindow;

        //The window renderer
        SDL_Renderer* gRenderer;

        //Current displayed texture
        SDL_Texture* gTexture = nullptr;

        vector<GameObject*> actoresJuego;
        MapGenerator* generadorMapa;
        KeyboardInput* keyboardInput;


        SDL_Event evento;
        bool enEjecucion;

        TilesGraph* tilesGraphGM;

        SDL_Rect camera;
        Uint32 lastTickTime = 0;

        // SDL2 C pointers
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;

        SceneManager* sceneManager = nullptr; // scene manager 
        AssetManager* assetManager = nullptr; // asset manager

        // screen parameters
        int windowWidth = 0;
        int windowHeight = 0;

        bool isRunning = false;  // game loop status
        //Uint32 lastTickTime = 0; // last time for delta calculation

    public:
        // Constructores & destructores

        GameManager(const std::string& windowName, const int windowWidth, const int windowHeight);
        GameManager();

        ~GameManager();

        // Metodos especializados
        bool onInit();
        bool loadContent();
        int onExecute();
        void onEvent(SDL_Event* _event);
        void onLoop();
        void onRender();
        void close();

        void run();
        void stop();
        int getWindowWidth() const;
        int getWindowHeight() const;
        SDL_Renderer* getRenderer() const;
        SceneManager* getSceneManager() const;
        AssetManager* getAssetManager() const;
    };