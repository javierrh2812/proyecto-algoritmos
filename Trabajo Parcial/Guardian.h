#pragma once
#include "Personaje.h"
#include "Header.h"
#include "Recurso.h"
#include "Semilla.h"
#include "Agua.h"
#include "Residuo.h"

class Guardian : public Personaje
{
protected:
	int nroArboles;
	int litrosAgua;
	int nroSemillas;
	int nroResiduos;
public:
	Guardian(int x, int y, int vidas) : Personaje(x, y, vidas) {
		this->nroArboles = 0;
		this->litrosAgua = 0;
		this->nroSemillas = 0;
		this->nroResiduos = 0;
	}
	~Guardian() {}
	int getNroArboles() {
		return this->nroArboles;
	}
	void mover(int tecla)
	{
		borrar();

		switch (tecla)
		{
		case IZQUIERDA:
			if (this->x > 2) this->x--;
			break;
		case DERECHA:
			if (this->x < 99) this->x++;
			break;
		case ABAJO:
			if (this->y < 39) this->y++;
			break;

		case ARRIBA:
			if (this->y > 1) this->y--;
			break;
		}

		dibujar();
	}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void dibujar()
	{
		Console::ForegroundColor = ConsoleColor::DarkMagenta; Console::SetCursorPosition(x, y); cout << "@";
	}

	void recolectar(Recurso* r) {
		if (typeid(*r) == typeid(Semilla)) {
			this->nroSemillas++;
		}
		else if (typeid(*r) == typeid(Agua)) {
			this->litrosAgua++;
		}
		else if (typeid(*r) == typeid(Residuo)) {
			this->nroResiduos++;
		}
	};
	Semilla* sembrar(char tecla) {
		if (this->nroSemillas > 0) {
			nroSemillas--;
			Semilla* semilla = new Semilla(this->x + 1, this->y + 1);
			mostrarIndicadores();
			return semilla;
		}
		return nullptr;
	}
	Agua* regar(char tecla) {
		if (this->litrosAgua > 0) {
			litrosAgua--;
			Agua* agua = new Agua(this->x + 1, this->y + 1);
			mostrarIndicadores();
			return agua;
		}
		return nullptr;
	}
	void disparar(char tecla)
	{
		if (this->nroResiduos > 0) {
			nroResiduos--;
			mostrarIndicadores();
			Residuo* residuo = new Residuo(this->x + 1, this->y);
			residuo->disparar();

		}
	}

	void mostrarIndicadores() {
		Console::SetCursorPosition(5, 38); cout << "VIDAS <3:" << vidas;
		Console::SetCursorPosition(28, 38); cout << "AGUA ~:" << litrosAgua;
		Console::SetCursorPosition(55, 38); cout << "SEMILLAS *:" << nroSemillas;
		Console::SetCursorPosition(78, 38);	cout << "RESIDUOS #:" << nroResiduos;
	}
};
