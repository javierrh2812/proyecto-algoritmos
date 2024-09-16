#pragma once
#include "Recurso.h"
class Residuo : public Recurso
{
protected:
public:
	Residuo() : Recurso() {};
	Residuo(int x, int y) : Recurso(x, y) {};
	~Residuo() {};

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void dibujar()
	{
		Console::SetCursorPosition(x, y); cout << "#";
	}

	void disparar() {
		while (x < 99) {
			x++;
			_sleep(50);			
			dibujar();
			borrar();
		}
	}
};
