#include <iostream>
#include "Casilla.h"

const short int TamanoTablero = 8;

using namespace std;

void MostrarTablero(Casilla **Tablero);

int main() {

    Casilla **Tablero = new Casilla*[8];

    for (short int i = 0; i < 8; i++) {
        Tablero[i] = new Casilla[8];
    }

    short int centro = TamanoTablero/2;

    Tablero[centro - 1][centro - 1].setContenido(Contenido::FichaBlanca);
    Tablero[centro - 1][centro].setContenido(Contenido::FichaNegra);
    Tablero[centro][centro - 1].setContenido(Contenido::FichaNegra);
    Tablero[centro][centro].setContenido(Contenido::FichaBlanca);

    MostrarTablero(Tablero);

    char JugadorActual = '1';
    short int fila, columna;

    return 0;

}

void MostrarTablero(Casilla **Tablero){

    cout << "         A B C D E F G H \n\n";

    for (int i = 0; i < TamanoTablero; i++) {

        cout << "     " << i+1 << "   ";

        for (int j = 0; j < TamanoTablero; j++) {
            cout << Tablero[i][j].RepresentarContenido() << ' ';
        }
        cout << "  " << i+1 << "\n";
    }

    cout << "\n         A B C D E F G H";
}