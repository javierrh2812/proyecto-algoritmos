#pragma once
#include "conio.h"
#include "iostream"
#include <chrono>
#include "string"
#define DERECHA 77
#define DERECHA_LETRA 108
#define IZQUIERDA 75
#define IZQUIERDA_LETRA 106
#define ARRIBA 72
#define ARRIBA_LETRA 105
#define ABAJO 80
#define ABAJO_LETRA 107
#define SeleccionarEnter 13
#define SeleccionarZ 90
#define SeleccionarX 88
	
using namespace std;
using namespace System;

void moveTo (int x, int y) {
		Console::SetCursorPosition(x, y);
}

void changeColor(ConsoleColor color) {
	Console::ForegroundColor = color;
}