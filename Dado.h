//
// Created by salvador.hilares on 22/06/2019.
//

#ifndef UNTITLED_DADO_H
#define UNTITLED_DADO_H

#include <random>
#include <iostream>
#include<string>
#include<time.h>
#include <vector>
#include <ctime>

class Dado{
public:
    static int Lanzar(){
        srand(time(NULL));
        int numero_dado = rand()%6+1;
        return numero_dado;
    }
};



#endif //UNTITLED_DADO_H
