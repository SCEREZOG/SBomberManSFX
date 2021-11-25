#ifndef _BOMBERMAN_ENTITIES_ENEMY_H_
#define _BOMBERMAN_ENTITIES_ENEMY_H_

#include <utility>

#include "../Entities/GameActor.h"
#include "../GameAITypes.h"

class Enemy : public GameActor
{
    public:

    Enemy(std::shared_ptr<SDL_Texture> texture, SDL_Renderer* renderer);

    void moveTo(const int x, const int y);

    void moveToCell(std::pair<int, int> pathToCell);

    bool isMovingToCell() const;

    bool canAttack() const;

    int getAttackRadius() const;

    void setAIType(AIType type);

    virtual void update(const unsigned int delta) override;

    void generateNewPath();

    private:

    void updateMovement(const unsigned int delta);

    // movement
    int newPositionX = 0;      // position X to move
    int newPositionY = 0;      // position Y to move
    bool movingToCell = false; // is moving to cell
    std::pair<int, int> path;  // diff of cells to move
    // AI
    AIType aiType = AIType::wandering; // AI type
    // consts
    const float baseSpeed = 0.0018f;    // speed of enemy
    const float attackSpeed = 0.0025f;   // speed of attack enemy
    const int attackRadius = 4;         // attack radius (in cells)
    // animations
    std::shared_ptr<Animation> movement; // movement animation
};

#endif // _BOMBERMAN_ENTITIES_ENEMY_H_
