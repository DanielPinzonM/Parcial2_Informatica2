#include "Casilla.h"

Casilla::Casilla(Contenido Cont) : Cont(Cont) {}

void Casilla::setContenido(Contenido NuevoContenido) {
        Cont = NuevoContenido;
    }

Contenido Casilla::getContenido(){
        return Cont;
    }

bool Casilla::NoOcupada(){
        return (Cont == Contenido::NoOcupada);
    }

char Casilla::RepresentarContenido(){

        switch (Cont) {

        case Contenido::FichaBlanca:
            return 'O';

        case Contenido::FichaNegra:
            return 'X';

        case Contenido::PosibleJugada:
            return '°';

        default:
            return '-';
        }
    }