#include "SocketClient.h"
#include "KeyListener.h"

SocketClient* cliente;

void * clienteRun(void *){
    try{
        cliente->conectar();
    }catch (string ex) {
        cout << ex << endl;
    }
    pthread_exit(NULL);
}

/**
 * Función main:
 * Crea una instancia de cliente y un hilo sobre el cual se ejecuta en segundo plano.
 * Tambien crea una sesión de juego y constantemente actualiza y renderiza la pantalla.
 *
 * @authors Juan Rodríguez Eduardo Bolívar
 * @return 0
 */
int main() {
    cliente = new SocketClient;
    pthread_t hiloC;
    pthread_create(&hiloC, 0, clienteRun, NULL);
    pthread_detach(hiloC);

    string json = "Hola desde el cliente";
    cliente->setMensaje(json.c_str());

    KeyListener kl;
    while (true){
        string msn;

        if(msn == "salir")
            break;
        cliente->setMensaje(msn.c_str());
    }
    delete cliente;

    return 0;
}
