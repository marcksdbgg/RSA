//
// Created by marck on 24/11/2021.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

class RSA {
public:
    RSA(int);
    RSA(int, int);
    void encriptado(int);
    void decifrado(int);
    void mostrar_encriptado();
    void mostrar_decifrado();

    int e;
    int N;
    int mensaje;
    int msg_encriptado;

private:
    int d;
    int p;
    int q;
    int oN;
};

