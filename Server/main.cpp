#include "SocketServer.h"
#include "game/Game.h"

SocketServer* server;

void * serverRun(void *){
    try {
        server->run();
    }catch (string ex){
        cout << ex << endl;
    }
    pthread_exit(NULL);
}
int main() {
    server = new SocketServer;
    pthread_t hiloS;
    pthread_create(&hiloS, 0, serverRun, NULL);
    pthread_detach(hiloS);

    //ciclo para enviar mensajes a los clientes
    string json = "Hola desde el servidor";

    Game* game = new Game;
    while (game->isOn()){
        game->update();
        game->render();

        //server->setMensaje(json.c_str());
    }
    delete server;
    delete game;
    return 0;
}