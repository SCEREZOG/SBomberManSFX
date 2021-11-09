

#include <SDL.h>
#include <memory>

#include "Text.h"
#include "Scene.h"


    /**
     * @breve escena de finalización del juego
     *
     */
    class GameOverScene : public Scene
    {
    public:
        /**
         * @breve Construye una nueva escena de Game Over
         *
         * @juego de param
         */
        GameOverScene(GameManager* gameManager);
        /**
         * @Disparador breve al actualizar si la escena está activa
         * @param delta - tiempo en milisegundos
         */
        virtual void update(const unsigned int delta) override;

    private:
        // temporizador hasta cambiar al siguiente menú
        int untilNextSceneTimer = 0;
        // constante
        const int sceneTimer = 2000;
    };

