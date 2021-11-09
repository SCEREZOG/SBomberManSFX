#pragma once

#include <SDL.h>
#include <vector>

#include "Sprite.h"



class GameManager;
/**
 * @clase base de escena breve
 *
 */
class Scene
{
public:
    /**
     * @breve Construye un nuevo objeto Escena
     *
     * @param game - puntero al juego
     */
    Scene(GameManager* gm01);
    /**
     * @breve Destruye el objeto Escena
     */
    virtual ~Scene();
    /**
     * @breve Agregar objeto a la escena para dibujar
     *
     * @objeto param
     */
    void addObject(std::shared_ptr<Sprite> object);
    /**
     * @breve Agregar objeto a la escena para dibujar en una posici�n espec�fica
     *
     * @objeto param
     * @posici�n de par�metro - posici�n donde insertar el objeto
     */
    void insertObject(std::shared_ptr<Sprite> object, int position);
    /**
     * @breve Eliminar objeto de la escena
     *
     * @objeto param
     */
    void removeObject(std::shared_ptr<Sprite> object);
    /**
     * @breve Establecer el objeto de la c�mara en una posici�n espec�fica
     *
     * @param x - posici�n x
     * @param y - posici�n y
     */
    void setCamera(const int x, const int y);
    /**
     * @breve Llamado cuando la escena se activa
     *
     */
    virtual void onEnter();
    /**
     * @breve Llamada cuando la escena se desactiva
     *
     */
    virtual void onExit();
    /**
     * @Disparo breve en evento SDL2 si la escena est� activa
     *
     * @evento param - evento SDL2
     */
    virtual void onEvent(const SDL_Event& event);
    /**
     * @Disparador breve al actualizar si la escena est� activa
     *
     * @param delta - tiempo en milisegundos
     */
    virtual void update(const unsigned int delta);
    /**
     * @breve Dibujar objetos en la pantalla
     *
     */
    void render();

protected:
    GameManager* gm01 = nullptr; // puntero al juego para usar en todas las escenas

private:
    std::vector<std::shared_ptr<Sprite>> objects; // objetos para actualizar y dibujar
    SDL_Rect camera;                              // posici�n de la c�mara
};
// namespace bomberman

// _BOMBERMAN_SCENES_SCENE_H_
