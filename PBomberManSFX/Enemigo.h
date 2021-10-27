#pragma once
#include"GameActor.h"
#include "iostream"

using namespace std;

class Enemigo : public GameActor
{
protected:
    int p;
public:
    Enemigo(Texture* _textura, Tile* _tileActual);
    void setTileActual(Tile* _tileNuevo);

    //bool tratarDeMover(MoveDirection _direccionNueva);

  /*  void update();*/

};

