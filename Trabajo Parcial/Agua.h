#pragma once
#include "Recurso.h"
class Agua : public Recurso
{
protected:
public:
	Agua() : Recurso() {};
	Agua(int x, int y) : Recurso(x, y) {};
	~Agua() {};

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void dibujar()
	{
		Console::SetCursorPosition(x, y); cout << "~";
	}
};
