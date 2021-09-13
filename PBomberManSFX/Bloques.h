#pragma once
class Bloques
{
private:
	int anchoBloques;
	int altoBloques;
	int posicionX;
	int posicionY;
public:
	int getAnchoBloques() { return anchoBloques; }
	void setAnchoBloques(int _anchoBloques) { anchoBloques = _anchoBloques; }

	int getAltoBloques() { return altoBloques; }
	void setAltoBloques(int _altoBloques) { altoBloques = _altoBloques; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	void Colisionador();
};

