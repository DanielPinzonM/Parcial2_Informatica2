#ifndef FUNCIONESOTHELLO_H
#define FUNCIONESOTHELLO_H
#include <string>
#include "Casilla.h"

const short int TamanoTablero = 8;

using namespace std;

void MostrarTablero(Casilla **Tablero);
void MarcarJugadas(Casilla **Tablero, Contenido Cont);
bool PuedeJugar(Casilla **Tablero);
void RealizarMovimiento(Casilla **Tablero, short int *Fila, short int *Columna, Contenido Cont);
void LimpiarPosiblesJugadas(Casilla **Tablero);
bool TableroLleno(Casilla **Tablero);
string DeterminarGanador(Casilla **Tablero, string *Jugadores, short int* CantFichas);
void GuardarRegistro(string *Jugadores, string *Ganador, short int *CantFichas);
string FechaHoraActual();

#endif // FUNCIONESOTHELLO_H