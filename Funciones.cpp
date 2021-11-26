//
// Created by marck on 24/11/2021.
//

#include "Funciones.h"

int modulo(int a, int n){
    int r = a-n*(a/n);
    r = r+(r<0)*n;
    return r;
}

int Euclides(int a, int b){
    while (modulo(a, b) != 0){
        int temp = b;
        b = modulo(a, b);
        a = temp;
    }
    return b;
}

int E_recursivo(int a, int b){
    if (modulo(a, b) == 0){
        return b;
    }
    else   {
        int temp = b;
        b = modulo(a, b);
        a = temp;
        E_recursivo(a,b);
    }
    return 0;
}

int mcd(int a, int b){
    return Euclides(a, b);
}

int E_extendido(int a, int b) {
    int cont = 0;
    int temp1 = a;
    int temp2 = b;
    while (modulo(a, b) != 0) {
        int temp = b;
        b = modulo(a, b);
        a = temp;
        cont++;
    }
    cont = cont + 2;
    int g[cont];
    g[0] = temp1;
    g[1] = temp2;

    int y[cont], u[cont], v[cont];
    u[0] = 1, u[1] = 0, v[0] = 0, v[1] = 1;
    for (int i = 1;; ++i) {
        y[i + 1] = g[i - 1] / g[i];
        g[i + 1] = g[i - 1] - (y[i + 1] * g[i]);
        u[i + 1] = u[i - 1] - (y[i + 1] * u[i]);
        v[i + 1] = v[i - 1] - (y[i + 1] * v[i]);
        if (g[i + 1] == 0) {
            return modulo(u[i], g[1]);
        }
    }
}

int Exponenciacion_mod(int base, int exponent, int mod){
    int reply = base;
    exponent/=2;
    while (exponent){
        base = modulo(base*base, mod);
        if (modulo(exponent, 2)){
            reply = modulo(reply*base, mod);
        }
        exponent/=2;
    }
    return reply;
}

int random(int begin, int end) {
    srand(time(NULL));
    return begin + rand() % (end - begin);
}

vector<int> criba_eratostenes(int limite)
{
    vector<int> criba;
    int prime_found;
    for (int i = 2; i <= limite; i++)
        criba.push_back(i);

    if (limite == 2 || limite == 3)
        return criba;

    vector<int>::iterator it = criba.begin();
    vector<int>::iterator it2;
    prime_found = *it;
    while (prime_found*prime_found < limite)
    {
        it2 = it + 1;

        for(; it2 <= criba.end(); it2++)
            if(*it2 % prime_found == 0)
                criba.erase(it2);
        it++;
        prime_found = *it;
    }

    return criba;
}


vector <int> prime_bits(int bit){
    vector <int> primos = criba_eratostenes(pow(2, bit)-1);
    vector<int>::iterator it = primos.begin();
    while (*it < pow(2, bit)/2){
        primos.erase(it);
    }
    return primos;
}

