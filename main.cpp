#include <iostream>
#include<string>
#include<time.h>
#include <vector>
#include "Juego.h"
#include "Jugador.h"
#include "Dado.h"
#include "Casillla.h"
#include "Tablero.h"
#include "Ficha.h"
#include "Recorrido.h"
#include <random>

#define DEF {\
    srand(time(NULL));\
    auto * ludo = new Juego();\
    ludo->IniciarJuego();\
    return 0;\
}
using namespace std;

int main() DEF