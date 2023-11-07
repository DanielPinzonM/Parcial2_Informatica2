#include <iostream>
#include "Casilla.h"

const short int TamanoTablero = 8;

using namespace std;

void MostrarTablero(Casilla **Tablero);
void ComprobarJugadas(Casilla **Tablero, Contenido Cont, bool* PuedeJugar);
void RealizarMovimiento(Casilla **Tablero, short int *Fila, short int *Columna, Contenido Cont);
void LimpiarPosiblesJugadas(Casilla **Tablero);
void DeterminarGanador(Casilla **Tablero);

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
    bool PuedeJugar1 = false;
    bool PuedeJugar2 = false;

    while (true) {

        if (JugadorActual == '1'){

            PuedeJugar1 = false;
            ComprobarJugadas(Tablero, Contenido::FichaNegra, &PuedeJugar1);

            while (PuedeJugar1 == true){

                MostrarTablero(Tablero);
                cout << "\n\n\nEs el turno del jugador 1 (Fichas Negras(X))\n";
                cout << "Ingresa la fila y la columna del movimiento(ejemplo: 3 4): ";
                cin >> fila >> columna;

                fila = fila-1;
                columna = columna -1;

                if (fila < 0 || fila >= TamanoTablero || columna < 0 || columna >= TamanoTablero) {

                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << "Movimiento inválido. Inténtalo de nuevo.\n";
                }
                else{
                    if (Tablero[fila][columna].getContenido() == Contenido::PosibleJugada){
                        RealizarMovimiento(Tablero, &fila, &columna, Contenido::FichaNegra);
                        MostrarTablero(Tablero);
                        JugadorActual += 1;
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        break;
                    }
                    else{
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout << "Movimiento inválido. Inténtalo de nuevo.\n";
                    }
                }
            }

            if (PuedeJugar1 == false){
                MostrarTablero(Tablero);
                cout << "No tiene jugadas disponibles, se pasará el turno al siguiente jugador.\nIngrese 1 para continuar: ";
                cin >> fila;
                JugadorActual +=1;
            }
        }

        else if (JugadorActual == '2'){

            PuedeJugar2 = false;
            ComprobarJugadas(Tablero, Contenido::FichaBlanca, &PuedeJugar2);

            while (PuedeJugar2 == true){

                MostrarTablero(Tablero);
                cout << "\n\n\nEs el turno del jugador 2 (Fichas Blancas(O))\n";
                cout << "Ingresa la fila y la columna del movimiento(ejemplo: 3 4): ";
                cin >> fila >> columna;

                fila = fila-1;
                columna = columna -1;

                if (fila < 0 || fila >= TamanoTablero || columna < 0 || columna >= TamanoTablero) {

                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << "Movimiento inválido. Inténtalo de nuevo.\n";
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
                        cout << "Movimiento inválido. Inténtalo de nuevo.\n";
                    }
                }
            }

            if (PuedeJugar2 == false){
                MostrarTablero(Tablero);
                cout << "No tiene jugadas disponibles, se pasará el turno al siguiente jugador.\nIngrese 1 para continuar: ";
                cin >> fila;
                JugadorActual +=1;
            }
        }

        if (PuedeJugar1 == false && PuedeJugar2 == false){

            break;
        }
    }

    return 0;
}


void MostrarTablero(Casilla **Tablero){

    cout << "         1 2 3 4 5 6 7 8 \n\n";

    for (int i = 0; i < TamanoTablero; i++) {

        cout << "     " << i+1 << "   ";

        for (int j = 0; j < TamanoTablero; j++) {
            cout << Tablero[i][j].RepresentarContenido() << ' ';
        }
        cout << "  " << i+1 << "\n";
    }

    cout << "\n         1 2 3 4 5 6 7 8";
}

void ComprobarJugadas(Casilla **Tablero, Contenido Cont, bool* PuedeJugar){

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
                                if (*PuedeJugar == false){
                                    *PuedeJugar = true;
                                }
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
                                if (*PuedeJugar == false){
                                    *PuedeJugar = true;
                                }
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
                                if (*PuedeJugar == false){
                                    *PuedeJugar = true;
                                }
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
                                if (*PuedeJugar == false){
                                    *PuedeJugar = true;
                                }
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
                                if (*PuedeJugar == false){
                                    *PuedeJugar = true;
                                }
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
                                if (*PuedeJugar == false){
                                    *PuedeJugar = true;
                                }
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
                                if (*PuedeJugar == false){
                                    *PuedeJugar = true;
                                }
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
                                if (*PuedeJugar == false){
                                    *PuedeJugar = true;
                                }
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

void DeterminarGanador(Casilla **Tablero){

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

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "                     JUGADOR 1 GANADOR";
        cout << " El jugador de fichas negras gana la partina con " << NumFichasN << " Fichas.";
    }
    else{

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "                     JUGADOR 2 GANADOR";
        cout << " El jugador de fichas blancas gana la partina con " << NumFichasN << " Fichas.";
    }

}
