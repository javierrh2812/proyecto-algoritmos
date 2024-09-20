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
		for (int i = 0; i < 100; i++) {
			Console::ForegroundColor = ConsoleColor::DarkCyan; Console::SetCursorPosition(i+2, 0); cout << "=";
			Console::ForegroundColor = ConsoleColor::DarkCyan; Console::SetCursorPosition(i, 36); cout << "=";
			Console::ForegroundColor = ConsoleColor::DarkCyan; Console::SetCursorPosition(i+2, 40); cout << "=";
		}

		for (int j = 0; j < 41; j++) {
			Console::ForegroundColor = ConsoleColor::DarkCyan; Console::SetCursorPosition(0, j); cout << "||";
			Console::ForegroundColor = ConsoleColor::DarkCyan; Console::SetCursorPosition(100, j); cout << "||";
		}
		for (int k = 37; k < 40; k++) {
			Console::ForegroundColor = ConsoleColor::DarkCyan; Console::SetCursorPosition(25, k); cout << "||";
			Console::ForegroundColor = ConsoleColor::DarkCyan; Console::SetCursorPosition(50, k); cout << "||";
			Console::ForegroundColor = ConsoleColor::DarkCyan; Console::SetCursorPosition(75, k); cout << "||";
		}
		
	};
};
