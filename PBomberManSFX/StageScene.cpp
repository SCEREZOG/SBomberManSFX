#ifndef _BOMBERMAN_SCENES_STAGE_SCENE_H_
#define _BOMBERMAN_SCENES_STAGE_SCENE_H_

#include "GameManager.h"
//#include "LevelScene.h"
#include "MenuScene.h"
#include "StageScene.h"
#include "AssetManager.h"



    StageScene::StageScene(GameManager * _gm01, const unsigned int level, const unsigned int _score)
        : Scene(_gm01), stage(level), score(_score)
    {
        // stage text
        auto text = std::make_shared<Text>(gm01->getAssetManager()->getFont(), gm01->getRenderer(),
            "STAGE " + std::to_string(level));
        text->setSize(static_cast<int>(gm01->getWindowWidth() / 3.0f),
            static_cast<int>(gm01->getWindowHeight() / 20.0f));
        text->setPosition(static_cast<int>(gm01->getWindowWidth() / 2.0f - text->getWidth() / 2.0f),
            static_cast<int>(gm01->getWindowHeight() / 2.0f - text->getHeight() / 2.0f));
        addObject(text);
    }

    void StageScene::update(const unsigned int delta)
    {
        untilNextSceneTimer += delta;
        if (untilNextSceneTimer >= sceneTimer)
        {
            untilNextSceneTimer = 0;
           /* gm01->getSceneManager()->addScene("level", std::make_shared<LevelScene>(gm01, stage, score));*/
            gm01->getSceneManager()->activateScene("level");
            gm01->getSceneManager()->removeScene("stage");
        }
    }

#endif // _BOMBERMAN_SCENES_STAGE_SCENE_H_
