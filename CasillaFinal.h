//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_CASILLAFINAL_H
#define UNTITLED_CASILLAFINAL_H

#include "Casillla.h"

class CasillaFinal:public Casilla{
public:
    CasillaFinal(int X, int Y){
        x = X;
        y = Y;
    }
    void mostrar() override{
        color = 'F';
        tablero[getX()][getY()] = getColor();
    }
};



#endif //UNTITLED_CASILLAFINAL_H
