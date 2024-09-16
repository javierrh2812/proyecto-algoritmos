#pragma once
#include "Header.h"
class Recurso
{
protected:
	int x;
	int y;
	bool recolectado;
public:
	Recurso(){
		this->x = rand() % 99 + 1;
		this->y = rand() % 35 + 1;
		this->recolectado = false;
	}
	Recurso(int x, int y) {
		this->x = x;
		this->y = y;
		this->recolectado = true;
	}
	virtual ~Recurso() {};
	void setX() { this->x = x; }
	int getX() { return this->x; }
	void setY(int y) { this->y = y; }
	int getY() { return this->y; }
	bool getRecolectado() { return this->recolectado; }
	void setRecolectado() { this->recolectado = true; }
	virtual void dibujar() {};
	virtual void borrar() {};

	virtual void mostrarRecursos() {};
};
