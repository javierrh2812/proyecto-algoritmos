#pragma once
#include "Recurso.h"
#include "Arbol.h"

class Semilla : public Recurso
{
protected:
	int vecesRegada;
public:
	Semilla() : Recurso() {};
	Semilla(int x, int y) : Recurso(x, y) {
		this->vecesRegada = 0;
	};
	~Semilla() {};
	
	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void dibujar()
	{
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(x, y); cout << "*";
	}

	void regar() {
		this->vecesRegada++;
		if (this->vecesRegada == 3) {
			Arbol *arbol = new Arbol(this->x, this->y);
			arbol->dibujar();
		}
	}
};
