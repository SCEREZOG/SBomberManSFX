#ifndef _BOMBERMAN_SCENES_MENU_SCENE_H_
#define _BOMBERMAN_SCENES_MENU_SCENE_H_

#include <SDL.h>
#include <memory>

//#include "../Entities/Music.h"
#include "Text.h"
#include "Scene.h"
#include "Sprite.h"

    /**
     * @breve ID de menú  
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
     * @breve escena del menú
     *
     */
    class MenuScene : public Scene
    {
    public:
        /**
         * @breve Construya una nueva escena de menú
         *
         * @juego de param
         */
        MenuScene(GameManager* gm01);
        /**
         * @breve Llamado cuando se activó la escena
         *
         */
       /* virtual void onEnter() override;*/
        /**
         * @breve Llamado cuando se desactivó la escena
         *
         */
      /*  virtual void onExit() override;*/
        /**
         * @Disparo breve en evento SDL2 si la escena está activa
         * @evento param - evento SDL2
         */
        virtual void onEvent(const SDL_Event& event) override;

    private:
        /**
         * @breve llamado cuando se seleccionó el elemento del menú
         *
         */
        void onMenuItemSelect();
        /**
         * @breve llamado cuando se presiona el elemento del menú
         *
         */
        void onMenuItemPress();

        std::shared_ptr<Text> startText = nullptr;      //inicio del menú
        std::shared_ptr<Text> exitText = nullptr;       //salir del menú
        //std::shared_ptr<Music> menuMusic = nullptr;     //musica de menu
        MenuItem currentSelectedMenu = MenuItem::Start; //menú seleccionado actual

        //colores constantes para la selección del menú
        const SDL_Color colorStandard = { 255, 255, 255, 255 };
        const SDL_Color colorPressed = { 66, 134, 244, 255 };
    };

#endif // _BOMBERMAN_SCENES_MENU_SCENE_H_