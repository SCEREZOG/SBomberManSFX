

#include <memory>
#include <queue>
#include <string>
#include <unordered_map>

#include "Scene.h"


    /**
     * @breve administrador de escena
     *
     */
    class SceneManager
    {
    public:
        /**
         * @breve Construya un nuevo objeto de Scene Manager
         *
         */
        SceneManager();
        /**
         * @Breve añadir escena al gerente
         *
         * @nombre de parámetro - nombre de la escena
         * @escena param - puntero de escena
         */

         //agregar
        void addScene(const std::string& name, std::shared_ptr<Scene> scene);
        /**
         * @breve activar escena por nombre
         * @nombre de parámetro - nombre de la escena
         */

         //activar
        void activateScene(const std::string& name);
        /**
         * @breve eliminar escena por nombre
         *
         * @nombre de parámetro - nombre de la escena
         */

         //eliminar
        void removeScene(const std::string& name);
        /**
         * @breve enviar evento a la escena activa
         *
         * @evento param - evento SDL2
         */

         //en el evento
        void onEvent(const SDL_Event& event);
        /**
         * @breve actualización de la escena activa
         *
         * @param delta - tiempo en milisegundos
         */

         //actualizar
        void update(const unsigned int delta);
        /**
         * @breve dibujar objetos de la escena activa
         *
         */

         //render==dibujar
        void render();

    private:
        std::unordered_map<std::string, std::shared_ptr<Scene>> scenes; //escenas
        std::queue<std::shared_ptr<Scene>> removedScenes;               //escenas eliminadas, para limpiar
        std::shared_ptr<Scene> currentScene = nullptr;                  //escena activa
    };


