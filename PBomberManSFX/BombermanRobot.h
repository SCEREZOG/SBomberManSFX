#pragma once
#include <iostream>
#include "GamePawn.h"
#include "Bomberman.h"

using namespace std;

class BombermanRobot : public Bomberman
{
private:

public:
	//Constructor
	BombermanRobot(Texture* _textura, Tile* _tileActual);
	//void setTileActual(Tile* _tileNuevo) override;

	//void update();
	//void render();

};

