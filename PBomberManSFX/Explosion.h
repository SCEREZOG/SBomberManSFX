#pragma once

class Explosion {
private:
	int anchoExplosion;
	int altoExplosion;
	int posicionX;
	int posicionY;
	int tiempo;
public:
	int getAnchoExplosion() { return anchoExplosion; }
	void setAnchoExplosion(int _anchoExplosion) { anchoExplosion = _anchoExplosion; }

	int getAltoExplosion() { return altoExplosion; }
	void setAltoExplosion(int _altoExplosion) { altoExplosion = _altoExplosion; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	int getTiempo() { return tiempo; }
	void setTiempo(int _tiempo) { tiempo = _tiempo; }

	void RangoDeDaño();

};
