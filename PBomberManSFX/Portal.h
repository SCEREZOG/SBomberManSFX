#pragma once
class Portal
{
private:
	int anchoPortal;
	int altoPortal;
	int posicionX;
	int posicionY;

public:
	int getAnchoPortal() { return anchoPortal; }
	void setAnchoPortal(int _anchoPortal) { anchoPortal = _anchoPortal; }

	int getAltoPortal() { return altoPortal; }
	void setAltoPortal(int _altoPortal) { altoPortal = _altoPortal; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	void PosicionInicialDeBomberMan();
};

