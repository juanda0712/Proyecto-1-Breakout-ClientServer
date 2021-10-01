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
 * Tambien crea una ventana que sirve para el input del cliente.
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

    auto* window = new RenderWindow(VideoMode(200,200), "Client controller", Style::Titlebar);
    window->clear(Color::White);

    window->display();

    while (window->isOpen()){
        string msn;
        msn = kl.updateKeyPressed();
        if (msn == "Esc") {
            cliente->setMensaje(msn.c_str());
            window->close();
        }
        cliente->setMensaje(msn.c_str());
    }
    delete window;
    delete cliente;

    return 0;
}
