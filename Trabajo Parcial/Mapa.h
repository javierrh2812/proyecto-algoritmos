#pragma once 
#include"Header.h"
#include"Recurso.h"
#include"Agua.h"
#include"Semilla.h"
#include"Residuo.h"

class Mapa
{
protected:
	int x;
	int y;
public:
	Mapa(int x, int y) {
		this->x = x;
		this->y = y;
	};
	~Mapa() {};
	void setX() { this->x = x; }
	int getX() { return this->x; }
	void setY(int y) { this->y = y; }
	int getY() { return this->y; }
	void dibujar()
	{
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				for (int k = 36; k < 40; k++)
				{
					Console::SetCursorPosition(i, 0); cout << "=";
					Console::SetCursorPosition(0, j); cout << "|";
					Console::SetCursorPosition(100, j); cout << "|";
					Console::SetCursorPosition(25, k); cout << "|";
					Console::SetCursorPosition(50, k); cout << "|";
					Console::SetCursorPosition(75, k); cout << "|";
					Console::SetCursorPosition(i, 36); cout << "=";
					Console::SetCursorPosition(i, 40); cout << "=";
				}
			}
		}
		
	};
};
