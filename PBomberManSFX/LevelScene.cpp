#include <algorithm>
#include <chrono>
#include <functional>
#include <random>
#include <string>

#include "Sprite.h"
#include "GameManager.h"
#include "GameOverScene.h"
#include "LevelScene.h"
//#include "../Scenes/StageScene.h"
//#include "../Util/Pathfinding.h"

namespace bomberman
{
    LevelScene::LevelScene(GameManager* _gameManager, const unsigned int _stage, const unsigned int prevScore)
        : Scene(_gameManager), score(prevScore), stage(_stage)
    {
        // parámetros de campo comunes
        fieldPositionX = 0;
        fieldPositionY = gameManager->getWindowHeight() / 15;
        const float scale =
            (gameManager->getWindowHeight() - fieldPositionY) / static_cast<float>(tileArrayHeight * tileSize);
        scaledTileSize = static_cast<int>(round(scale * tileSize));
        //musica de menu
        //menuMusic = std::make_shared<Music>(game->getAssetManager()->getMusic(MusicEnum::Level));
        //menuMusic->play();
        ////sonidos
        //gameoverSound = std::make_shared<Sound>(game->getAssetManager()->getSound(SoundEnum::Lose));
        //winSound = std::make_shared<Sound>(game->getAssetManager()->getSound(SoundEnum::Win));
        //explosionSound = std::make_shared<Sound>(game->getAssetManager()->getSound(SoundEnum::Explosion));
        //dibujar texto
        spawnTextObjects();
        //generar mapa de mosaicos
        generateTileMap();
        //Preparar jugador
    /*    spawnPlayer(fieldPositionX + playerStartX * scaledTileSize,
            fieldPositionY + playerStartY * scaledTileSize);*/
        //generar enemigos
        generateEnemies();
        //establecer temporizador
        updateLevelTimer();
    }

    void LevelScene::spawnTextObjects()
    {
        const int fontWidth = static_cast<int>(game->getWindowWidth() / 32.0f);
        const int fontHeight = static_cast<int>(game->getWindowHeight() / 30.0f);
        //texto del temporizador
        auto timerText =
            std::make_shared<Text>(game->getAssetManager()->getFont(), game->getRenderer(), "TIME");
        timerText->setSize(fontWidth * 4, fontHeight);
        timerText->setPosition(30, 10);
        timerText->attachToCamera(false);
        addObject(timerText);
        backgroundObjectLastNumber++;

        //// número de temporizador
        //timerNumber = std::make_shared<Text>(game->getAssetManager()->getFont(), game->getRenderer(), "000");
        //timerNumber->setSize(fontWidth * 3, fontHeight);
        //timerNumber->setPosition(timerText->getPositionX() + timerText->getWidth() + 30,
        //    timerText->getPositionY());
        //timerNumber->attachToCamera(false);
        //addObject(timerNumber);
        //backgroundObjectLastNumber++;

        // puntaje
 /*       std::string scoreText = std::to_string(score);
        scoreNumber =
            std::make_shared<Text>(game->getAssetManager()->getFont(), game->getRenderer(), scoreText);
        scoreNumber->setSize(fontWidth * static_cast<int>(scoreText.size()), fontHeight);
        scoreNumber->setPosition(
            static_cast<int>(game->getWindowWidth() / 2.0f - scoreNumber->getWidth() / 2.0f),
            timerText->getPositionY());
        scoreNumber->attachToCamera(false);
        addObject(scoreNumber);
        backgroundObjectLastNumber++;*/

        // escenario
        std::string stageTextConv = "STAGE " + std::to_string(stage);
        auto stageText =
            std::make_shared<Text>(game->getAssetManager()->getFont(), game->getRenderer(), stageTextConv);
        stageText->setSize(fontWidth * static_cast<int>(stageTextConv.size()), fontHeight);
        stageText->setPosition(game->getWindowWidth() - 30 - stageText->getWidth(),
            timerText->getPositionY());
        stageText->attachToCamera(false);
        addObject(stageText);
        backgroundObjectLastNumber++;
    }

    void LevelScene::generateTileMap()
    {
        // Nosotros necesitamos ladrillos al azar
     /*   const auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        auto randBrick = std::bind(std::uniform_int_distribution<int>(0, brickSpawnRandomize),
            std::mt19937(static_cast<unsigned int>(seed)));*/

        // iterar cada mosaico
        //for (int i = 0; i < static_cast<int>(tileArrayHeight); i++)
        //{
        //    for (int j = 0; j < static_cast<int>(tileArrayWidth); j++)
        //    {
        //        tiles[i][j] = baseTiles[i][j];
        //        // generar ladrillos aleatorios
        //        if (tiles[i][j] == Tile::Grass)
        //        {
        //            if (randBrick() == 0)
        //            {
        //                tiles[i][j] = Tile::Brick;
        //            }
        //        }
        //        // desove de ladrillo y hierba
        //        if (tiles[i][j] == Tile::Brick)
        //        {
        //            spawnGrass(fieldPositionX + j * scaledTileSize, fieldPositionY + i * scaledTileSize);
        //            spawnBrick(fieldPositionX + j * scaledTileSize, fieldPositionY + i * scaledTileSize);
        //        }
        //        // hierba de desove
        //        if (tiles[i][j] == Tile::Grass || tiles[i][j] == Tile::EmptyGrass)
        //        {
        //            spawnGrass(fieldPositionX + j * scaledTileSize, fieldPositionY + i * scaledTileSize);
        //        }
        //        // piedra de desove
        //        if (tiles[i][j] == Tile::Stone)
        //        {
        //            spawnStone(fieldPositionX + j * scaledTileSize, fieldPositionY + i * scaledTileSize);
        //        }
        //    }
        //}
    }

    //void LevelScene::spawnGrass(const int positionX, const int positionY)
    //{
    //    auto grass = std::make_shared<Sprite>(game->getAssetManager()->getTexture(Texture::Grass),
    //        game->getRenderer());
    //    grass->setPosition(positionX, positionY);
    //    grass->setSize(scaledTileSize, scaledTileSize);
    //    addObject(grass);
    //    backgroundObjectLastNumber++;
    //}

    //void LevelScene::spawnBrick(const int positionX, const int positionY)
    //{
    //    auto brick = std::make_shared<Sprite>(game->getAssetManager()->getTexture(Texture::Brick),
    //        game->getRenderer());
    //    brick->setPosition(positionX, positionY);
    //    brick->setSize(scaledTileSize, scaledTileSize);
    //    addObject(brick);
    //    collisions.push_back(std::make_pair(Tile::Brick, brick));
    //}

    //void LevelScene::spawnStone(const int positionX, const int positionY)
    //{
    //    auto stone = std::make_shared<Sprite>(game->getAssetManager()->getTexture(Texture::Stone),
    //        game->getRenderer());
    //    stone->setPosition(positionX, positionY);
    //    stone->setSize(scaledTileSize, scaledTileSize);
    //    addObject(stone);
    //    collisions.push_back(std::make_pair(Tile::Stone, stone));
    //    backgroundObjectLastNumber++;
    //}

    //void LevelScene::spawnPlayer(const int positionX, const int positionY)
    //{
    //    // jugador de desove
    //    player = std::make_unique<Player>(game->getAssetManager()->getTexture(Texture::Player),
    //        game->getRenderer());
    //    player->setPosition(positionX, positionY);
    //    player->setSize(scaledTileSize, scaledTileSize);
    //    player->setClip(tileSize, tileSize, tileSize * 4, 0);
    //    addObject(player);
    //}

    //void LevelScene::spawnEnemy(Texture texture, AIType type, const int positionX, const int positionY)
    //{
    //    auto enemy =
    //        std::make_shared<Enemy>(game->getAssetManager()->getTexture(texture), game->getRenderer());
    //    enemy->setPosition(positionX, positionY);
    //    enemy->setSize(scaledTileSize, scaledTileSize);
    //    enemy->setAIType(type);
    //    addObject(enemy);
    //    enemies.push_back(enemy);
    //}

    //void LevelScene::generateEnemies()
    //{
    //    // necesitamos enemigo en mosaico aleatorio
    //    const auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    //    auto randCount = std::bind(std::uniform_int_distribution<int>(minEnemiesOnLevel, maxEnemiesOnLevel),
    //        std::mt19937(static_cast<unsigned int>(seed)));
    //    auto randType = std::bind(std::uniform_int_distribution<int>(0, 1),
    //        std::mt19937(static_cast<unsigned int>(seed)));
    //    auto randTexture = std::bind(std::uniform_int_distribution<int>(0, 2),
    //        std::mt19937(static_cast<unsigned int>(seed)));
    //    auto randCellX = std::bind(std::uniform_int_distribution<int>(0, tileArrayHeight - 1),
    //        std::mt19937(static_cast<unsigned int>(seed)));
    //    auto randCellY = std::bind(std::uniform_int_distribution<int>(0, tileArrayWidth - 1),
    //        std::mt19937(static_cast<unsigned int>(seed)));
    //    // iniciar enemigos engendrar
    //    for (int i = 0; i < randCount(); i++)
    //    {
    //        // tratar de encontrar baldosas adecuadas
    //        int cellX = randCellX();
    //        int cellY = randCellY();
    //        while (tiles[cellX][cellY] == Tile::Brick || tiles[cellX][cellY] == Tile::Stone ||
    //            tiles[cellX][cellY] == Tile::EmptyGrass)
    //        {
    //            cellX = randCellX();
    //            cellY = randCellY();
    //        }
    //        //engendrar enemigo
    //        int textureRand = randTexture();
    //        spawnEnemy(textureRand == 0 ? Texture::Enemy1 :
    //            (textureRand == 1 ? Texture::Enemy2 : Texture::Enemy3),
    //            randType() == 0 ? AIType::Wandering : AIType::Chasing,
    //            fieldPositionX + cellY * scaledTileSize, fieldPositionY + cellX * scaledTileSize);
    //    }
    //}

    //void LevelScene::spawnBomb(Object* object)
    //{
    //    //solo podemos tener 1 bomba y deberíamos tener un objeto
    //    if (bomb || !object)
    //    {
    //        return;
    //    }
    //    //calcular la posición
    //    int bombPositionX = object->getPositionX();
    //    int bombPositionY = object->getPositionY() - fieldPositionY;
    //    const int bombPositionDiffX = bombPositionX % scaledTileSize;
    //    const int bombPositionDiffY = bombPositionY % scaledTileSize;
    //    //Puso una bomba con fuerza en la celda
    //    bombPositionX = (bombPositionDiffX > scaledTileSize / 2) ?
    //        bombPositionX + scaledTileSize - bombPositionDiffX :
    //        bombPositionX - bombPositionDiffX;
    //    bombPositionY = (bombPositionDiffY > scaledTileSize / 2) ?
    //        bombPositionY + scaledTileSize - bombPositionDiffY :
    //        bombPositionY - bombPositionDiffY;
    //    bombPositionY += fieldPositionY;
    //    //crear bomba en posición
    //    bomb =
    //        std::make_shared<Sprite>(game->getAssetManager()->getTexture(Texture::Bomb), game->getRenderer());
    //    bomb->setSize(scaledTileSize, scaledTileSize);
    //    bomb->setPosition(bombPositionX, bombPositionY);
    //    insertObject(bomb, backgroundObjectLastNumber);
    //    // animación
    //    auto animation = std::make_shared<Animation>();
    //    animation->addAnimationEntity(AnimationEntity(0, 0, tileSize, tileSize));
    //    animation->addAnimationEntity(AnimationEntity(tileSize * 1, 0, tileSize, tileSize));
    //    animation->addAnimationEntity(AnimationEntity(tileSize * 2, 0, tileSize, tileSize));
    //    animation->addAnimationEntity(AnimationEntity(tileSize * 3, 0, tileSize, tileSize));
    //    animation->setSprite(bomb.get());
    //    bomb->addAnimation(animation);
    //    // cambiar a bomba
    //    const int bombCellX = static_cast<int>(
    //        round((bomb->getPositionX() - fieldPositionX) / static_cast<float>(scaledTileSize)));
    //    const int bombCellY = static_cast<int>(
    //        round((bomb->getPositionY() - fieldPositionY) / static_cast<float>(scaledTileSize)));
    //    tiles[bombCellY][bombCellX] = Tile::Bomb;
    //    // temporizador de actualización
    //    bombTimer = bombTimerStart;
    //    animation->play();
    //}

    //void LevelScene::spawnBang(Object* object)
    //{
    //    // cambiar a hierba
    //    const int bombCellX = static_cast<int>(
    //        round((bomb->getPositionX() - fieldPositionX) / static_cast<float>(scaledTileSize)));
    //    const int bombCellY = static_cast<int>(
    //        round((bomb->getPositionY() - fieldPositionY) / static_cast<float>(scaledTileSize)));
    //    tiles[bombCellY][bombCellX] = Tile::Grass;
    //    // crear flequillo en posición
    //    for (unsigned int i = 0; i < bangSpawnCells; i++)
    //    {
    //        auto bang = std::make_shared<Sprite>(game->getAssetManager()->getTexture(Texture::Explosion),
    //            game->getRenderer());
    //        bang->setSize(scaledTileSize, scaledTileSize);
    //        bang->setPosition(object->getPositionX() + bangSpawnPositions[i][0] * scaledTileSize,
    //            object->getPositionY() + bangSpawnPositions[i][1] * scaledTileSize);
    //        addObject(bang);
    //        bangs.push_back(bang);
    //        // cambiar a bang
    //        const int bangCellX = static_cast<int>(
    //            round((bang->getPositionX() - fieldPositionX) / static_cast<float>(scaledTileSize)));
    //        const int bangCellY = static_cast<int>(
    //            round((bang->getPositionY() - fieldPositionY) / static_cast<float>(scaledTileSize)));
    //        tiles[bangCellY][bangCellX] = Tile::Bang;
    //        //animación
    //        auto animation = std::make_shared<Animation>();
    //        for (unsigned int j = 1; j < 12; j++)
    //        {
    //            animation->addAnimationEntity(AnimationEntity(tileSize * j, 0, tileSize, tileSize));
    //        }
    //        animation->setSprite(bang.get());
    //        bang->addAnimation(animation);
    //        animation->play();
    //        explosionSound->play();
    //    }
        // temporizador de actualización
    //    bangTimer = bangTimerStart;
    //}

    //void LevelScene::spawnDoor(Object* object)
    //{
    //    // crear puerta en posición
    //    door =
    //        std::make_shared<Sprite>(game->getAssetManager()->getTexture(Texture::Door), game->getRenderer());
    //    door->setSize(scaledTileSize, scaledTileSize);
    //    door->setPosition(object->getPositionX(), object->getPositionY());
    //    insertObject(door, backgroundObjectLastNumber);
    //}

    void LevelScene::finish() const
    {
        menuMusic->stop();
        if (isWin)
        {
            winSound->play();
            game->getSceneManager()->addScene("stage", std::make_shared<StageScene>(game, stage + 1, score));
            game->getSceneManager()->activateScene("stage");
        }
        else
        {
            gameoverSound->play();
            game->getSceneManager()->activateScene("gameover");
        }
        game->getSceneManager()->removeScene("level");
    }

    void LevelScene::gameOver()
    {
        menuMusic->stop();
        gameOverTimer = gameOverTimerStart;
        isGameOver = true;
    }

    void LevelScene::exit() const
    {
        menuMusic->stop();
        game->getSceneManager()->activateScene("menu");
        game->getSceneManager()->removeScene("level");
    }

    void LevelScene::onEvent(const SDL_Event& event)
    {
        Scene::onEvent(event);
        //Necesitamos actualizar el movimiento si se presionan o sueltan las teclas de movimiento
        if ((event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) && event.key.repeat == 0)
        {
            updateMovement(event.type == SDL_KEYDOWN ? true : false, event.key.keysym.scancode);
        }

        if (event.type == SDL_KEYDOWN)
        {
            //debemos ir al menú principal con la tecla Escape
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                gameOver();
                isWin = false;
                gameOverTimer = winTimerStart;
            }
            // podemos generar una bomba con la prensa espacial
            else if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
            {
                if (!isGameOver)
                {
                    spawnBomb(player.get());
                }
            }
            // podemos pausar un juego presionando la tecla enter
            else if (event.key.keysym.scancode == SDL_SCANCODE_RETURN)
            {
                isPaused = !isPaused;
                if (isPaused)
                {
                    menuMusic->pause();
                }
                else
                {
                    menuMusic->resume();
                }
            }
            // etapa completa trampa
            else if (event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
            {
                gameOver();
                isWin = true;
                score += scoreRewardForStage * 100;
                gameOverTimer = winTimerStart;
            }
        }
    }

    void LevelScene::update(const unsigned int delta)
    {
        // pausa
        if (isPaused)
        {
            return;
        }
        Scene::update(delta);
        //Actualizar colisión del jugador
        updatePlayerCollision();
        //actualizar colisión de enemigos
        updateEnemiesCollision();
        //actualizar colisión de ladrillos
        updateBangsCollision();
        //actualizar la cámara
        updateCamera();
        //actualizar temporizadores
        updateTimers(delta);
    }

    void LevelScene::updateTimers(const unsigned int delta)
    {
        //temporizador de nivel de actualización
        levelTimer -= delta;
        levelTimerDelta += delta;
        if (levelTimerDelta >= levelTimerUpdateText)
        {
            updateLevelTimer();
        }
        //actualizar el temporizador de la bomba
        if (bomb != nullptr)
        {
            updateBombTimer(delta);
        }
        //actualizar el temporizador de explosión
        if (bangs.size() > 0)
        {
            updateBangTimer(delta);
        }
        //actualizar el juego sobre el temporizador
        if (isGameOver)
        {
            updateGameOverTimer(delta);
        }

        //nivel de finalización si el temporizador de nivel es 0
        if (levelTimer <= 0 && !isGameOver)
        {
            gameOver();
            isWin = false;
            gameOverTimer = winTimerStart;
        }
    }

    void LevelScene::updateLevelTimer()
    {
        if (levelTimer < 0)
        {
            return;
        }
        levelTimerDelta = 0;
        const int timeInSec = static_cast<int>(levelTimer / 1000.0f);
        std::string timeString = std::to_string(timeInSec);
        while (timeString.size() < 3)
        {
            timeString = "0" + timeString;
        }
        timerNumber->setText(timeString);
    }

    void LevelScene::updateBombTimer(const unsigned int delta)
    {
        if (bombTimer > 0)
        {
            bombTimer -= delta;
        }
        else
        {
            spawnBang(bomb.get());
            removeObject(bomb);
            bomb = nullptr;
        }
    }

    void LevelScene::updateBangTimer(const unsigned int delta)
    {
        if (bangTimer > 0)
        {
            bangTimer -= delta;
        }
        else
        {
            for (auto& bang : bangs)
            {
                removeObject(bang);
                //cambiar a hierba
                const int bangCellX = static_cast<int>(
                    round((bang->getPositionX() - fieldPositionX) / static_cast<float>(scaledTileSize)));
                const int bangCellY = static_cast<int>(
                    round((bang->getPositionY() - fieldPositionY) / static_cast<float>(scaledTileSize)));
                tiles[bangCellY][bangCellX] = baseTiles[bangCellY][bangCellX];
            }
            bangs.clear();
        }
    }

    void LevelScene::updateGameOverTimer(const unsigned int delta)
    {
        if (gameOverTimer > 0)
        {
            gameOverTimer -= delta;
        }
        else
        {
            finish();
        }
    }

    void LevelScene::updateMovement(const bool isPressed, const int keycode)
    {
        if (player == nullptr)
        {
            return;
        }
        //en la prensa comenzamos el movimiento
        if (isPressed)
        {
            switch (keycode)
            {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
                playerDirectionY -= 1;
                break;
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
                playerDirectionY += 1;
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                playerDirectionX -= 1;
                break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                playerDirectionX += 1;
                break;
            default:
                break;
            }
        }
        //al soltarnos dejamos de movernos
        else
        {
            switch (keycode)
            {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
                playerDirectionY += 1;
                break;
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
                playerDirectionY -= 1;
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                playerDirectionX += 1;
                break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                playerDirectionX -= 1;
                break;
            default:
                break;
            }
        }
        //depende de la tecla presionada elegir la dirección del jugador
        MovementDirection direction = MovementDirection::None;
        if (playerDirectionX != 0)
        {
            if (playerDirectionX > 0)
            {
                direction = MovementDirection::Right;
            }
            else
            {
                direction = MovementDirection::Left;
            }
        }
        else if (playerDirectionY != 0)
        {
            if (playerDirectionY > 0)
            {
                direction = MovementDirection::Down;
            }
            else
            {
                direction = MovementDirection::Up;
            }
        }
        //aplicar dirección
        player->setMovementDirection(direction);
    }

    void LevelScene::updateCamera()
    {
        if (player == nullptr)
        {
            return;
        }
        //constante para comprobar la cámara
        const int screenStart = fieldPositionX;
        const int screenFinish = fieldPositionX + scaledTileSize * static_cast<int>(tileArrayWidth);
        const int screenWidthHalf = game->getWindowWidth() / 2;
        int cameraPositionX = player->getPositionX();
        //comprobar los bordes de la pantalla
        if (cameraPositionX <= screenWidthHalf)
        {
            cameraPositionX = screenStart;
        }
        else if (cameraPositionX + screenWidthHalf >= screenFinish)
        {
            cameraPositionX = screenFinish - game->getWindowWidth();
        }
        else
        {
            cameraPositionX -= screenWidthHalf;
        }
        //hora de mover la cámara
        setCamera(cameraPositionX, 0);
    }

    void LevelScene::updateScore()
    {
        std::string scoreText = std::to_string(score);
        scoreNumber->setText(scoreText);
        scoreNumber->setSize(static_cast<int>(timerNumber->getWidth() / 3.0f) *
            static_cast<int>(scoreText.size()),
            scoreNumber->getHeight());
        scoreNumber->setPosition(game->getWindowWidth() / 2 - scoreNumber->getWidth() / 2,
            scoreNumber->getPositionY());
    }

    void LevelScene::updatePlayerCollision()
    {
        if (player == nullptr)
        {
            return;
        }
        // no hay razón para verificar la colisión si el jugador está inactivo
        if (!player->isMoving())
        {
            return;
        }
        //establezca el ancho en un tamaño más pequeño para un camino más fácil
        SDL_Rect playerRect = player->getRect();
        playerRect.w = static_cast<int>(playerRect.w * 0.5);
        playerRect.h = static_cast<int>(playerRect.h * 0.5);
        // iterar objetos para colisión
        for (const auto& collisionObject : collisions)
        {
            if (isCollisionDetected(playerRect, collisionObject.second->getRect()))
            {
                player->revertLastMove();
            }
        }
        // colisión de puerta
        if (door != nullptr)
        {
            if (isCollisionDetected(playerRect, door->getRect()))
            {
                // comprobar la condición ganadora
                if (!isGameOver && enemies.size() == 0)
                {
                    gameOver();
                    isWin = true;
                    score += scoreRewardForStage;
                    gameOverTimer = winTimerStart;
                }
            }
        }
    }

    void LevelScene::updateEnemiesCollision()
    {
        //iterar enemigos para colisión
        for (const auto& enemy : enemies)
        {
            // iterar dibujables para colisión
            for (const auto& collisionObject : collisions)
            {
                //comprobar la colisión del bloque
                if (isCollisionDetected(enemy->getRect(), collisionObject.second->getRect()))
                {
                    //dejar de moverse en la detección de colisiones
                    enemy->setMoving(false);
                    enemy->revertLastMove();
                }
            }
            // comprobar si hay colisión de bomba
            if (bomb && isCollisionDetected(enemy->getRect(), bomb->getRect()))
            {
                // dejar de moverse en la detección de colisiones
                enemy->setMoving(false);
                enemy->revertLastMove();
            }
            // comprobar la colisión del jugador
            if (player != nullptr)
            {
                // establecer el ancho en un tamaño más pequeño
                SDL_Rect playerRect = player->getRect();
                playerRect.w = static_cast<int>(playerRect.w * 0.2);
                playerRect.h = static_cast<int>(playerRect.h * 0.2);
                if (isCollisionDetected(playerRect, enemy->getRect()))
                {
                    // jugador asesinado por enemigo
                    removeObject(player);
                    player = nullptr;
                    gameOver();
                }
            }
            if (player != nullptr)
            {
                // puede atacar?
                if (!enemy->isMovingToCell() && enemy->canAttack())
                {
                    // comprobar el radio de ataque
                    if (abs(player->getPositionX() + player->getWidth() / 2 - enemy->getPositionX() -
                        enemy->getWidth() / 2) < enemy->getAttackRadius() &&
                        abs(player->getPositionY() + player->getHeight() / 2 - enemy->getPositionY() -
                            enemy->getHeight() / 2) < enemy->getAttackRadius())
                    {
                        // empezar a seguir al jugador
                        followToPlayer(enemy.get());
                    }
                }
            }
        }
    }

    void LevelScene::updateBangsCollision()
    {
        // comprobar si hay colisión explosiva
        for (const auto& bang : bangs)
        {
            // comprobar ladrillos
            auto itCollision = collisions.begin();
            while (itCollision != collisions.end())
            {
                if ((*itCollision).first == Tile::Brick)
                {
                    auto brick = (*itCollision).second;
                    if (isCollisionDetected(brick->getRect(), bang->getRect()))
                    {
                        destroyBrick(brick);
                        // eliminar el ladrillo de la matriz de colisión
                        itCollision = collisions.erase(itCollision);
                        continue;
                    }
                }
                ++itCollision;
            }
            // comprobar enemigos
            auto itEnemies = enemies.begin();
            while (itEnemies != enemies.end())
            {
                SDL_Rect enemyRect = (*itEnemies)->getRect();
                enemyRect.w = static_cast<int>(enemyRect.w * 0.2);
                enemyRect.h = static_cast<int>(enemyRect.h * 0.2);
                if (isCollisionDetected(enemyRect, bang->getRect()))
                {
                    removeObject(*itEnemies);
                    itEnemies = enemies.erase(itEnemies);

                    // enemigo asesinado por bang
                    score += scoreRewardForKill;
                    updateScore();
                    continue;
                }
                ++itEnemies;
            }
            // comprobar jugador
            if (player != nullptr)
            {
                SDL_Rect playerRect = player->getRect();
                playerRect.w = static_cast<int>(playerRect.w * 0.2f);
                playerRect.h = static_cast<int>(playerRect.h * 0.2f);
                if (isCollisionDetected(playerRect, bang->getRect()))
                {
                    removeObject(player);
                    player = nullptr;
                    gameOver();
                }
            }
        }
    }

    bool LevelScene::isCollisionDetected(const SDL_Rect& rect1, const SDL_Rect& rect2) const
    {
        // comprobar si hay colisión
        if (rect1.x + rect1.w / 2 <= rect2.x - rect2.w / 2)
            return false;
        if (rect1.x - rect1.w / 2 >= rect2.x + rect2.w / 2)
            return false;
        if (rect1.y + rect1.h / 2 <= rect2.y - rect2.h / 2)
            return false;
        if (rect1.y - rect1.h / 2 >= rect2.y + rect2.h / 2)
            return false;

        return true;
    }

    void LevelScene::destroyBrick(std::shared_ptr<Object> brick)
    {
        // Nosotros necesitamos puerta si no tenemos
        if (door == nullptr)
        {
            //los ladrillos de la izquierda cuentan
            long bricksCount = std::count_if(collisions.begin(), collisions.end(),
                [](auto collision) { return collision.first == Tile::Brick; });
            // Aleatorio para spawn de puerta
            const auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            auto randDoor = std::bind(std::uniform_int_distribution<int>(0, doorSpawnRandomize),
                std::mt19937(static_cast<unsigned int>(seed)));
            //puerta de generación si podemos
            if (randDoor() == 0 || bricksCount <= 1)
            {
                spawnDoor(brick.get());
            }
        }
        // cambia el ladrillo a pasto y quítalo
        const int brickCellX = static_cast<int>(
            round((brick->getPositionX() - fieldPositionX) / static_cast<float>(scaledTileSize)));
        const int brickCellY = static_cast<int>(
            round((brick->getPositionY() - fieldPositionY) / static_cast<float>(scaledTileSize)));
        tiles[brickCellY][brickCellX] = Tile::Grass;
        removeObject(brick);
    }

    void LevelScene::followToPlayer(Enemy* enemy)
    {
        //muévete a la celda más cercana si el enemigo está deambulando
        if (enemy->isMoving())
        {
            std::pair<int, int> cell = std::make_pair(0, 0);
            enemy->moveToCell(cell);
            return;
        }
        // obtener celdas de criaturas por su posición
        const int playerCellX = static_cast<int>(
            round((player->getPositionX() - fieldPositionX) / static_cast<float>(scaledTileSize)));
        const int playerCellY = static_cast<int>(
            round((player->getPositionY() - fieldPositionY) / static_cast<float>(scaledTileSize)));
        const int enemyCellX = static_cast<int>(
            round((enemy->getPositionX() - fieldPositionX) / static_cast<float>(scaledTileSize)));
        const int enemyCellY = static_cast<int>(
            round((enemy->getPositionY() - fieldPositionY) / static_cast<float>(scaledTileSize)));

        // La fuente es la esquina inferior más a la izquierda
        std::pair<unsigned int, unsigned int> src = std::make_pair(enemyCellY, enemyCellX);

        // El destino es la esquina superior más a la izquierda
        std::pair<unsigned int, unsigned int> dest = std::make_pair(playerCellY, playerCellX);

        //obtener la mejor celda más cercana para seguir
        std::pair<int, int> cell = findBestCell(tiles, src, dest);
        if (cell.first >= 0 && cell.second >= 0)
        {
            cell.first -= src.first;
            cell.second -= src.second;
            enemy->moveToCell(cell);
        }
        else
        {
            enemy->generateNewPath();
        }
    }
} // namespace bomberman
