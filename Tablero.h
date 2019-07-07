//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_TABLERO_H
#define UNTITLED_TABLERO_H

#include "Casillla.h"
#include "CasillaRecorrido.h"
#include "CasillaSegura.h"
#include "CasillaCasa.h"
#include "CasillaFinal.h"
#include "CasillaInicio.h"
#include <vector>
#include <iostream>
using namespace std;

vector<Casilla*>* casillas;

class Tablero{
public:
    Tablero(){
        tablero = new char*[15];
        for(int i=0 ;i<15 ;i++)
            tablero[i] = new char[15];
        for(int i=0 ;i<15;i++)
            for(int j=0 ;j<15 ;j++)
                tablero[i][j] = '*';
        casillas = new vector<Casilla *>();
    }

     void IngresoDatos(){
        // Creacion de las casillas Casas verde
        casillas->push_back(new CasillaCasa(0,0,'V'));
        casillas->push_back(new CasillaCasa(0,1,'V'));
        casillas->push_back(new CasillaCasa(1,0,'V'));
        casillas->push_back(new CasillaCasa(1,1,'V'));

        //Zona segura para verde
        casillas->push_back(new CasillaSegura(7,1));
        casillas->push_back(new CasillaSegura(7,2));
        casillas->push_back(new CasillaSegura(7,3));
        casillas->push_back(new CasillaSegura(7,4));
        casillas->push_back(new CasillaSegura(7,5));

        // Creacion de las casillas Casas rojo
        casillas->push_back(new CasillaCasa(13,0,'R'));
        casillas->push_back(new CasillaCasa(13,1,'R'));
        casillas->push_back(new CasillaCasa(14,0,'R'));
        casillas->push_back(new CasillaCasa(14,1,'R'));

        //Zona segura para rojo
        casillas->push_back(new CasillaSegura(9,7));
        casillas->push_back(new CasillaSegura(10,7));
        casillas->push_back(new CasillaSegura(11,7));
        casillas->push_back(new CasillaSegura(12,7));
        casillas->push_back(new CasillaSegura(13,7));

        // Creacion de las casillas Casas azul
        casillas->push_back(new CasillaCasa(0,13,'A'));
        casillas->push_back(new CasillaCasa(0,14,'A'));
        casillas->push_back(new CasillaCasa(1,13,'A'));
        casillas->push_back(new CasillaCasa(1,14,'A'));

        //Zona segura para azul
        casillas->push_back(new CasillaSegura(1,7));
        casillas->push_back(new CasillaSegura(2,7));
        casillas->push_back(new CasillaSegura(3,7));
        casillas->push_back(new CasillaSegura(4,7));
        casillas->push_back(new CasillaSegura(5,7));

        // Creacion de las casillas Casas amarillo
        casillas->push_back(new CasillaCasa(13,13,'Y'));
        casillas->push_back(new CasillaCasa(13,14,'Y'));
        casillas->push_back(new CasillaCasa(14,13,'Y'));
        casillas->push_back(new CasillaCasa(14,14,'Y'));

        //Zona segura para amarillo
        casillas->push_back(new CasillaSegura(7,13));
        casillas->push_back(new CasillaSegura(7,12));
        casillas->push_back(new CasillaSegura(7,11));
        casillas->push_back(new CasillaSegura(7,10));
        casillas->push_back(new CasillaSegura(7,9));

        // Creacion de las Casillas Inicios
        casillas->push_back(new CasillaInicio(13,6));
        casillas->push_back(new CasillaInicio(6,1));
        casillas->push_back(new CasillaInicio(1,8));
        casillas->push_back(new CasillaInicio(8,13));

        // Creacion de las casillas Recorrido
        casillas->push_back(new CasillaRecorrido(14,6));
        casillas->push_back(new CasillaRecorrido(12,6));
        casillas->push_back(new CasillaRecorrido(11,6));
        casillas->push_back(new CasillaRecorrido(10,6));
        casillas->push_back(new CasillaRecorrido(9,6));
        casillas->push_back(new CasillaRecorrido(8,5));
        casillas->push_back(new CasillaRecorrido(8,4));
        casillas->push_back(new CasillaRecorrido(8,3));
        casillas->push_back(new CasillaRecorrido(8,2));
        casillas->push_back(new CasillaRecorrido(8,1));
        casillas->push_back(new CasillaRecorrido(8,0));
        casillas->push_back(new CasillaRecorrido(7,0));
        casillas->push_back(new CasillaRecorrido(6,0));
        casillas->push_back(new CasillaRecorrido(6,2));
        casillas->push_back(new CasillaRecorrido(6,3));
        casillas->push_back(new CasillaRecorrido(6,4));
        casillas->push_back(new CasillaRecorrido(6,5));
        casillas->push_back(new CasillaRecorrido(5,6));
        casillas->push_back(new CasillaRecorrido(4,6));
        casillas->push_back(new CasillaRecorrido(3,6));
        casillas->push_back(new CasillaRecorrido(2,6));
        casillas->push_back(new CasillaRecorrido(1,6));
        casillas->push_back(new CasillaRecorrido(0,6));
        casillas->push_back(new CasillaRecorrido(0,7));
        casillas->push_back(new CasillaRecorrido(0,8));
        casillas->push_back(new CasillaRecorrido(2,8));
        casillas->push_back(new CasillaRecorrido(3,8));
        casillas->push_back(new CasillaRecorrido(4,8));
        casillas->push_back(new CasillaRecorrido(5,8));
        casillas->push_back(new CasillaRecorrido(6,9));
        casillas->push_back(new CasillaRecorrido(6,10));
        casillas->push_back(new CasillaRecorrido(6,11));
        casillas->push_back(new CasillaRecorrido(6,12));
        casillas->push_back(new CasillaRecorrido(6,13));
        casillas->push_back(new CasillaRecorrido(6,14));
        casillas->push_back(new CasillaRecorrido(7,14));
        casillas->push_back(new CasillaRecorrido(8,14));
        casillas->push_back(new CasillaRecorrido(8,12));
        casillas->push_back(new CasillaRecorrido(8,11));
        casillas->push_back(new CasillaRecorrido(8,10));
        casillas->push_back(new CasillaRecorrido(8,9));
        casillas->push_back(new CasillaRecorrido(9,8));
        casillas->push_back(new CasillaRecorrido(10,8));
        casillas->push_back(new CasillaRecorrido(11,8));
        casillas->push_back(new CasillaRecorrido(12,8));
        casillas->push_back(new CasillaRecorrido(13,8));
        casillas->push_back(new CasillaRecorrido(14,8));
        casillas->push_back(new CasillaRecorrido(14,7));
        casillas->push_back(new CasillaRecorrido(14,6));

        // Casilla Final
        casillas->push_back(new CasillaFinal(8,7));
        casillas->push_back(new CasillaFinal(7,6));
        casillas->push_back(new CasillaFinal(6,7));
        casillas->push_back(new CasillaFinal(7,8));

        for(Casilla* casilla: *casillas)
            casilla->mostrar();
    }
     void mostrar(){
        // Iteracion sobre cada objeto almacenado en el vector
        for(int i=0 ;i<15 ;i++) {
            for (int j = 0; j < 15; j++) {
                cout <<tablero[i][j]<<"\t";
            }
            cout << endl;
        }
    }
};


#endif //UNTITLED_TABLERO_H
