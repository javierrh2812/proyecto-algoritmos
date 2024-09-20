#pragma once
#include "Personaje.h"
#define DERECHA 77
#define DERECHA_LETRA 108
#define IZQUIERDA 75
#define IZQUIERDA_LETRA 106
#define ARRIBA 72
#define ARRIBA_LETRA 105
#define ABAJO 80
#define ABAJO_LETRA 107
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
        return nroArboles;
    }

    void incrementarNroArboles() {
        nroArboles++;
    }

    void mover(int tecla) {
        borrar();

        switch (tecla)
        {
        case IZQUIERDA:
        case IZQUIERDA_LETRA:
            if (this->x > 1)
            {
                this->x--;
            }
            break;
        case DERECHA:
        case DERECHA_LETRA:
            if (this->x < 99)
            {
                this->x++;
            }
            break;
        case ABAJO:
        case ABAJO_LETRA:
            if (this->y < 39)
            {
                this->y++;
            }
            break;
        case ARRIBA:
        case ARRIBA_LETRA:
            if (this->y > 1)
            {
                this->y--;
            }
            break;
        }
<<<<<<< HEAD

        dibujar();
    }

    void borrar() {
        Console::SetCursorPosition(x, y); cout << " ";
    }

    void dibujar() {
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
    }

    Semilla* sembrar(char tecla) {
        if (this->nroSemillas > 0) {
            nroSemillas--;
            Semilla* semilla = new Semilla(this->x + 1, this->y + 1);
            incrementarNroArboles(); // Incrementa aquí
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

=======

        dibujar();
    }

    void borrar() {
        Console::SetCursorPosition(x, y); cout << " ";
    }

    void dibujar() {
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
    }

    Semilla* sembrar(char tecla) {
        if (this->nroSemillas > 0) {
            nroSemillas--;
            Semilla* semilla = new Semilla(this->x + 1, this->y + 1);
            incrementarNroArboles();
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

>>>>>>> CAMBIOS
    void disparar(char tecla) {
        if (this->nroResiduos > 0) {
            nroResiduos--;
            mostrarIndicadores();
            Residuo* residuo = new Residuo(this->x + 1, this->y);
            residuo->disparar();
        }
    }

	void mostrarIndicadores() {
		Console::ForegroundColor = ConsoleColor::Red; Console::SetCursorPosition(5, 38); cout << "VIDAS <3:"<<vidas;
		Console::ForegroundColor = ConsoleColor::Cyan; Console::SetCursorPosition(28, 38); cout << "AGUA ~:" << litrosAgua;
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(55, 38); cout << "SEMILLAS *:" << nroSemillas;
		Console::ForegroundColor = ConsoleColor::DarkYellow; Console::SetCursorPosition(78, 38);	cout << "RESIDUOS #:" << nroResiduos;
<<<<<<< HEAD
	};
};
    void mostrarIndicadores() {
        Console::ForegroundColor = ConsoleColor::Red; Console::SetCursorPosition(5, 38); cout << "VIDAS <3:" << vidas;
        Console::ForegroundColor = ConsoleColor::Cyan; Console::SetCursorPosition(28, 38); cout << "AGUA ~:" << litrosAgua;
        Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(55, 38); cout << "SEMILLAS *:" << nroSemillas;
        Console::ForegroundColor = ConsoleColor::DarkYellow; Console::SetCursorPosition(78, 38); cout << "RESIDUOS #:" << nroResiduos;
    }
=======
	}
>>>>>>> CAMBIOS
};
