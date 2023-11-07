#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include "Casilla.h"
#include "FuncionesOthello.h"

using namespace std;

void MostrarTablero(Casilla **Tablero){

    cout << "                  1 2 3 4 5 6 7 8 \n\n";

    for (int i = 0; i < TamanoTablero; i++) {

        cout << "              " << i+1 << "   ";

        for (int j = 0; j < TamanoTablero; j++) {
            cout << Tablero[i][j].RepresentarContenido() << ' ';
        }
        cout << "  " << i+1 << "\n";
    }

    cout << "\n                  1 2 3 4 5 6 7 8";
}

void MarcarJugadas(Casilla **Tablero, Contenido Cont){

    for (short int i = 0; i < TamanoTablero; i++) {
        for (short int j = 0; j < TamanoTablero; j++) {

            if (Tablero[i][j].getContenido() == Cont){


                if (i>1){ //Filas hacia arriba
                    for (short int Factual = i-1; Factual >= 0; Factual--){

                        if (Tablero[Factual][j].getContenido() == Cont){
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

                        if (Tablero[Factual][j].getContenido() == Cont){
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

                        if (Tablero[i][Cactual].getContenido() == Cont){
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

                        if (Tablero[i][Cactual].getContenido() == Cont){
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

                        if (Tablero[FCactual][j-(i-FCactual)].getContenido() == Cont){
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

                        if (Tablero[FCactual][j+(FCactual-i)].getContenido() == Cont){
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

                        if (Tablero[FCactual][j+(i-FCactual)].getContenido() == Cont){
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

                        if (Tablero[FCactual][j-(FCactual-i)].getContenido() == Cont){
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

bool PuedeJugar(Casilla **Tablero){

    for (short int i = 0; i < TamanoTablero; i++){
        for (short int j = 0; j < TamanoTablero; j++){

            if (Tablero[i][j].getContenido() == Contenido::PosibleJugada){
                return true;
            }
        }
    }

    return false;
}

void RealizarMovimiento(Casilla **Tablero, short int *Fila, short int *Columna, Contenido Cont){

    Tablero[*Fila][*Columna].setContenido(Cont);

    if (*Fila>1){ //Filas hacia arriba
        for (short int Factual = *Fila-1; Factual >= 0; Factual--){

            if (Tablero[Factual][*Columna].getContenido() == Contenido::NoOcupada || Tablero[Factual][*Columna].getContenido() == Contenido::PosibleJugada){
                break;
            }
            else if (Tablero[Factual][*Columna].getContenido() == Cont){
                if(Factual == *Fila-1){
                    break;
                }
                else{
                    for (short int i = Factual+1; i < *Fila; i++){
                        Tablero[i][*Columna].setContenido(Cont);
                    }
                    break;
                }
            }
        }
    }

    if (*Fila<TamanoTablero-2){ //Filas hacia abajo
        for (short int Factual = *Fila+1; Factual < TamanoTablero; Factual++){

            if (Tablero[Factual][*Columna].getContenido() == Contenido::NoOcupada || Tablero[Factual][*Columna].getContenido() == Contenido::PosibleJugada){
                break;
            }
            else if (Tablero[Factual][*Columna].getContenido() == Cont){
                if(Factual == *Fila+1){
                    break;
                }
                else{
                    for (short int i = Factual-1; i > *Fila; i--){
                        Tablero[i][*Columna].setContenido(Cont);
                    }
                    break;
                }
            }
        }
    }

    if (*Columna<TamanoTablero-2){ //Columnas a la derecha
        for (short int Cactual = *Columna+1; Cactual < TamanoTablero; Cactual++){

            if (Tablero[*Fila][Cactual].getContenido() == Contenido::NoOcupada || Tablero[*Fila][Cactual].getContenido() == Contenido::PosibleJugada){
                break;
            }
            else if (Tablero[*Fila][Cactual].getContenido() == Cont){
                if(Cactual == *Columna+1){
                    break;
                }
                else{
                    for (short int i = Cactual-1; i > *Columna; i--){
                        Tablero[*Fila][i].setContenido(Cont);
                    }
                    break;
                }
            }
        }
    }

    if (*Columna>1){ //Columnas a la izquierda
        for (short int Cactual = *Columna-1; Cactual >= 0; Cactual--){

            if (Tablero[*Fila][Cactual].getContenido() == Contenido::NoOcupada || Tablero[*Fila][Cactual].getContenido() == Contenido::PosibleJugada){
                break;
            }
            else if (Tablero[*Fila][Cactual].getContenido() == Cont){
                if(Cactual == *Columna-1){
                    break;
                }
                else{
                    for (short int i = Cactual+1; i < *Columna; i++){
                        Tablero[*Fila][i].setContenido(Cont);
                    }
                    break;
                }
            }
        }
    }

    if (*Fila>1 && *Columna>1){ //Diagonal superior izquierda
        for (short int FCactual = *Fila-1; FCactual >= 0; FCactual--){

            if (Tablero[FCactual][*Columna-(*Fila-FCactual)].getContenido() == Contenido::NoOcupada || Tablero[FCactual][*Columna-(*Fila-FCactual)].getContenido() == Contenido::PosibleJugada){
                break;
            }
            else if (Tablero[FCactual][*Columna-(*Fila-FCactual)].getContenido() == Cont){
                if(FCactual == *Fila-1){
                    break;
                }
                else{
                    for (short int i = FCactual+1; i < *Fila; i++){
                        Tablero[i][*Columna-(*Fila-i)].setContenido(Cont);
                    }
                    break;
                }
            }
        }
    }

    if (*Fila<TamanoTablero-2 && *Columna<TamanoTablero-2){ //Diagonal inferior derecha
        for (short int FCactual = *Fila+1; FCactual < TamanoTablero; FCactual++){

            if (Tablero[FCactual][*Columna+(FCactual-(*Fila))].getContenido() == Contenido::NoOcupada || Tablero[FCactual][*Columna+(FCactual-(*Fila))].getContenido() == Contenido::PosibleJugada){
                break;
            }
            else if (Tablero[FCactual][*Columna+(FCactual-(*Fila))].getContenido() == Cont){
                if(FCactual == *Fila+1){
                    break;
                }
                else{
                    for (short int i = FCactual-1; i > *Fila; i--){
                        Tablero[i][*Columna+(i-(*Fila))].setContenido(Cont);
                    }
                    break;
                }
            }
        }
    }

    if (*Fila>1 && *Columna<TamanoTablero-2){ //Diagonal superior derecha
        for (short int FCactual = *Fila-1; FCactual >= 0; FCactual--){

            if (Tablero[FCactual][*Columna+(*Fila-FCactual)].getContenido() == Contenido::NoOcupada || Tablero[FCactual][*Columna+(*Fila-FCactual)].getContenido() == Contenido::PosibleJugada){
                break;
            }
            else if (Tablero[FCactual][*Columna+(*Fila-FCactual)].getContenido() == Cont){
                if(FCactual == *Fila-1){
                    break;
                }
                else{
                    for (short int i = FCactual+1; i < *Fila; i++){
                        Tablero[i][*Columna+(*Fila-i)].setContenido(Cont);
                    }
                    break;
                }
            }
        }
    }

    if ((*Fila<TamanoTablero-2) && *Columna>1){ //Diagonal inferior izquierda
        for (short int FCactual = *Fila+1; FCactual < TamanoTablero; FCactual++){

            if (Tablero[FCactual][*Columna-(FCactual-(*Fila))].getContenido() == Contenido::NoOcupada || Tablero[FCactual][*Columna-(FCactual-(*Fila))].getContenido() == Contenido::PosibleJugada){
                break;
            }
            else if (Tablero[FCactual][*Columna-(FCactual-(*Fila))].getContenido() == Cont){
                if(FCactual == *Fila+1){
                    break;
                }
                else{
                    for (short int i = FCactual-1; i > *Fila; i--){
                        Tablero[i][*Columna-(i-(*Fila))].setContenido(Cont);
                    }
                    break;
                }
            }
        }
    }
}

void LimpiarPosiblesJugadas(Casilla **Tablero){

    for (short int i = 0; i < TamanoTablero; i++){
        for (short int j = 0; j < TamanoTablero; j++){

            if (Tablero[i][j].getContenido() == Contenido::PosibleJugada){
                Tablero[i][j].setContenido(Contenido::NoOcupada);
            }
        }
    }
}

bool TableroLleno(Casilla **Tablero){

    for (short int i = 0; i < TamanoTablero; i++){
        for (short int j = 0; j < TamanoTablero; j++){

            if (Tablero[i][j].getContenido() == Contenido::NoOcupada){
                return false;
            }
        }
    }

    return true;
}

string DeterminarGanador(Casilla **Tablero, string *Jugadores,  short int* CantFichas){

    short int NumFichasN = 0;
    short int NumFichasB = 0;

    for (short int i = 0; i < TamanoTablero; i++){
        for (short int j = 0; j < TamanoTablero; j++){

            if (Tablero[i][j].getContenido() == Contenido::FichaNegra){
                NumFichasN += 1;
            }
            else{
                NumFichasB += 1;
            }
        }
    }

    if (NumFichasN > NumFichasB){

        *CantFichas = NumFichasN;
        return Jugadores[0];
    }
    else{

        *CantFichas = NumFichasB;
        return Jugadores[1];
    }

}

void GuardarRegistro(string *Jugadores, string *Ganador, short int *CantFichas){

    ofstream archivo;

    try{

        archivo.open("Registros.txt", ios::app);

        if (!archivo.is_open()){
            throw '1';
        }

    }catch (char c){

        if (c == '1'){
            cout << "Error al acceder al archivo de registros para guardar los datos.";
            return;
        }
    }

    archivo << FechaHoraActual() << "\nJugador 1 (Fichas Negras): " << Jugadores[0]
            << "\nJugador 2 (Fichas Blancas): " << Jugadores[1] << "\nGanador: "
            << *Ganador << " con " << *CantFichas << " fichas\n\n";

    archivo.close();
}

string FechaHoraActual() {
    time_t t = time(nullptr);
    tm* Actual = localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", Actual);
    return buffer;
}
