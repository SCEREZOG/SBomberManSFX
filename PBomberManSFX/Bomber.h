#pragma once
class Bomber
{
private:
	int anchoAvatar;
	int altoAvatar;
	int posicionX;
	int posicionY;
	int bomba;
public:

    int getAnchoAvatar() { return anchoAvatar; }
	void setAnchoAvatar(int _anchoAvatar) { anchoAvatar = _anchoAvatar;}

	int getAltoAvatar() { return altoAvatar; }
	void setAltoAvatar(int _altoAvatar) { altoAvatar = _altoAvatar; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	int getBomba() { return bomba; }
	void setBomba(int _bomba) { bomba = _bomba;}

	void Morir();
	void Correr();
	void Mover();
	void ColocarBomba();
	void ActivarBomba();
	void Vida();
	void Puntaje();

};

