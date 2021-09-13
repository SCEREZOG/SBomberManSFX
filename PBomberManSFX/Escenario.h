#pragma once
class Escenario
{
private:
	int anchoEscenario;
	int altoEscenario;
public:
	int getAnchoEscenario() { return anchoEscenario; }
	void setAnchoEscenario(int _anchoEscenario) { anchoEscenario = _anchoEscenario; }

	int getAltoEscenario() { return altoEscenario; }
	void setAltoEscenario(int _altoEscenario) { altoEscenario = _altoEscenario; }

	void Tiempo();

	
};

