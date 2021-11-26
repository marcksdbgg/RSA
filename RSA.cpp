//
// Created by marck on 24/11/2021.
//

#include "RSA.h"

RSA::RSA(int bits) {
    vector<int> random_prime = prime_bits(bits); //Primos entre (bits^2)/2 y (bits^2)-1
    p = random_prime[modulo(random(3033, 3303 + random_prime.size()), random_prime.size() - 1)];
    q = random_prime[modulo(random(3433, 3343 + random_prime.size()), random_prime.size() - 1)];
    e = random_prime[random(0, random_prime.size() - 1)];

    N = p * q;
    oN = (p-1)*(q-1);
    while (mcd(e, oN) != 1) {
        e = random_prime[random(0, random_prime.size() - 1)];
    }
    d = E_extendido(e, oN);
    cout << "El valor de \"p\" es: " << p << endl;
    cout << "El valor de \"q\" es: " << q << endl;
    cout << "El valor de \"e\" es: " << e << endl;
    cout << "El valor de \"d\" es: " << d << endl;
    cout << "El valor de \"N\" es: " << N << endl;
}

RSA::RSA(int a, int b) {
    e = a;
    N = b;
}

void RSA::encriptado(int mensaje) {
    msg_encriptado = Exponenciacion_mod(mensaje, e, N);
}

void RSA::decifrado(int msg) {
    mensaje = Exponenciacion_mod(msg, d, N);
}

void RSA::mostrar_encriptado() {
    cout << endl << "Mensaje cifrado: "<< msg_encriptado <<endl;
}

void RSA::mostrar_decifrado() {
    cout << "Mensaje decifrado: "<<mensaje;
}
