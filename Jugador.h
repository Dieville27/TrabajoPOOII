//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_JUGADOR_H
#define UNTITLED_JUGADOR_H

#include <string>
#include <iostream>
#include <iterator>
#include "Ficha.h"
#include "Casillla.h"
#include "Tablero.h"
#include "Recorrido.h"
using namespace std;

char Color[4] = {'R','V','Y','A'};
Ficha** fichaJugador = nullptr;

class Jugador {
private:
    string nombre;
    char color;
public:
    Jugador() {
        string Nombre;
        cout<<"Ingresa tu nombre:";
        cin>>Nombre;
        this->nombre = Nombre;
        fichaJugador = new Ficha*[4];
        for(int i=0 ;i<4 ;i++){
            fichaJugador[i] = new Ficha();
        }
        cout<<"Ingrese el color a escojer:"<<endl;
        int  opcion = 0;
        do{
           for(int i=1 ; i<=4 ; i++){
               cout<<i<<". "<<Color[i-1]<<endl;
           }
           cout<<"Ingrese su opcion:";
           cin>>opcion;
        }while(opcion < 1 || opcion > 4);
        switch(opcion) {
            case 1:
                color = Color[opcion-1];
                Color[opcion-1] = 'O';
                default:
                    break;
            case 2:
                color = Color[opcion-1];
                Color[opcion-1] = 'O';
            case 3:
                color = Color[opcion-1];
                Color[opcion-1] = 'O';
            case 4:
                color = Color[opcion-1];
                Color[opcion-1] = 'O';
        }
    }

    void jugar(Ficha *ficha, int movimientos) {
        cout<<"EL RESULTADO DEL DADO ES EL SIGUIENTE: "<<movimientos<<endl;
        for(Casilla* comprobar: *casillas) {
            if(comprobar->getColor()==color) {
                ficha->mover(comprobar,movimientos);
            }
            if(ficha->getEstado()=='J' || ficha->getEstado()=='S'){
                seleccionarFichaEnJuego();
                Recorrido::calcularMovimiento(comprobar,movimientos);
            }
        }
    }

    static Ficha *seleccionarFichaEnJuego() {
        int opcion = 0;
        cout << "Escoja su su ficha a mover por el tablero" << endl;
        do {
            cout << "1. Ficha numero 1"<<endl;
            cout << "2. Ficha numero 2"<<endl;
            cout << "3. Ficha numero 3"<<endl;
            cout << "4. Ficha numero 4"<<endl;
            cout << "Ingrese la ficha que desea mover: ";
            cin >> opcion;
        } while (opcion < 1 || opcion > 4);
        switch(opcion){
            case 1:
                return fichaJugador[opcion-1];
                default:
                    break;
            case 2:
                return fichaJugador[opcion-1];
            case 3:
                return fichaJugador[opcion-1];
            case 4:
                return fichaJugador[opcion-1];
        }
    }

    void mostrarDatos(){
        cout<<"Nombre del Jugador: "<<nombre<<endl;
        cout<<"Color del jugador: "<<color<<endl;
    }

    string getNombre(){
        return nombre;
    }
};


#endif //UNTITLED_JUGADOR_H
