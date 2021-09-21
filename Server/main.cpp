#include "SocketServer.h"

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

    //ciclo para enviar mensajes al cliente
    string json = "Hola desde el servidor";
    while (true){
        string msn;
        cin >> msn;
        if(msn == "salir"){
            break;
        }
        server->setMensaje(json.c_str());

    }
    delete server;
    return 0;
}