
#include <iostream>

#include "SceneManager.h"

          
                SceneManager::SceneManager() {}

                void SceneManager::addScene(const std::string& name, const std::shared_ptr<Scene> scene)
                {
                    const auto it = scenes.find(name);
                    if (it != scenes.end() && it->second)
                    {
                        std::cout << "SceneManager::addScene - scene '" << name << "' already exist in scene tree!"
                            << std::endl;
                        return;
                    }
                    scenes[name] = std::move(scene);
                }

                void SceneManager::activateScene(const std::string& name)
                {
                    //intenta encontrar la escena por su nombre
                    const auto it = scenes.find(name);
                    if (it != scenes.end())
                    {
                        if (currentScene)
                        {
                            currentScene->onExit();
                        }
                        currentScene = it->second;
                        currentScene->onEnter();
                    }
                    else
                    {
                        std::cout << "SceneManager::activateScene - scene '" << name << "' doesn't exist!" << std::endl;
                    }
                }

                void SceneManager::removeScene(const std::string& name)
                {
                    //intenta encontrar la escena por su nombre
                    const auto it = scenes.find(name);
                    if (it != scenes.end())
                    {
                        if (it->second == currentScene)
                        {
                            currentScene->onExit();
                            currentScene = nullptr;
                        }
                        //agregar a la cola para su posterior eliminación en la actualización
                        removedScenes.push(it->second);
                        scenes.erase(name);
                    }
                    else
                    {
                        std::cout << "SceneManager::activateScene - scene '" << name << "' doesn't exist!" << std::endl;
                    }
                }

                void SceneManager::onEvent(const SDL_Event& event)
                {
                    currentScene->onEvent(event);
                }

                void SceneManager::update(const unsigned int delta)
                {
                    //finalmente eliminar escenas eliminadas
                    while (removedScenes.size() > 0)
                    {
                        removedScenes.pop();
                    }

                    currentScene->update(delta);
                }

                void SceneManager::render() 
                {
                    currentScene->render();
                }
         
