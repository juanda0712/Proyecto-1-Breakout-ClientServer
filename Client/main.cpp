#include "SocketClient.h"
#include "game/Game.h"

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

    Game* session = new Game;

    while (session->isOn()){
        string msn;
        cin >> msn;
        session->update();
        session->render();
        if(msn == "salir")
            break;
        cliente->setMensaje(json.c_str());
    }

    delete session;
    delete cliente;

    return 0;
}
