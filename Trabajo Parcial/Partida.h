#pragma once
#include "Mapa.h"
#include "Recurso.h"
#include "Semilla.h"
#include "Agua.h"
#include "Residuo.h"
#include "Guardian.h"
#include "Villano.h"
#include "Menu.h"

class Partida
{
protected:
	Recurso* recursos[23];
	Guardian* guardian;
	Mapa* mapa;
	Semilla* semillasSembradas[5];
	Villano* villanos[7];
	Menu* menu;
public: 
	
	Partida() 
	{		
		mapa = new Mapa(0, 0);
		guardian = new Guardian(5, 15, 3);
		for (int i = 0; i < 5; i++) {
			recursos[i] = new Semilla();
		}
		for (int i = 5; i < 20; i++) {
			recursos[i] = new Agua();
		}
		for (int i = 20; i < 23; i++) {
			recursos[i] = new Residuo();
		}
		for (int i = 0; i < 5; i++) {
			semillasSembradas[i] = nullptr;
		}
		for (int i = 0; i < 7; i++) {
			villanos[i] = new Villano();
		}
	}
	~Partida() {}

	void dibujar() {
		mapa->dibujar();
		for (int i = 0; i < 23; i++) {
			if (!recursos[i]->getRecolectado()) {
				recursos[i]->dibujar();
			}
		}
		for (int i = 0; i < 7; i++) {
			if (!villanos[i]->getDerrotado()) {
				villanos[i]->dibujar();
			}
		}
		guardian->mostrarIndicadores();
	}

	void moverGuardian(char tecla) {
		guardian->mover(tecla);
	}

	void colision()
	{
		Recurso* r = reconocerRecurso();
		Villano* v = reconocerVillano();
		if (r) {
			if (!r->getRecolectado()) {
				r->borrar();
				guardian->recolectar(r);
				guardian->mostrarIndicadores();
			}
			r->setRecolectado();
		}
		if (v) {
			if (!v->getDerrotado()) {
				guardian->setVidas(guardian->getVidas() - 1);
				guardian->setX(5);
				guardian->setY(15);
				v->dibujar();
				guardian->mostrarIndicadores();
			}
		}

		return;
	}
<<<<<<< HEAD
	
=======
	void mostrarTiempo() {
		int segundos = 60;
		bool contadorSegundos = true;
		while (contadorSegundos && segundos > 0) {
			Console::SetCursorPosition(90, 0);
			cout << "Tiempo: " << segundos << "   ";
			_sleep(500);

			if (guardian->getNroArboles() >= 10) {
				Console::Clear();
				Console::SetCursorPosition(0, 0);
				cout << "YOU WIN" << endl;
				contadorSegundos = false;
				break;
			}

			int recursosRecolectados = 0;
			for (int i = 0; i < 23; i++) {
				if (recursos[i]->getRecolectado()) {
					recursosRecolectados++;
				}
			}
			if (recursosRecolectados >= 8) {
				Console::Clear();
				Console::SetCursorPosition(0, 0);
				cout << "Game Over" << endl;
				contadorSegundos = false;
				break;
			}

		}

		if (segundos == 0 && contadorSegundos) {
			Console::Clear();
			Console::SetCursorPosition(0, 0);
			cout << "Game Over" << endl;
		}
	}



>>>>>>> #
	Recurso* reconocerRecurso() {
		for (int i = 0; i < 23; i++) {
			Recurso* r = recursos[i];
			bool colisionX = guardian->getX() == r->getX() && guardian->getX() == r->getX();
			bool colisionY = guardian->getY() == r->getY() && guardian->getY() == r->getY();

			if (colisionX && colisionY) {
				return r;
			}
		}
		return nullptr;
	}

	Villano* reconocerVillano() {
		for (int i = 0; i < 7; i++) {
			Villano* v = villanos[i];
			bool colisionX = guardian->getX() == v->getX() && guardian->getX() == v->getX();
			bool colisionY = guardian->getY() == v->getY() && guardian->getY() == v->getY();

			if (colisionX && colisionY) {
				return v;
			}
		}
		return nullptr;
	}

	void agregarSemillaSembrada(Semilla* nuevaSemilla) {
		for (int i = 0; i < 5; ++i) {
			if (semillasSembradas[i] == nullptr) {
				semillasSembradas[i] = nuevaSemilla;
				break;
			}
		}
	}

	void sembrarGuardian(char tecla) {
		if (tecla == 'S') {
			Semilla* semilla = guardian->sembrar(tecla);
			if (semilla) {
				semilla->dibujar();
				agregarSemillaSembrada(semilla);
			}
		}
	}

	void regarGuardian(char tecla) {
		if (tecla == 'R') {
			int regar = 0;
			int xRegar = guardian->getX() + 1;
			int yRegar = guardian->getY() + 1;

			for (int i = 0; i < 5; ++i) {
				if (semillasSembradas[i] != nullptr) {
					if (semillasSembradas[i]->getX() == xRegar && semillasSembradas[i]->getY() == yRegar) {
						Agua* agua = guardian->regar(tecla);
						if (agua) {
							semillasSembradas[i]->regar();
						}
					}
				}
			}
		}
	}

	void dispararGuardian(char tecla) {
		if (tecla == 'D') {
			guardian->disparar(tecla);
		}
	}
};
