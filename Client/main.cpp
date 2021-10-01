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

    auto* window = new RenderWindow(VideoMode(200,200), "Hola", Style::Titlebar);
    window->clear(Color::White);
    window->display();
    KeyListener kl;
    while (window->isOpen()){
        string msn;
        msn = kl.updateKeyPressed();
        if(msn == "Esc") {
            window->close();
            cliente->setMensaje(msn.c_str());
        }
        cliente->setMensaje(msn.c_str());
    }
    delete window;
    delete cliente;

    return 0;
}
