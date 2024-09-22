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
	int villanosEliminados;
public:
	Guardian(int x, int y, int vidas) : Personaje(x, y, vidas) {
		this->nroArboles = 0;
		this->litrosAgua = 0;
		this->nroSemillas = 0;
		this->nroResiduos = 0;
		this->villanosEliminados= 0;
	}
	~Guardian() {}
	int getNroArboles() {
		return this->nroArboles;
	}
	void agregarArbol() {
		this->nroArboles++;
		mostrarIndicadores();
	}

	void agregarVillanoEliminado() {
		this->villanosEliminados++;
		mostrarIndicadores();
	}
	int getVillanosEliminados() {
		return this->villanosEliminados;
	}
	void mover(int tecla)
	{
		borrar();

		switch (tecla)
		{
		case IZQUIERDA:
		case IZQUIERDA_LETRA:
			if (this->x > 2) this->x--;
			break;
		case DERECHA:
		case DERECHA_LETRA:
			if (this->x < 99) this->x++;
			break;
		case ABAJO:
		case ABAJO_LETRA:
			if (this->y < 39) this->y++;
			break;

		case ARRIBA:
		case ARRIBA_LETRA:
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
		Console::ForegroundColor = ConsoleColor::DarkMagenta; 
		Console::SetCursorPosition(x, y); cout << "@";
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

	int obtenerCantidadDeRecursosRecolectados() {
		return this->nroSemillas + this->litrosAgua + this->nroResiduos;
	}
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
	Residuo *disparar()
	{
		if (this->nroResiduos > 0) {
			nroResiduos--;
			mostrarIndicadores();
			Residuo* residuo = new Residuo(this->x + 1, this->y);
			return residuo;
		}
		else return nullptr;
	}

	void mostrarIndicadores() {
		Console::ForegroundColor = ConsoleColor::DarkRed; 
		Console::SetCursorPosition(x, y); cout << "*"; 
		Console::SetCursorPosition(5, 38); cout << "VIDAS <3:" << vidas;

		Console::ForegroundColor = ConsoleColor::Cyan; 
		Console::SetCursorPosition(x, y); cout << "*"; 
		Console::SetCursorPosition(20, 38); cout << "AGUA ~:" << litrosAgua;

		Console::ForegroundColor = ConsoleColor::Green; 
		Console::SetCursorPosition(x, y); cout << "*"; 
		Console::SetCursorPosition(35, 38); cout << "SEMILLAS *:" << nroSemillas;

		Console::ForegroundColor = ConsoleColor::DarkYellow; 
		Console::SetCursorPosition(x, y); cout << "*"; 
		Console::SetCursorPosition(50, 38);	cout << "RESIDUOS #:" << nroResiduos;

		Console::SetCursorPosition(65, 38); cout << "ARBOLES Y:" << nroArboles;

		Console::SetCursorPosition(80, 38); cout << "VILLANOS ELIM." << villanosEliminados;
	}
};
