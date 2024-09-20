#pragma once
#include "Personaje.h"

class Villano : public Personaje
{
protected:
	bool derrotado;
public:
	Villano() : Personaje(x, y, vidas) {
		this->x = rand() % 99 + 1;
		this->y = rand() % 35 + 1;
		this->vidas = 1;
		this->derrotado = false;
	}
	~Villano() {};

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void dibujar()
	{
	
		Console::ForegroundColor= ConsoleColor::DarkRed; Console::SetCursorPosition(x, y); cout << "X";
	}
	bool getDerrotado() { return this->derrotado; }
	void setDerrotado() { this->derrotado = true; }
};
