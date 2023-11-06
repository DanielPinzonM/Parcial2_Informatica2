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

    char JugadorActual = '1';
    short int fila, columna;

    while (true) {

        if (JugadorActual == '1'){

            ComprobarJugadas(Tablero, Contenido::FichaNegra);
            MostrarTablero(Tablero);

            cout << "\n\n\nEs el turno del jugador 1 (Fichas Negras(+))\n";
            cout << "Ingresa la fila y la columna para tu movimiento (ejemplo: 3 4): ";
            cin >> fila >> columna;

            if (fila < 0 || fila >= TamanoTablero || columna < 0 || columna >= TamanoTablero) {
                cout << "Movimiento inválido. Inténtalo de nuevo.\n";
            }
        }
    }

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


void ComprobarJugadas(Casilla **Tablero, Contenido Cont){

    for (short int i = 0; i < TamanoTablero; i++) {
        for (short int j = 0; j < TamanoTablero; j++) {

            if (Tablero[i][j].getContenido() == Cont){


                if (i>1){ //Filas hacia arriba
                    for (short int Factual = i-1; Factual >= 0; Factual--){

                        if (Tablero[Factual][j].getContenido() == Contenido::FichaNegra){
                            break;
                        }
                        else if (Tablero[Factual][j].getContenido() == Contenido::NoOcupada || Tablero[Factual][j].getContenido() == Contenido::PosibleJugada){
                            if(Factual == i-1){
                                break;
                            }
                            else{
                                Tablero[Factual][j].setContenido(Contenido::PosibleJugada);
                                break;
                            }
                        }
                    }

                }

                if (i<TamanoTablero-2){ //Filas hacia abajo
                    for (short int Factual = i+1; Factual < TamanoTablero; Factual++){

                        if (Tablero[Factual][j].getContenido() == Contenido::FichaNegra){
                            break;
                        }
                        else if (Tablero[Factual][j].getContenido() == Contenido::NoOcupada || Tablero[Factual][j].getContenido() == Contenido::PosibleJugada){
                            if(Factual == i+1){
                                break;
                            }
                            else{
                                Tablero[Factual][j].setContenido(Contenido::PosibleJugada);
                                break;
                            }
                        }
                    }

                }

                if (j>1){ //Columnas a la izquierda
                    for (short int Cactual = j-1; Cactual >= 0; Cactual--){

                        if (Tablero[i][Cactual].getContenido() == Contenido::FichaNegra){
                            break;
                        }
                        else if (Tablero[i][Cactual].getContenido() == Contenido::NoOcupada || Tablero[i][Cactual].getContenido() == Contenido::PosibleJugada){
                            if(Cactual == j-1){
                                break;
                            }
                            else{
                                Tablero[i][Cactual].setContenido(Contenido::PosibleJugada);
                                break;
                            }
                        }
                    }

                }

                if (j<TamanoTablero-2){ //Columnas a la derecha
                    for (short int Cactual = j+1; Cactual < TamanoTablero; Cactual++){

                        if (Tablero[i][Cactual].getContenido() == Contenido::FichaNegra){
                            break;
                        }
                        else if (Tablero[i][Cactual].getContenido() == Contenido::NoOcupada || Tablero[i][Cactual].getContenido() == Contenido::PosibleJugada){
                            if(Cactual == j+1){
                                break;
                            }
                            else{
                                Tablero[i][Cactual].setContenido(Contenido::PosibleJugada);
                                break;
                            }
                        }
                    }

                }

                if (i>1 && j>1){ //Diagonal superior izquierda
                    for (short int FCactual = i-1; FCactual >= 0; FCactual--){

                        if (Tablero[FCactual][j-(i-FCactual)].getContenido() == Contenido::FichaNegra){
                            break;
                        }
                        else if (Tablero[FCactual][j-(i-FCactual)].getContenido() == Contenido::NoOcupada || Tablero[FCactual][j-(i-FCactual)].getContenido() == Contenido::PosibleJugada){
                            if(FCactual == i-1){
                                break;
                            }
                            else{
                                Tablero[FCactual][j-(i-FCactual)].setContenido(Contenido::PosibleJugada);
                                break;
                            }
                        }
                    }

                }

                if (i<TamanoTablero-2 && j<TamanoTablero-2){ //Diagonal inferior derecha
                    for (short int FCactual = i+1; FCactual < TamanoTablero; FCactual++){

                        if (Tablero[FCactual][j+(FCactual-i)].getContenido() == Contenido::FichaNegra){
                            break;
                        }
                        else if (Tablero[FCactual][j+(FCactual-i)].getContenido() == Contenido::NoOcupada || Tablero[FCactual][j+(FCactual-i)].getContenido() == Contenido::PosibleJugada){
                            if(FCactual == i+1){
                                break;
                            }
                            else{
                                Tablero[FCactual][j+(FCactual-i)].setContenido(Contenido::PosibleJugada);
                                break;
                            }
                        }
                    }

                }

                if (i>1 && j<TamanoTablero-2){ //Diagonal superior derecha
                    for (short int FCactual = i-1; FCactual >= 0; FCactual--){

                        if (Tablero[FCactual][j+(i-FCactual)].getContenido() == Contenido::FichaNegra){
                            break;
                        }
                        else if (Tablero[FCactual][j+(i-FCactual)].getContenido() == Contenido::NoOcupada || Tablero[FCactual][j+(i-FCactual)].getContenido() == Contenido::PosibleJugada){
                            if(FCactual == i-1){
                                break;
                            }
                            else{
                                Tablero[FCactual][j+(i-FCactual)].setContenido(Contenido::PosibleJugada);
                                break;
                            }
                        }
                    }

                }

                if ((i<TamanoTablero-2) && j>1){ //Diagonal inferior izquierda
                    for (short int FCactual = i+1; FCactual < TamanoTablero; FCactual++){

                        if (Tablero[FCactual][j-(FCactual-i)].getContenido() == Contenido::FichaNegra){
                            break;
                        }
                        else if (Tablero[FCactual][j-(FCactual-i)].getContenido() == Contenido::NoOcupada || Tablero[FCactual][j-(FCactual-i)].getContenido() == Contenido::PosibleJugada){
                            if(FCactual == i+1){
                                break;
                            }
                            else{
                                Tablero[FCactual][j-(FCactual-i)].setContenido(Contenido::PosibleJugada);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}