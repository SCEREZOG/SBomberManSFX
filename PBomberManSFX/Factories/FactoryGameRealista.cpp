#include "FactoryGameRealista.h"


FactoryGameRealista::FactoryGameRealista() {
    gameManager = GameManager::instance;
    scaledTileSize = 32;
}

std::shared_ptr<GameObject> FactoryGameRealista::CreatePlayer(const int _positionX, const int _positionY)
{
    // spawn player
    auto player = std::make_shared<RealistaPlayer>(gameManager->getAssetManager()->getTexture(Texture::Player_Realista), gameManager->getRenderer());
    player->setPosition(_positionX, _positionY);
    player->setSize(scaledTileSize, scaledTileSize);
    player->setClip(tileSize, tileSize, tileSize * 4, 0);

    return dynamic_pointer_cast<GameObject>(player);
}


std::shared_ptr<GameObject> FactoryGameRealista::CreateEnemy(AIType _type, const int _positionX, const int _positionY)
{
    //shared_ptr<GameObject> enemy(nullptr);
    auto enemy = std::make_shared<RealistaEnemy>(gameManager->getAssetManager()->getTexture(Texture::Enemy1_Realista), gameManager->getRenderer());
    enemy->setPosition(_positionX, _positionY);
    enemy->setSize(scaledTileSize, scaledTileSize);
    enemy->setAIType(_type);

    return dynamic_pointer_cast<GameObject>(enemy);
}

