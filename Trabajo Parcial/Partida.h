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
	int segundos = 80 * 10;
	Menu* menu;
	bool gameOver=false;
	bool youWin = false;
	int villanosEliminados = 0;
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

	int getGameOver() {
		return this->gameOver;
	}

	int getYouWin() {
		return youWin;
	}

	void dibujar(){
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

		guardian->dibujar();
		if (r) {
			if (!r->getRecolectado()) {
				r->borrar();
				guardian->dibujar();
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

	template<typename T>
	string convertAndRemoveLast(T value) {
		string str = to_string(value);
		if (!str.empty()) {
			str.pop_back();
		}
		return str;
	}

	//TODO: cambiar de nombre
	void validarJuego() {

		if (segundos > 0) {
			Console::SetCursorPosition(90, 0);
			cout << "Tiempo: " << convertAndRemoveLast(segundos) << "   ";

			int recursosRecolectados = guardian->obtenerCantidadDeRecursosRecolectados();

			bool esGanador = recursosRecolectados >= 5
				&& guardian->getNroArboles() >= 1
				&& guardian->getVillanosEliminados() >= 1;

			if (esGanador) {
				handleYouWin();
			}
			segundos--;
		}
		if (segundos == 0 || guardian->getVidas()==0 ) {
			handleGameOver();
		}
	}

	void handleYouWin() {
		Console::Clear();
		Console::SetCursorPosition(0, 0);
		youWin = true;
		cout << 
			"                                      __          \n"
			"   _________    ____ _____    _______/  |_  ____  \n"
			"  / ___\\__  \\  /    \\\\__  \\  /  ___/\\   __\\/ __ \\ \n"
			" / /_/  > __ \\|   |  \\/ __ \\_\\___ \\  |  | \\  ___/ \n"
			" \\___  (____  /___|  (____  /____  > |__|  \\___  >\n"
			"/_____/     \\/     \\/     \\/     \\/            \\/ \n";		
		_sleep(2000);

	}

	void handleGameOver() {
		Console::Clear();
		Console::SetCursorPosition(0, 0);
		gameOver = true;
		std::cout << "   _________    _____   ____     _______  __ ___________ \n"
			"  / ___\\__  \\  /     \\_/ __ \\   /  _ \\  \\/ // __ \\_  __ \\\n"
			" / /_/  > __ \\|  Y Y  \\  ___/  (  <_> )   /\\  ___/|  | \\/\n"
			" \\___  (____  /__|_|  /\\___  >  \\____/ \\_/  \\___  >__|   \n"
			"/_____/     \\/      \\/     \\/                   \\/       \n";

		_sleep(2000);

	}

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
				this->villanosEliminados++;
			}
		}
		return nullptr;
	}

	bool colisionResiduoConVillano(Residuo *r) {
		for (int i = 0; i < 7; i++) {
			Villano* v = villanos[i];
			bool colisionX = r->getX()-1 == v->getX();
			bool colisionY = r->getY() == v->getY();

			if (colisionX && colisionY) {
				guardian->agregarVillanoEliminado();
				return true;
			}
		}
		return false;
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
							Arbol *arbol = semillasSembradas[i]->regar();
							if (arbol) {
								this->guardian->agregarArbol();
							}
						}
					}
				}
			}
		}
	}

	void dispararGuardian(char tecla) {
		if (tecla == 'D') {
			Residuo *r = guardian->disparar();
			guardian->dibujar();
			do {
				r->dibujar();
				_sleep(50);
				r->borrar();
				r->setX(r->getX() + 1);
			} while (r->getX() < 99 && !colisionResiduoConVillano(r));
		}
	}
};
