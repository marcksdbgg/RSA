#include "RSA.h"

using namespace std;

int main() {
    RSA Mark(7);
    RSA extrano(Mark.e, Mark.N);
    extrano.mensaje = 69; 
    extrano.encriptado(extrano.mensaje);
    Mark.decifrado(extrano.msg_encriptado);
    extrano.mostrar_encriptado();
    Mark.mostrar_decifrado();

    return 0;
}
