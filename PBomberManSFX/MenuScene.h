#ifndef _BOMBERMAN_SCENES_MENU_SCENE_H_
#define _BOMBERMAN_SCENES_MENU_SCENE_H_

#include <SDL.h>
#include <memory>

//#include "../Entities/Music.h"
#include "Text.h"
#include "Scene.h"
#include "Sprite.h"

    /**
     * @breve ID de men�  
     *
     */
    enum class MenuItem
    {
        None,
        Start,
        Exit,
        Last
    };
    /**
     * @breve escena del men�
     *
     */
    class MenuScene : public Scene
    {
    public:
        /**
         * @breve Construya una nueva escena de men�
         *
         * @juego de param
         */
        MenuScene(GameManager* gm01);
        /**
         * @breve Llamado cuando se activ� la escena
         *
         */
       /* virtual void onEnter() override;*/
        /**
         * @breve Llamado cuando se desactiv� la escena
         *
         */
      /*  virtual void onExit() override;*/
        /**
         * @Disparo breve en evento SDL2 si la escena est� activa
         * @evento param - evento SDL2
         */
        virtual void onEvent(const SDL_Event& event) override;

    private:
        /**
         * @breve llamado cuando se seleccion� el elemento del men�
         *
         */
        void onMenuItemSelect();
        /**
         * @breve llamado cuando se presiona el elemento del men�
         *
         */
        void onMenuItemPress();

        std::shared_ptr<Text> startText = nullptr;      //inicio del men�
        std::shared_ptr<Text> exitText = nullptr;       //salir del men�
        //std::shared_ptr<Music> menuMusic = nullptr;     //musica de menu
        MenuItem currentSelectedMenu = MenuItem::Start; //men� seleccionado actual

        //colores constantes para la selecci�n del men�
        const SDL_Color colorStandard = { 255, 255, 255, 255 };
        const SDL_Color colorPressed = { 66, 134, 244, 255 };
    };

#endif // _BOMBERMAN_SCENES_MENU_SCENE_H_