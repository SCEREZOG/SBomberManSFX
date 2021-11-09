
#ifndef _BOMBERMAN_LEVEL_SCENE_H_
#define _BOMBERMAN_LEVEL_SCENE_H_

#include <SDL.h>
#include <memory>
#include <utility>
#include <vector>

//#include "../Const.h"
//
//#include "../Entities/Enemy.h"
//#include "../Entities/Music.h"
//#include "../Entities/Player.h"
//#include "Sound.h"
#include "Text.h"
#include "Scene.h"
namespace bomberman
{
    /**
     * @breve escena de nivel
     *
     */
    class LevelScene : public Scene
    {
    public:
        /**
         * @breve Construye una nueva escena de nivel
         *
         * @juego de param - puntero del juego
         * @etapa de parámetro - número de etapa
         */
        LevelScene(GameManager* gameManager, const unsigned int stage, const unsigned int prevScore);
        /**
         * @breves eventos de captura de SDL2
         *
         * @evento param - evento SDL2
         */
        virtual void onEvent(const SDL_Event& event) override;
        /**
         * @breve escena de nivel de actualización
         *
         * @param delta: tiempo delta desde la actualización anterior en milisegundos
         */
        virtual void update(const unsigned int delta) override;

    private:
        //generación y generación de objetos de mapa
        void spawnTextObjects();
        void generateTileMap();
        void generateEnemies();
        void spawnGrass(const int positionX, const int positionY);
        void spawnBrick(const int positionX, const int positionY);
        void spawnStone(const int positionX, const int positionY);
        void spawnPlayer(const int positionX, const int positionY);
      /*  void spawnEnemy(Texture texture, AIType type, const int positionX, const int positionY);
        void spawnBomb(Object* object);
        void spawnBang(Object* object);
        void spawnDoor(Object* object);*/

        /**
         * @breve nivel de finalización
         *
         */
        void finish() const;
        /**
         * @breve juego terminado
         *
         */
        void gameOver();
        /**
         * @breve nivel de salida
         *
         */
        void exit() const;

        // actualización de temporizadores
        void updateTimers(const unsigned int delta);
        void updateLevelTimer();
        void updateBombTimer(const unsigned int delta);
        void updateBangTimer(const unsigned int delta);
        void updateGameOverTimer(const unsigned int delta);
        // actualizar movimiento
        void updateMovement(const bool isPressed, const int keycode);
        //actualizar la cámara
        void updateCamera();
        //actualización de la puntuación
        void updateScore();
        //actualizar colisiones
        void updatePlayerCollision();
        void updateEnemiesCollision();
        void updateBangsCollision();
        bool isCollisionDetected(const SDL_Rect& rect1, const SDL_Rect& rect2) const;
        // destruir ladrillo
        void destroyBrick(std::shared_ptr<GameObject> brick);
        // el enemigo sigue al jugador si está en el radio de ataque
    /*    void followToPlayer(Enemy* enemy);*/

        // temporizadores en ms const
        const int levelTimerStart = 200500;
        const int levelTimerUpdateText = 1000;
        const int bombTimerStart = 1500;
        const int bangTimerStart = 800;
        const int gameOverTimerStart = 1000;
        const int winTimerStart = 200;
        //constante para la puntuación
        const unsigned int scoreRewardForKill = 200;
        const unsigned int scoreRewardForStage = 1000;

        ////std::shared_ptr<Music> menuMusic = nullptr;                       // musica de menu
        ////std::shared_ptr<Sound> gameoverSound = nullptr;                   //juego sobre sonido
        ////std::shared_ptr<Sound> winSound = nullptr;                        //ganar sonido
        ////std::shared_ptr<Sound> explosionSound = nullptr;                  //sonido de explosión
        //std::shared_ptr<Text> timerNumber = nullptr;                      //Temporizador
        //std::shared_ptr<Text> scoreNumber = nullptr;                      // puntaje
        ///*std::shared_ptr<Player> player = nullptr;    */                     // jugador
        ////std::shared_ptr<Sprite> bomb = nullptr;                           // bomba del jugador
        ////std::shared_ptr<Sprite> door = nullptr;                           // puerta para acabado nivelado
        //std::vector<std::shared_ptr<Enemy>> enemies;                      // enemigos
        //std::vector<std::pair<Tile, std::shared_ptr<Object>>> collisions; // colisiones
        //std::vector<std::shared_ptr<Object>> bangs;                       //explosión de la bomba
        //Tile tiles[tileArrayHeight][tileArrayWidth];                      //mapa de mosaico

        int playerDirectionX = 0; // dirección utilizada para el control
        int playerDirectionY = 0; //dirección utilizada para el control
        // variables de temporizador
        int levelTimer = levelTimerStart;
        int levelTimerDelta = 0;
        int bombTimer = 0;
        int bangTimer = 0;
        int gameOverTimer = 0;
        // banderas bool
        bool isGameOver = false;
        bool isPaused = false;
        bool isWin = false;
        //variables
        unsigned int score = 0;
        unsigned int stage = 0;

        // posicionamiento de nivel
        int fieldPositionX = 0;
        int fieldPositionY = 0;
        //tamaño de los azulejos
        int scaledTileSize = 0;
        //último objeto que usó como fondo (pasto)
        int backgroundObjectLastNumber = 0;
    };
} // namespace bomberman

#endif // _BOMBERMAN_LEVEL_SCENE_H_
