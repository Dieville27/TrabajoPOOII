//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_RECORRIDO_H
#define UNTITLED_RECORRIDO_H

#include "Casillla.h"

//Clase recorrido:

class Recorrido{
public:
    static void calcularMovimiento(Casilla* casilla,int movimientos){
        // Recorrido por las casillas Recorrido //
            // Movmiento Horizontal para la derecha //
            if (((casilla->getY()+movimientos<6 || casilla->getY()+movimientos>8)  && casilla->getX()==6) || ((casilla->getY()+movimientos<9 && casilla->getY()>5) && casilla->getX()==0)){
                tablero[casilla->getX()][casilla->getY()+movimientos] = 'J';
            }
            // Movimiento Horizontal para la izquierda //
            else if (( casilla ->getX()==8  && (casilla -> getY()-movimientos>8 || casilla -> getY()-movimientos>6)) || (casilla->getX()==14 && (casilla->getY()-movimientos>5 && casilla->getY()<9))){
                tablero[casilla->getX()][casilla->getY()-movimientos] = 'J';
            }
            // Movmiento Vertical hacia arriba //
            else if ((casilla -> getY()==6  && ((casilla -> getX()-movimientos>-1 && casilla->getX()<6)||(casilla->getX()-movimientos>8  && casilla->getX()>8))) || ((casilla->getX()-movimientos>5  && (casilla->getX()<9 && casilla->getX()>5)) && casilla->getY()==0)){
                tablero[casilla->getX()-movimientos][casilla->getY()] = 'J' ;
            }
            // Moviento Vertical hacia abajo //
            else if (((casilla->getX()<6 && casilla->getY()==8 && casilla->getX()>-1) && (casilla->getX()+movimientos<6)) || ((casilla->getX()>8 && casilla->getX()<15 && casilla->getY()==8) && (casilla->getX()+movimientos<15)) || ((casilla->getX()<9 && casilla->getX()>5 && casilla->getY()==14) && (casilla->getX()+movimientos<9))){
                tablero[casilla->getX()+movimientos][casilla->getY()] = 'J';
            }
        // Fin del codigo de casillas Recorrido //

        // Recorrido para las casillas Segura //
            // Movimiento Horizontal para la derecha//

        }

};


#endif //UNTITLED_RECORRIDO_H
