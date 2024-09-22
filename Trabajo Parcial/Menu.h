#pragma once
#include "Header.h"

class Menu {
private:
	int tecla;
	int opcion;
	int opcionElegida;
	int opcionAnterior;

public:
	Menu(int& Tecla, int& Opcion, int& OpcionElegida, int OpcionAnterior)
		: tecla(Tecla), opcion(Opcion), opcionElegida(OpcionElegida), opcionAnterior(OpcionAnterior) {}

	~Menu() {}

	void ventana() {
		Console::SetWindowSize(100,40);
		Console::Clear();
		Console::CursorVisible = false;
	}

	int Iniciar_Menu() {
		int Opcion = 1;
		int OpcionAnterior = 0;
		int OpcionElejida = 0;
		MostrarTitulo();
		MostrarOpciones();
		while (true) {
			if (_kbhit()) {
				int Tecla = _getch();
				Controles_Menu(Tecla, Opcion, OpcionElejida);
				if (OpcionElejida != 0) {
					return Opcion;
				}
			}
			if (OpcionAnterior != Opcion) {
				actualizarOpcion(Opcion, OpcionAnterior);
				OpcionAnterior = Opcion;
			}
		}
	}

	void Controles_Menu(int& Tecla, int& Opcion, int& OpcionElejida) {
		if (Tecla > 90) Tecla -= 32;
		if (Tecla ==ARRIBA) {
			if (Opcion > 1) {
				Opcion--;
			}
			else {
				Opcion = 4;
			}
		}
		else if (Tecla ==ABAJO) {
			if (Opcion < 4) {
				Opcion++;
			}
		}
		else if (Tecla == SeleccionarZ || Tecla == SeleccionarX || Tecla == SeleccionarEnter) {
			OpcionElejida = Opcion;
		}
	}

	void actualizarOpcion(int opcion, int opcionAnterior) {
		Console::SetCursorPosition(44, 26 + opcion - 1);  
		cout << (char)175;  
		borrarOpcion(opcionAnterior);
	}

	void borrarOpcion(int opcion) {
		Console::SetCursorPosition(44, 26 + opcion - 1);  
		cout << " " ;  
	}

	void MostrarTitulo() {
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(26, 6); cout << "  ________                       .___.__                " << endl;
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(26, 7); cout << " /  _____/ __ _______ _______  __| _/|__|____    ____   " << endl;
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(26, 8); cout << "/   \\  ___|  |  \\__  \\\\_  __ \\/ __ | |  \\__  \\  /    \\  " << endl;
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(26, 9); cout << "\\    \\_\\  \\  |  // __ \\|  | \\/ /_/ | |  |/ __ \\|   |  \\ " << endl;
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(26, 10); cout << " \\______  /____/(____  /__|  \\____ | |__(____  /___|  / " << endl;
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(26, 11); cout << "        \\/           \\/           \\/         \\/     \\/ " << endl;
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(43, 13); cout << "        _____                                            ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(43, 14); cout << "  _____/ ____\\                                           ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(43, 15); cout << " /  _ \\   __\\                                            ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(43, 16); cout << "(  <_> )  |                                              ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(43, 17); cout << " \\____/|__|  ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(30, 19); cout << " _______          __                                    ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(30, 20); cout << " \\      \\ _____ _/  |_ __ _________   ____              ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(30, 21); cout << " /   |   \\\\__  \\\\   __\\  |  \\_  __ \\_/ __ \\             ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(30, 22); cout << "/    |    \\/ __ \\|  | |  |  /|  | \\/\\  ___/             ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(30, 23); cout << "\\____|__  (____  /__| |____/ |__|    \\___  >            ";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(30, 24); cout << "        \\/     \\/                        \\/ ";
	}
	void MostrarOpciones() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(45, 26); cout << "1.  Jugar";
		Console::SetCursorPosition(45, 27); cout << "2.  Tutorial";
		Console::SetCursorPosition(45, 28); cout << "3.  Creditos";
		Console::SetCursorPosition(45, 29); cout << "4.  Salir";
	}
	void Creditos() {



		Console::SetCursorPosition(44, 8); cout << "______  _                _____          __  _                             									   ";
		Console::SetCursorPosition(44, 9); cout << "|  _  \\(_)              /  ___|        / _|(_)                            											   ";
		Console::SetCursorPosition(44, 10); cout << "| | | | _   __ _  ____  \\ `--.   ___  | |_  _   __ _                      								   ";
		Console::SetCursorPosition(44, 11); cout << "| | | || | / _` ||_  /   `--. \\ / _ \\ |  _|| | / _` |                     							   ";
		Console::SetCursorPosition(44, 12); cout << "| |/ / | || (_| | / /   /\\__/ /| (_) || |  | || (_| |                     								   ";
		Console::SetCursorPosition(44, 13); cout << "|___/_ |_| \\__,_|/___|  \\____/  \\___/_|_| _|_| \\__,_|  							   ";

		Console::SetCursorPosition(34, 15); cout << "______       _                     _____  _                            ";
		Console::SetCursorPosition(34, 16); cout << "| ___ \\     | |                   |  ___|| |                           	   ";
		Console::SetCursorPosition(34, 17); cout << "| |_/ /__ _ | | _ __ ___    __ _  | |__  | | _   _  _ __    ___   _ __ 	   ";
		Console::SetCursorPosition(34, 18); cout << "|  __// _` || || '_ ` _ \\  / _` | |  __| | || | | || '_ \\  / _ \\ | '__|  	   ";
		Console::SetCursorPosition(34, 19); cout << "| |  | (_| || || | | | | || (_| | | |___ | || |_| || | | || (_) || |   	   ";
		Console::SetCursorPosition(34, 20); cout << "\\_|   \\__,_||_||_| |_| |_| \\__,_| \\____/ |_| \\__, ||_| |_| \\___/ |_|   	   ";
		Console::SetCursorPosition(34, 21); cout << "                                              __/ |                    	   ";
		Console::SetCursorPosition(34, 22); cout << "                                             |___/   	   ";

		Console::SetCursorPosition(33, 23); cout << "______                                  ___                _              ";
		Console::SetCursorPosition(33, 24); cout << "| ___ \\                                |_  |              (_)             ";
		Console::SetCursorPosition(33, 25); cout << "| |_/ / __ _  _ __ ___    ___   ___      | |  __ _ __   __ _   ___  _ __ ";
		Console::SetCursorPosition(33, 26); cout << "|    / / _` || '_ ` _ \\  / _ \\ / __|     | | / _` |\\ \\ / /| | / _ \\| '__| ";
		Console::SetCursorPosition(33, 27); cout << "| |\\ \\| (_| || | | | | || (_) |\\__ \\ /\\__/ /| (_| | \\ V / | ||  __/| |    ";
		Console::SetCursorPosition(33, 28); cout << "\\_| \\_|\\__,_||_| |_| |_| \\___/ |___/ \\____/  \\__,_|  \\_/  |_| \\___||_|   ";



	}
	void Tutorial() {

		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 5);
		cout << "OBJETIVO:";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 6);
		cout << "*********";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 7);
		cout << "*El jugador debe recolectar suficientes recursos para poder plantar arboles"<<endl;
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(16, 8); 
		cout << "y limpiar el ambiente antes de que el tiempo o sus vidas se agoten.";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 10);
		cout << "*Cuando el jugador logre reforestar el 70% del mapa, GANASTE";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(16, 11);
		cout << "Es decir, cuando por lo menos plantas un arbol, eliminas a un villano";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(16, 12);
		cout << "y al menos tienes 5 recursos recolectados";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 14);
		cout << "*Si las vidas del jugador llegan a 0 o no consigue suficientes recursos";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(16, 15); 
		cout<<"para reforestar el terreno, PERDISTE";
	

		for (int i = 1; i < 100; i++)
		{
			Console::ForegroundColor = ConsoleColor::Yellow; Console::SetCursorPosition(i, 16); cout << "-";
		}


		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(5, 18);
		cout << "Controles para mover al Guardian:";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 19);
		cout << ",__  __,";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 20);
		cout << "|      |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 21);
		cout << "|  /\\  |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 22);
		cout << "|      |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 23);
		cout << "'--  --'";
		//
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 25);
		cout << ",__  __,";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 26);
		cout << "|      |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 27);
		cout << "|  \\/  |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 28);
		cout << "|      |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(15, 29);
		cout << "'--  --'";
		//
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(6, 21);
		cout << ",__  __,";														   
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(6, 22);
		cout << "|   ,  |";														   
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(6, 23);
		cout << "|  /   |";														   
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(6, 24);
		cout << "|  \\   |";													   
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(6, 25);
		cout << "|   '  |";														  
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(6, 26);
		cout << "'--  --'";
		//
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(24, 21);
		cout << ",__  __,";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(24, 22);
		cout << "|  ,   |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(24, 23);
		cout << "|   \\  |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(24, 24);
		cout << "|   /  |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(24, 25);
		cout << "|  '   |";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(24, 26);
		cout << "'--  --'";
		
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(5, 31); cout << " < :  Izquierda";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(5, 32); cout << " > :  Derecha";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(5, 33); cout << "/\\ :  Arriba";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(5, 34); cout << "\\/ :  Abajo";
		// Dibujar barra lateral
		for (int i = 17; i < 40; i++)
		{
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(50, i);
			cout << "|";
		}

		// Título "botones a utilizar:"
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(53, 18);
		cout << "Botones a utilizar:";

		// Botón S
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(62, 21);
		cout << ",__  __,";                      // Parte superior
		Console::SetCursorPosition(62, 22);
		cout << "|      |";                      // Borde superior
		Console::SetCursorPosition(62, 23);
		cout << "|   S  |";                      // Contenido del botón: S
		Console::SetCursorPosition(62, 24);
		cout << "|      |";                      // Borde inferior
		Console::SetCursorPosition(62, 25);
		cout << "'--  --'";                      // Parte inferior

		// Botón R
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(72, 21);
		cout << ",__  __,";                      // Parte superior
		Console::SetCursorPosition(72, 22);
		cout << "|      |";                      // Borde superior
		Console::SetCursorPosition(72, 23);
		cout << "|   R  |";                      // Contenido del botón: R
		Console::SetCursorPosition(72, 24);
		cout << "|      |";                      // Borde inferior
		Console::SetCursorPosition(72, 25);
		cout << "'--  --'";                      // Parte inferior

		// Botón D
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(68, 26);
		cout << ",__  __,";                      // Parte superior
		Console::SetCursorPosition(68, 27);
		cout << "|      |";                      // Borde superior
		Console::SetCursorPosition(68, 28);
		cout << "|   D  |";                      // Contenido del botón: D
		Console::SetCursorPosition(68, 29);
		cout << "|      |";                      // Borde inferior
		Console::SetCursorPosition(68, 30);
		cout << "'--  --'";                      // Parte inferior
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(53, 32); cout << " S :  Sembrar";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(53, 33); cout << " R :  Regar";
		Console::ForegroundColor = ConsoleColor::Green; Console::SetCursorPosition(53, 34); cout << " D :  Disparar";
		

	}
	void Salir()
	{
		Console::Clear();
		exit(0);

	}
};