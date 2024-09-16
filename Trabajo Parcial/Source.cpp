#include "Header.h"
#include "Guardian.h"
#include"Partida.h"

void menu() {

}
int main()
{
	srand(time(NULL));
	Partida *partida = new Partida();
	partida->dibujar();
	while (true) {
		if (_kbhit()) {
			char tecla = _getch();
			partida->moverGuardian(tecla);
			partida->sembrarGuardian(tecla);
			partida->regarGuardian(tecla);
			partida->dispararGuardian(tecla);
		}
		partida->colision();
	}
	system("pause>0");
}