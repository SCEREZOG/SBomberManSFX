

#include <SDL.h>
#include <memory>

#include "Text.h"
#include "Scene.h"

    /**
     * @brief Stage Scene
     *
     */
    class StageScene : public Scene
    {
    public:
        /**
         * @brief Construct a new Stage Scene
         *
         * @param game
         */
        StageScene(GameManager* gm01, const unsigned int level, const unsigned int score);
        /**
         * @brief Trigger on update if scene is active
         *
         * @param delta - time in milliseconds
         */
        virtual void update(const unsigned int delta) override;

    private:
        // timer until switch to next menu
        int untilNextSceneTimer = 0;
        // const
        const int sceneTimer = 2000;
        unsigned int stage = 0;
        unsigned int score = 0;
    };



