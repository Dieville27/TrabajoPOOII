//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_JUEGO_H
#define UNTITLED_JUEGO_H

#include <random>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <ctime>
#include "Jugador.h"
#include "Dado.h"
#include "Casillla.h"
#include "Tablero.h"
#include "Ficha.h"
#include "Recorrido.h"
using namespace std;

vector<Jugador*>* CantidadJugadores;
int* Turno;
int siguiente = 0;

class Juego {
private:
    int turno;
    int numero_de_jugadores;
public:
    Juego(){
        int numberPlayer;
        cout<<"Ingrese el numero de jugadores:";
        cin>>numberPlayer;
        this->numero_de_jugadores = numberPlayer;
        this->turno = numberPlayer;
        CantidadJugadores = new vector<Jugador*>[4];
        Turno = new int[4];
        cout<<"LOS JUGADORES ENTRANTES SON "<<numero_de_jugadores<<endl;
        for(int i = 0 ; i<numero_de_jugadores; i++){
            CantidadJugadores->push_back(new Jugador());
            Turno[i] = 0;
        }
    }
    void IniciarJuego() {
        string Corroborar;
        cout << "Esta seguro que son todos los jugadores \n Tenga en cuenta que son maximo 4\n Si la respuesta es Si: ";
        cout << "Escriba si ;en caso contrario, escriba no: ";
        cin >> Corroborar;
        auto *tabla = new Tablero();
        if (Corroborar == "no") {
            cout << "Ingrese el nombre del nuevo Jugador:";
            AdicionarJugador();
            imprimirDatosJugadores();
            cout << "Esta es la tabla donde empezaran a jugar bajo mis reglas muajaja xd" << endl;
            tabla->IngresoDatos();
            tabla->mostrar();
            cout << "Solo falta un paso mas para que los deje en paz y gobiernen sobre mi hermoso reino\n";
            cout << "Todos los jugadores lanzaran el dado para tener un turno determinado y no halla trampas :[\n";
            int aumentando = 0;
            for (Jugador *jugadores : *CantidadJugadores) {
                int numero = Dado::Lanzar();
                cout << "El numero del jugador " << jugadores->getNombre() << " es " << numero << endl;
                Turno[aumentando] = numero;
                aumentando++;
            }
            int contador = 0;
            for (int i = 0; i < 4; i++) {
                if (fichaJugador[i]->getEstado() != 'F' && contador != 4) {
                    while (fichaJugador[i]->getEstado() != 'F' || contador!=4) {
                        for (Jugador *jugadores : *CantidadJugadores) {
                            jugadores->jugar(Jugador::seleccionarFichaEnJuego(), Dado::Lanzar());
                            tabla->mostrar();
                            if(Dado::Lanzar()!=6) {
                                siguienteTurno();
                            }
                            validarFinJuego();
                            if(fichaJugador[i]->getEstado()=='F'){
                                contador++;
                            }
                        }
                    }
                    finalizarJuego();
                }
            }
        } else if (Corroborar == "si") {
            imprimirDatosJugadores();
            cout << "Esta es la tabla donde empezaran a jugar bajo mis reglas muajaja xd" << endl;
            tabla->IngresoDatos();
            tabla->mostrar();
            cout << "Solo falta un paso mas para que los deje en paz y gobiernen sobre mi hermoso reino\n";
            cout << "Todos los jugadores lanzaran el dado para tener un turno determinado y no halla trampas :[\n";
            int aumentando = 0;
            for (Jugador *jugadores : *CantidadJugadores) {
                int numero = Dado::Lanzar();
                cout << "El numero del jugador " << jugadores->getNombre() << " es " << numero << endl;
                Turno[aumentando] = numero;
                aumentando++;
            }
            int contador = 0;
            for (int i = 0; i < 4; i++) {
                if (fichaJugador[i]->getEstado() != 'F' && contador != 4) {
                    while (fichaJugador[i]->getEstado() != 'F' || contador!=4) {
                        for (Jugador *jugadores : *CantidadJugadores) {
                            jugadores->jugar(Jugador::seleccionarFichaEnJuego(), 6);
                            tabla->mostrar();
                            if(Dado::Lanzar()!=6) {
                                siguienteTurno();
                            }
                            validarFinJuego();
                            if(fichaJugador[i]->getEstado()=='F'){
                                contador++;
                            }
                        }
                    }
                    finalizarJuego();
                }
            }
        }
    }

    static void siguienteTurno(){
        cout<<"TURNO DEL JUGADOR QUE SACO EN EL DADO "<<Turno[siguiente]<<endl;
        siguiente++;
        if(siguiente==3)
            siguiente = 0;
    }

    static void validarFinJuego() {
        if (fichaJugador[0]->getEstado() == 'F' && fichaJugador[1]->getEstado() == 'F' &&
            fichaJugador[2]->getEstado() == 'F' &&
            fichaJugador[3]->getEstado() == 'F') {
            cout<<"Ganaste"<<endl;
        }
    }
    /*void validarCapturaFicha(){

    }*/

    static void finalizarJuego(){
        cout<<"Fin del juego"<<endl;
        cout<<"GRACIAS POR JUGAR"<<endl;
        // Invocación de los métodos delete //
    }

    void AdicionarJugador(){
        if(numero_de_jugadores == 4) {
            cout << "No puede agregar más Jugadores, por favor no insista";
        }
        else {
            numero_de_jugadores++;
            turno++;
            CantidadJugadores->push_back(new Jugador());
            Turno[turno] = 0;
        }
    }

    static void imprimirDatosJugadores(){
        int Imprimir = 0;
        cout<<"Estos son los jugadores ingresados al ludo:"<<endl;
        for(Jugador* jugadores : *CantidadJugadores){
            Imprimir++;
            cout<<"El jugador "<<Imprimir<<" tiene las siguientes caracteristicas: "<<endl;
            jugadores->mostrarDatos();
        }
    }

};


#endif //UNTITLED_JUEGO_H
