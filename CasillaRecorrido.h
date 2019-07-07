//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_CASILLARECORRIDO_H
#define UNTITLED_CASILLARECORRIDO_H

#include "Casillla.h"

class CasillaRecorrido:public Casilla{
public:
    CasillaRecorrido(int X, int Y){
        x = X;
        y = Y;
    }
    void mostrar() override{
        color = 'r';
        tablero[getX()][getY()] = getColor();
    }
};

#endif //UNTITLED_CASILLARECORRIDO_H
