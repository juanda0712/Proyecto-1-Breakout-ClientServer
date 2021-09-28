#ifndef SERVER_SOCKETSERVER_H
#define SERVER_SOCKETSERVER_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>

using namespace std;

/**
 * structura  dataSocket:
 *
 * ES una estructura creada para guardar el descriptor y la informacion del socket cliente.
 * Representa a los clientes
 * @author Juan Rodriguez
 */
struct dataSocket{
    int descriptor;
    sockaddr_in info;
};

/**
 * Clase SocketServer:
 *
 * Es la clase para el socket del server. Contiene los componentes necesarios para identificar y alamcenar sistemas..
 * Establece métodos para Iniciar el servidor, enviar mensajes al cliente, crear el socket , conectar el socket,
 * con el kernel y monitorear lo que el cliente envie.
 *
 * @author Juan Rodriguez
 */
class SocketServer{
public:
    SocketServer();
    void run();
    void setMensaje(const char* msn);

private:
    int descriptor;
    sockaddr_in info;
    vector<int> clientes;

    bool crearSocket();
    bool enlazarKernel();
    static void* controladorCliente(void* obj);
};
#endif //SERVER_SOCKETSERVER_H
