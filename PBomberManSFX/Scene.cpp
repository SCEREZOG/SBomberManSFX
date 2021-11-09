#include <algorithm>

#include "Scene.h"



    Scene::Scene(GameManager* _gm01)
    {
        this->gm01 = _gm01;
        //configurar la cámara en la posición superior izquierda
        camera = { 0, 0, 0, 0 };
    }

    Scene::~Scene() {}

    void Scene::addObject(std::shared_ptr<Sprite> object)  
    {
        objects.push_back(std::move(object));
    }

    void Scene::insertObject(std::shared_ptr<Sprite> object, int position)
    {
        objects.insert(objects.begin() + position, object);
    }

    void Scene::removeObject(std::shared_ptr<Sprite> object)
    {
        objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
    }

    void Scene::setCamera(const int x, const int y)
    {
        camera.x = x;
        camera.y = y;
    }

    void Scene::onEnter() {}

    void Scene::onExit() {}

    void Scene::onEvent(const SDL_Event& /*event*/) {}

    void Scene::update(const unsigned int delta)
    {
        for (auto& Gameobject : objects)
        {
            Gameobject->update(delta);
        }
    }

    void Scene::render()
    {
        for (const auto& Gameobject : objects)
        {
            Gameobject->render(camera);
        }
    }
