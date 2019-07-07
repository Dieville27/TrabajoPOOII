//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_CASILLACASA_H
#define UNTITLED_CASILLACASA_H

#include "Casillla.h"

class CasillaCasa: public Casilla {
public:
    CasillaCasa(int X, int Y, char Color){
        x = X;
        y = Y;
        color = Color;
    }
    void mostrar() override{
        tablero[getX()][getY()] = getColor();
    }
};



#endif //UNTITLED_CASILLACASA_H
