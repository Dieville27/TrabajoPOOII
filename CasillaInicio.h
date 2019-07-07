//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_CASILLAINICIO_H
#define UNTITLED_CASILLAINICIO_H

#include "Casillla.h"

class CasillaInicio:public Casilla{
public:
    CasillaInicio(int X, int Y){
        x = X;
        y = Y;
    }
    void mostrar() override{
        color = 'I';
        tablero[getX()][getY()] = getColor();
    }
};


#endif //UNTITLED_CASILLAINICIO_H
