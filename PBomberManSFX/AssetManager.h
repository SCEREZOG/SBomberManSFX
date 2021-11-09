#ifndef _BOMBERMAN_MANAGERS_ASSET_MANAGER_H_
#define _BOMBERMAN_MANAGERS_ASSET_MANAGER_H_

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <memory>
#include <string>
#include <unordered_map>


    /**
     * @breve enumeración de la textura
     *
     * @ver getTexture
     */
    enum class Texture : int
    {
        MenuBack,
     
    };
    /**
     * @breve enumeración de música
     *
     */
    /*enum class MusicEnum : int
    {
        MainMenu,
        Level
    }*/;
    /**
     * @breve enumeración de sonidos
     *
     */
    /*enum class SoundEnum : int
    {
        Win,
        Lose,
        Explosion
    };*/
    /**
     * @breve Hash para Texture enumeración
     *
     */
    struct EnumClassHash
    {
        template<typename T> std::size_t operator()(T t) const
        {
            return static_cast<std::size_t>(t);
        }
    };

    /**
     * @breve administrador de activos
     *
     */
    class AssetManager
    {
    public:
        /**
         * @activos de carga breve
         *
         * @Renderizador de parámetros - Renderizador SDL2
         */
        void load(SDL_Renderer* renderer);
        /**
         * @breve Obtener fuente
         *
         * @devolver fuente compartida ptr TTF fuente cargada
         */
        std::shared_ptr<TTF_Font> getFont() const;
        /**
         * @breve Obtener texturas
         *
         * @textura de parametro- enumerador de textura
         *
         * @devolver textura SDL ptr compartida> - textura cargada
         */
        std::shared_ptr<SDL_Texture> getTexture(Texture texture);
        /**
         * @breve Obtener música
         *
         * @música de parametro -enumerador de música
         * @devolver música compartida ptr Mix Music cargada
         */
        /*std::shared_ptr<Mix_Music> getMusic(MusicEnum music);*/
        /**
         * @breve Obtener sonido
         *
         * @sonido de  parametro - enumerador de sonido
         * @devolver el sonido cargado compartido ptr Mix Chunk
         */
       /* std::shared_ptr<Mix_Chunk> getSound(SoundEnum sound);*/

    private:
        /**
         * @fuente de carga breve
         *
         */
        void loadFont();
        /**
         * @texturas de carga breve
         *
         * @renderizador de parametro - renderizador SDL2
         * @textura de parametro - enumerador de texturas
         * @Ruta del archivo de parametro - ruta al archivo con textura
         */
        void loadTexture(SDL_Renderer* renderer, Texture texture, const std::string& filePath);
        /**
         * @breve carga de música
         *
         * @música param - enumerador de música
         * @param filePath: ruta al archivo con música
         */
       /* void loadMusic(MusicEnum music, const std::string& filePath);*/
        /**
         * @sonidos de carga breves
         *
         * @param sound - enumerador de sonido
         * @param filePath - ruta al archivo con sonido
         */
        /*void loadSound(SoundEnum sound, const std::string& filePath);*/

        std::shared_ptr<TTF_Font> font = nullptr;                                          // font
        std::unordered_map<Texture, std::shared_ptr<SDL_Texture>, EnumClassHash> textures; // map of textures
        //std::unordered_map<MusicEnum, std::shared_ptr<Mix_Music>, EnumClassHash> musics;       // map of music
        //std::unordered_map<SoundEnum, std::shared_ptr<Mix_Chunk>, EnumClassHash> sounds;       // map of sounds
    };
    //namespace bomberman
#endif // _BOMBERMAN_MANAGERS_ASSET_MANAGER_H_

