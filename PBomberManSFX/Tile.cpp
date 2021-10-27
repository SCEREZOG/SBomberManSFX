#include "Tile.h"
Tile::Tile()
{
	posicionTileX = 0;
	posicionTileY = 0;
	bomberman = nullptr;

	bombermanRobot = nullptr;

	muroCeramica = nullptr;
	muroMetal = nullptr;
	sueloCesped = nullptr;

	enemigo = nullptr;
}

Tile::Tile(int _posicionTileX, int _posicionTileY)
{
	posicionTileX = _posicionTileX;
	posicionTileY = _posicionTileY;
	bomberman = nullptr;

	bombermanRobot = nullptr;

	muroCeramica = nullptr;
	muroMetal = nullptr;
	sueloCesped = nullptr;

	enemigo = nullptr;
}