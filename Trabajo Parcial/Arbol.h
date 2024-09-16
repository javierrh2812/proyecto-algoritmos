#pragma once
#include "Header.h"
class Arbol 
{
protected:
	int x;
	int y;
public:
	Arbol() {};
	Arbol(int x, int y){
		this->x = x;
		this->y = y;
	};
	~Arbol() {};

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void dibujar()
	{
		Console::SetCursorPosition(x, y); cout << "Y";
	}
};
