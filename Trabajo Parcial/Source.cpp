#include "Header.h"
#include "Guardian.h"
#include "Partida.h"
#include"Menu.h"
int juego()
{
	srand(time(NULL));
	Partida* partida = new Partida();
	partida->dibujar();
	partida->moverGuardian(1);

	while (partida->getGameOver()==false && partida->getYouWin()==false) {
		if (_kbhit()) {
			char tecla = _getch();
			partida->moverGuardian(tecla);
			partida->sembrarGuardian(tecla);
			partida->regarGuardian(tecla);
			partida->dispararGuardian(tecla);
		}
		else {
			_sleep(100);
			partida->mostrarTiempo();
			partida->colision();
		}
	}

	return 0;
}

int main()
{
	int tecla, opcion, oa, oe;
	Menu* menu = new Menu(tecla, opcion, oa, oe);
	while (true) {
		menu->ventana();
		int Opcion = menu->Iniciar_Menu();
		srand(time(NULL));
		if (Opcion == 1)
		{
			system("cls");
			juego();

		}
		else  if (Opcion == 2)
		{
			system("cls");
			menu->Tutorial();
			system("pause>0");
		}
		else  if (Opcion == 3)
		{
			system("cls");
			menu->Creditos();
			system("pause>0");
		}
		else  if (Opcion == 4) {
			// Salir del juego
			menu->Salir();
			break;
		}
	}
	return 0;

}