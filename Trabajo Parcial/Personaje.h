#pragma once
#include "Header.h"
class Personaje
{
protected:
	int x;
	int y;
	int vidas;
public:
	Personaje(int x, int y, int vidas)
	{
		this->x = x;
		this->y = y;
		this->vidas = vidas;
	}
	virtual ~Personaje() {};
	void setX(int x) { this->x = x; }
	int getX() { return this->x; }
	void setY(int y) { this->y = y; }
	int getY() { return this->y; }
	void setVidas(int v) { this->vidas = v; };
	int getVidas() { return this->vidas; }


	virtual void mover() {};
	virtual void dibujar() {};
	virtual void borrar() {};
};
