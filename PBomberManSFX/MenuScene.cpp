#include <string>

#include "Sprite.h"
#include "GameManager.h"
#include "GameOverScene.h"
//#include "../Scenes/LevelScene.h"
#include "MenuScene.h"
#include "StageScene.h"


    //++ incremento para la identificación del menú
    MenuItem& operator++(MenuItem& c)
    {
        using type = typename std::underlying_type<MenuItem>::type;
        c = static_cast<MenuItem>(static_cast<type>(c) + 1);
        if (c == MenuItem::Last)
            c = static_cast<MenuItem>(static_cast<type>(MenuItem::None) + 1);
        return c;
    }

    //--decremento para la identificación del menú
    MenuItem& operator--(MenuItem& c)
    {
        using type = typename std::underlying_type<MenuItem>::type;
        c = static_cast<MenuItem>(static_cast<type>(c) - 1);
        if (c == MenuItem::None)
            c = static_cast<MenuItem>(static_cast<type>(MenuItem::Last) - 1);
        return c;
    }

    // incremento ++ para la identificación del menú
    MenuItem operator++(MenuItem& c, int)
    {
        MenuItem result = c;
        ++c;
        return result;
    }

    //decremento -- para la identificación del menú
    MenuItem operator--(MenuItem& c, int)
    {
        MenuItem result = c;
        --c;
        return result;
    }

    MenuScene::MenuScene(GameManager* gm01) : Scene(gm01)
    {
        //antecedentes
        auto background = std::make_shared<Sprite>(gm01->getAssetManager()->getTexture(Texture::MenuBack),
            gm01->getRenderer());
        background->setPosition(30, 20);
        background->setSize(gm01->getWindowWidth() - 60,
            static_cast<int>(gm01->getWindowHeight() / 1.5f) - 20);
        addObject(background);

        //menu de inicio
        startText = std::make_shared<Text>(gm01->getAssetManager()->getFont(), gm01->getRenderer(), "START USFX");
        startText->setColor(colorPressed);
        startText->setSize(static_cast<int>(gm01->getWindowWidth() / 4.0f),
            static_cast<int>(gm01->getWindowHeight() / 20.0f));
        startText->setPosition(static_cast<int>(gm01->getWindowWidth() / 2.0f - startText->getWidth() / 2.0f),
            background->getHeight() + 60);
        addObject(startText);

        //salir del menú
        exitText = std::make_shared<Text>(gm01->getAssetManager()->getFont(), gm01->getRenderer(), "EXIT");
        exitText->setSize(static_cast<int>(gm01->getWindowWidth() / 4.0f),
            static_cast<int>(gm01->getWindowHeight() / 20.0f));
        exitText->setPosition(startText->getPositionX(),
            startText->getPositionY() + exitText->getHeight() + 40);
        addObject(exitText);

        /*gm01->getSceneManager()->addScene("gameover", std::make_shared<GameOverScene>(gm01));*/
        //musica de menu
        /*menuMusic = std::make_shared<Music>(game->getAssetManager()->getMusic(MusicEnum::MainMenu));*/
    }

   /* void MenuScene::onEnter()
    {
        menuMusic->play();
    }*/

   /* void MenuScene::onExit()
    {
        menuMusic->stop();
    }*/

    void MenuScene::onEvent(const SDL_Event& event)
    {
        Scene::onEvent(event);
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.scancode)
            {
                // debemos seleccionar el siguiente elemento del menú
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
                currentSelectedMenu++;
                onMenuItemSelect();
                break;
                //debemos seleccionar el elemento anterior del menú
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
                currentSelectedMenu--;
                onMenuItemSelect();
                break;
                // entrar en el elemento del menú
            case SDL_SCANCODE_SPACE:
            case SDL_SCANCODE_RETURN:
                onMenuItemPress();
                break;
            default:
                break;
            }
        }
    }

    void MenuScene::onMenuItemSelect()
    {
        // restablecer el color de los elementos del menú
        startText->setColor(colorStandard);
        exitText->setColor(colorStandard);
        //cambiar el color del elemento de menú seleccionado
        switch (currentSelectedMenu)
        {
        case MenuItem::Start:
            startText->setColor(colorPressed);
            break;
        case MenuItem::Exit:
            exitText->setColor(colorPressed);
            break;
        default:
            break;
        }
    }

    void MenuScene::onMenuItemPress()
    {
        switch (currentSelectedMenu)
        {
        case MenuItem::Start:
            //ir a la escena del nivel
            gm01->getSceneManager()->addScene("stage", std::make_shared<StageScene>(gm01, 1, 0));
            gm01->getSceneManager()->activateScene("stage");
            break;
        case MenuItem::Exit:
            //detener el bucle del juego
            gm01->stop();
            break;
        default:
            break;
        }
    }