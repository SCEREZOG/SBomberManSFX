#pragma once
class Bomba
{
private:
	int anchoBomba;
	int altoBomba;
	int posicionX;
	int posicionY;
	int temporizador;
public:
	int getAnchoBomba() { return anchoBomba; }
	void setAnchoBomba(int _anchoBomba) { anchoBomba = _anchoBomba; }

	int getAltoBomba() { return altoBomba; }
	void setAltoBomba(int _altoBomba) { altoBomba = _altoBomba; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	int getTemporizador() { return temporizador; }
	void setTemporizador(int _temporizador) { temporizador = _temporizador; }

	void TiempoDeExplosion();
};


