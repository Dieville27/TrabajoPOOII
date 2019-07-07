//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_CASILLLA_H
#define UNTITLED_CASILLLA_H

char** tablero;

class Casilla{
protected:
    int x;
    int y;
    bool disponible;
    char color;
public:
    Casilla(){}
    virtual void mostrar() = 0;

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    char getColor(){
        return color;
    }

    bool getDisponible(){
        return disponible;
    }
};

#endif //UNTITLED_CASILLLA_H
