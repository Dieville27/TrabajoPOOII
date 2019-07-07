//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_FICHA_H
#define UNTITLED_FICHA_H

#include "Dado.h"
#include "Casillla.h"

class Ficha {
private:
    char estado;
public:
    Ficha(){
        estado = 'C';
    }
    void mover(Casilla* casilla,int movimiento){

        //Este if es para mover CasillaCasa a CasillaInicio
        if ( movimiento == 6 && estado == 'C') {
            estado = 'J';

            if((casilla -> getX()<2) && (casilla -> getY()<2)){
                tablero[6][1] = estado ;
            }
            else if ( 12< (casilla -> getX()) && (casilla -> getX())<15 && casilla -> getY()<2 ){

                tablero[13][6] = estado;

            }
            else if ( 12< (casilla -> getY()) && (casilla -> getY())<15 && casilla -> getX()<2 ){

                tablero[1][8] = estado;

            }

            else if ( 12< (casilla -> getY()) && (casilla -> getY())<15 && 12< (casilla -> getX()) && (casilla -> getX())<15 ){

                tablero[8][13] = estado;

            }

        }
        // Este if es para mover de CasillaRecorrido a CasillaSegura de forma vertical
        if((casilla->getX()==7 && casilla->getY()>0 && casilla->getY()<6) ||(casilla->getX()==7 && casilla->getY()>8 && casilla->getY()<14)){
            estado = 'S';
            tablero[casilla->getX()][casilla->getY()] = estado;
        }
        // Este if es para mover de CasillaRecorrido a CasillaSegura de forma horizontal
        if((casilla->getY()==7 && casilla->getX()>0 && casilla->getX()<6) ||(casilla->getY()==7 && casilla->getX()>8 && casilla->getX()<14)){
            estado = 'S';
            tablero[casilla->getX()][casilla->getY()] = estado;
        }
        // Este if es para mover de CasillaSegura A CasillaFinal
        if(tablero[7][6] == tablero[casilla->getX()][casilla->getY()] || tablero[6][7] == tablero[casilla->getX()][casilla->getY()] || tablero[7][8] == tablero[casilla->getX()][casilla->getY()] || tablero[8][7] == tablero[casilla->getX()][casilla->getY()] ){
            estado = 'F';
        }
    }
    char getEstado(){
        return estado;
    }
};


#endif //UNTITLED_FICHA_H
