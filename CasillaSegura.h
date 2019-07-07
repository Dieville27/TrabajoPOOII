//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_CASILLASEGURA_H
#define UNTITLED_CASILLASEGURA_H

#include "Casillla.h"

class CasillaSegura:public Casilla{
public:
    CasillaSegura(int X, int Y){
        x = X;
        y = Y;
    }
    void mostrar() override{
        color = 's';
        tablero[getX()][getY()] = getColor();
    }
};

#endif //UNTITLED_CASILLASEGURA_H
