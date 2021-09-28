#include "SocketClient.h"

/**
 * Constructor SocketClient:
 *
 * El constructor del socket del servidor no inicializa ningun atributo.
 *
 * @author JUan Rodriguez
 */
SocketClient::SocketClient() {}


/**
 * Método conectar():
 *
 * Es el metodo que permite al cliente conectarse a un servidor.
 * Define el descriptor del cliente con la funcion "socket".
 * Valida la creacion del socket.
 * Define la informacion del socket: tipo de conexion, ip del servidor, puerto del servidor.
 * Se conexta al servidor con la funcion "connect".
 *
 * @author Juan Rodriiguez
 */
void SocketClient::conectar() {
    //Crear un descriptor
    descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (descriptor < 0) //valida la creacion del socket
        cout << "Error al crear el socket " << endl;

    info.sin_family = AF_INET; //IPV4 tipo de conexion
    info.sin_addr.s_addr = inet_addr("127.0.0.1");
    info.sin_port = ntohs(4050); //definimos el puerto
    memset(&info.sin_zero, 0, sizeof(info.sin_zero));
    cout << "Se creo el socket " << endl;

    if ((connect(descriptor, (sockaddr *)&info, (socklen_t)sizeof(info)))<0){
        cout << "Error al conectarse con el servidor";
    }
    cout << "Nos hemos conectado correctamente" << endl;
    pthread_t hilo;
    pthread_create(&hilo, 0, SocketClient::controlador, (void *)this);
    pthread_detach(hilo);

}

/**
 * Método controlador():
 *
 * Este metodo lleva el control de los mensajes que vienen del servidor
 *
 * @author Juan Rodriiguez
 */
void * SocketClient::controlador(void *obj) {
    SocketClient* c = (SocketClient *)obj;
    bool estado = true;
    while(true){
        string mensaje;
        char buffer[1024] = {0};
        //aca va la condicion para cerrar el while (cerrar la conexion con el socket)
        if (mensaje == "salir"){
            break;
        }

        while(true){
            memset(buffer,0,1024);
            int bytes = recv(c->descriptor, buffer, 1024, 0); //funcion bloqueante
            mensaje.append(buffer, bytes);
            if (bytes <= 0 ){
                close(c->descriptor);
                pthread_exit(NULL);
            }
            if(bytes < 1024){
                break;
            }
        }
        cout << mensaje << endl; //mensaje del servidor
        //mensaje es la variable que me llega del servidor y tengo que ver que hago con ella en el cliente
        // se puede usar para el juego o para una clase
    }
    close(c->descriptor);
    pthread_exit(NULL);

}
/**
 * Método setMensaje():
 *
 * Envia mensajes del cliente al servidor
 *
 * @author Juan Rodriiguez
 */
void SocketClient::setMensaje(const char *msn) {
    send(descriptor, msn, strlen(msn), 0);
}