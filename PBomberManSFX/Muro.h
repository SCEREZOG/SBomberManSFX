#pragma once
class Muro
{
private:
	int anchoMuro;
	int altoMuro;
	int posicionX;
	int posicionY;

public:
	int getAnchoMuro() { return anchoMuro; }
	void setAnchoMuro(int _anchoMuro) { anchoMuro = _anchoMuro; }

	int getAltoMuro() { return altoMuro; }
	void setAltoMuro(int _altoMuro) { altoMuro = _altoMuro; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }


};

