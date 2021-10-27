#pragma once
#include <SDL.h>

//
//#include "Bomberman.h"
//#include "MuroCeramica.h"
//#include "MuroMetal.h"
//#include "SueloCesped.h"

class Bomberman;
class BombermanRobot;
class Enemigo;
class MuroCeramica;
class MuroMetal;
class SueloCesped;

class Tile
{
private:
	Bomberman* bomberman;
	BombermanRobot* bombermanRobot;
	Enemigo* enemigo;
	MuroCeramica* muroCeramica;
	MuroMetal* muroMetal;
	SueloCesped* sueloCesped;

	int posicionTileX;
	int posicionTileY;

public:
	static const int anchoTile = 34;
	static const int altoTile = 34;

	// Constructores y destructores
	Tile();
	Tile(int _posicionTileX, int _posicionTileY);

	// METODOS ACCESORES
	Bomberman* getBomberman() { return bomberman; }
	//
	BombermanRobot* getBombermanRobot() { return bombermanRobot; }
	Enemigo* getEnemigo() { return enemigo; }

	MuroCeramica* getMuroCeramica() { return muroCeramica; }
	MuroMetal* getMuroMetal() { return muroMetal; }
	SueloCesped* getSueloCesped() { return sueloCesped; }
	int getPosicionTileX() { return posicionTileX; }
	int getPosicionTileY() { return posicionTileY; }

	void setBomberman(Bomberman* _bomberman) { bomberman = _bomberman; }

	void setBombermanRobot(BombermanRobot* _bombermanRobot) { bombermanRobot = _bombermanRobot; }
	void setEnemigo(Enemigo* _enemigo) { enemigo = _enemigo; }

	void setMuroCeramica(MuroCeramica* _muroCeramica) { muroCeramica = _muroCeramica; }
	void setMuroMetal(MuroMetal* _muroMetal) { muroMetal = _muroMetal; }
	void setSueloCesped(SueloCesped* _sueloCesped) { sueloCesped = _sueloCesped; }
	void setPosicionTileX(int _posicionTileX) { posicionTileX = _posicionTileX; }
	void setPosicionTileY(int _posicionTileY) { posicionTileY = _posicionTileY; }
};

