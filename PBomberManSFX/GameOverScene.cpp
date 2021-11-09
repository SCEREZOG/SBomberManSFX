#include <string>

#include "GameManager.h"
#include "GameOverScene.h"
#include "MenuScene.h"


    GameOverScene::GameOverScene(GameManager* _gm01) : Scene(_gm01)
    {
        // juego sobre texto
        auto gameOverText =
            std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "GAME OVER USFX");
        gameOverText->setSize(static_cast<int>(gameManager->getWindowWidth() / 3.0f),
            static_cast<int>(gameManager->getWindowHeight() / 20.0f));
        gameOverText->setPosition(
            static_cast<int>(gameManager->getWindowWidth() / 2.0f - gameOverText->getWidth() / 2.0f),
            static_cast<int>(gameManager->getWindowHeight() / 2.0f - gameOverText->getHeight() / 2.0f));
        addObject(gameOverText);
    }

    void GameOverScene::update(const unsigned int delta)
    {
        untilNextSceneTimer += delta;
        if (untilNextSceneTimer >= sceneTimer)
        {
            untilNextSceneTimer = 0;
            gameManager->getSceneManager()->activateScene("menu");
        }
    }

