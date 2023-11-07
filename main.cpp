#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include "Casilla.h"
#include "FuncionesOthello.h"

using namespace std;

int main() {

    string Jugadores[2];

    cout << "        OTHELLO\n\n\n";
    cout << "Ingrese el nombre del primer jugador (fichas negras): ";
    cin >> Jugadores[0];
    cout << "Ingrese el nombre del segundo jugador (fichas blancas): ";
    cin >> Jugadores[1];
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    Casilla **Tablero = new Casilla*[TamanoTablero];

    for (short int i = 0; i < TamanoTablero; i++) {
        Tablero[i] = new Casilla[TamanoTablero];
    }

    short int centro = TamanoTablero/2;

    Tablero[centro - 1][centro - 1].setContenido(Contenido::FichaBlanca);
    Tablero[centro - 1][centro].setContenido(Contenido::FichaNegra);
    Tablero[centro][centro - 1].setContenido(Contenido::FichaNegra);
    Tablero[centro][centro].setContenido(Contenido::FichaBlanca);

    char JugadorActual = '1';
    short int fila, columna;
    bool PuedeJugar1;
    bool PuedeJugar2;

    while (true) {

        if (JugadorActual == '1'){

            MarcarJugadas(Tablero, Contenido::FichaNegra);
            PuedeJugar1 = PuedeJugar(Tablero);

            while (PuedeJugar1 == true){

                cout << "Es el turno de " << Jugadores[0] << " (Fichas negras <X>)\n\n";
                MostrarTablero(Tablero);
                cout << "\n\n\nIngresa la fila y la columna del movimiento <3 4>: ";
                cin >> fila >> columna;

                fila = fila-1;
                columna = columna -1;

                if (fila < 0 || fila >= TamanoTablero || columna < 0 || columna >= TamanoTablero) {

                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << "Movimiento invalido. Intentalo de nuevo.\n";
                }
                else{
                    if (Tablero[fila][columna].getContenido() == Contenido::PosibleJugada){
                        RealizarMovimiento(Tablero, &fila, &columna, Contenido::FichaNegra);
                        LimpiarPosiblesJugadas(Tablero);
                        JugadorActual += 1;
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        break;
                    }
                    else{
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout << "Movimiento invalido. Intentalo de nuevo.\n";
                    }
                }
            }

            if (PuedeJugar1 == false){
                cout << "Es el turno de " << Jugadores[0] << " (Fichas negras <X>)\n\n";
                MostrarTablero(Tablero);
                cout << "\n\n\nNo tiene jugadas disponibles, se pasara el turno al siguiente jugador.\nIngrese 1 para continuar: ";
                cin >> fila;
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                JugadorActual +=1;
            }
        }

        else if (JugadorActual == '2'){

            MarcarJugadas(Tablero, Contenido::FichaBlanca);
            PuedeJugar2 = PuedeJugar(Tablero);

            while (PuedeJugar2 == true){

                cout << "Es el turno de " << Jugadores[1] << " (Fichas blancas <O>)\n\n";
                MostrarTablero(Tablero);
                cout << "\n\n\nIngresa la fila y la columna del movimiento <3 4>: ";
                cin >> fila >> columna;

                fila = fila-1;
                columna = columna -1;

                if (fila < 0 || fila >= TamanoTablero || columna < 0 || columna >= TamanoTablero) {

                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << "Movimiento invalido. Intentalo de nuevo.\n";
                }
                else{
                    if (Tablero[fila][columna].getContenido() == Contenido::PosibleJugada){
                        RealizarMovimiento(Tablero, &fila, &columna, Contenido::FichaBlanca);
                        LimpiarPosiblesJugadas(Tablero);
                        JugadorActual -= 1;
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        break;
                    }
                    else{
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout << "Movimiento invalido. Intentalo de nuevo.\n";
                    }
                }
            }

            if (PuedeJugar2 == false){
                cout << "Es el turno de " << Jugadores[1] << " (Fichas blancas <O>)\n\n";
                MostrarTablero(Tablero);
                cout << "\n\n\nNo tiene jugadas disponibles, se pasara el turno al siguiente jugador.\nIngrese 1 para continuar: ";
                cin >> fila;
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                JugadorActual -=1;
            }
        }

        if ((PuedeJugar1 == false && PuedeJugar2 == false) || TableroLleno(Tablero) == true){

            string Ganador;
            short int CantFichas;

            Ganador = DeterminarGanador(Tablero, Jugadores, &CantFichas);

            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            MostrarTablero(Tablero);

            if (Ganador == Jugadores[0]){

                cout << "\n\n\n                **" << Jugadores[0] << " GANADOR!!**\n";
                cout << " El jugador de fichas negras gana la partina con " << CantFichas << " fichas.";
                cout << "\n\n\n\n";

            }

            else{

                cout << "\n\n\n                **" << Jugadores[1] << " GANADOR!!**\n";
                cout << " El jugador de fichas negras gana la partina con " << CantFichas << " fichas.";
                cout << "\n\n\n\n";
            }

            GuardarRegistro(Jugadores, &Ganador, &CantFichas);

            break;
        }
    }

    for (short int i = 0; i < TamanoTablero; i++) {
        delete[] Tablero[i];
    }

    delete[] Tablero;

    Tablero = nullptr;

    return 0;
}
