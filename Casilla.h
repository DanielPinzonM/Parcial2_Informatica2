#ifndef CASILLA_H
#define CASILLA_H

enum Contenido {NoOcupada, PosibleJugada, FichaBlanca, FichaNegra};

class Casilla {
public:

    Casilla(Contenido Cont = Contenido::NoOcupada);
    void setContenido(Contenido NuevoContenido);
    Contenido getContenido();
    bool NoOcupada();
    char RepresentarContenido();

private:
    Contenido Cont;
};

#endif // CASILLA_H