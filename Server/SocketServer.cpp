#include "SocketServer.h"

/**
 * Constructor SocketServer:
 *
 * El constructor del socket del servidor no inicializa ningun atributo.
 *
 * @author JUan Rodriguez
 */
SocketServer::SocketServer() {}

/**
 * Método crearSocket():
 *
 * ES el metodo que crea el socket.
 * Define y valida el descriptor del socket con la funcion "socket".
 * Difine el tipo de conexion, define el puerto y permite que se conecten clientes que tengan la ip y el puerto del servidor.
 *
 *
 * @author Juan Rodriiguez
 */
bool SocketServer::crearSocket() {
    //Crear un descriptor
    descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (descriptor < 0) //valida la creacion del socket
        return false;

    info.sin_family = AF_INET; //IPV4 tipo de conexion
    info.sin_addr.s_addr = INADDR_ANY; //acepta a cualquiera con mi ip y mi puerto
    info.sin_port = htons(4050); //definimos el puerto
    memset(&info.sin_zero, 0, sizeof(info.sin_zero)); //limpiamos la estructura
    return true;
}

/**
 * Método enlazarKernel():
 *
 * Es el metodo que enlaza al socket con el kernel.
 * Utiliza la funcion "bind" para enlazar el socket y lo valida con un condicional
 * POne a escuchar al socket enlazado un maximo de 4 clientes
 *
 *
 * @author Juan Rodriiguez
 */
bool SocketServer::enlazarKernel() {
    if ((bind(descriptor, (sockaddr *)&info, (socklen_t)sizeof(info))) < 0)
    return false;

    listen(descriptor,4);
    return true;
}

/**
 * Método run():
 *
 * Es el metodo que inicia el servidor.
 * Llama a los metodos crearSocket y enlazarSocket
 * Tiene un ciclo infinito para aceptar a los clientes
 * envia la informacion de los clientes al controlador de clientes.
 *
 * @author Juan Rodriiguez
 */
void SocketServer::run() {
    //validar errores al crear el socket y enlazar kernel
    if (!crearSocket())
        throw string("Hubo un error al crear el socket");

    if (!enlazarKernel())
        throw string("Hubo un error al enlazar el kernel");

    while(true){
        dataSocket clientData;
        socklen_t clientLen = sizeof(clientData.info);
        cout << "Esperando a que conecte un cliente..." << endl;
        clientData.descriptor = accept(descriptor,(sockaddr *)&clientData.info,&clientLen); //funcion bloqueante

        if (clientData.descriptor < 0){
            cout << "Error al aceptar el cliente" << endl;
            break;
        }
        else{
            clientes.push_back(clientData.descriptor);
            cout << "Cliente conectado" << endl;
            pthread_t hilo;
            pthread_create(&hilo,0,SocketServer::controladorCliente,(void *)&clientData);
            pthread_detach(hilo);
        }
    }
    close(descriptor);
}

/**
 * Método controladorCliente():
 *
 * Este metodo lleva el control de los mensajes de los clientes
 * Cada cliente es un hilo
 *
 * @author Juan Rodriiguez
 */
void* SocketServer::controladorCliente(void* obj) {
    dataSocket* clientData = (dataSocket * )obj;

    while(true){
        string mensaje;
        char buffer[1024] = {0};
        while(true){
            memset(buffer,0,1024);
            int bytes = recv(clientData->descriptor, buffer, 1024, 0); //funcion bloqueante
            mensaje.append(buffer, bytes);
            if (bytes <= 0 ){
                close(clientData->descriptor);
                pthread_exit(NULL);
            }
            if(bytes < 1024){
                break;
            }
        }



        cout << mensaje << endl; //mensaje del cliente
        //mensaje es la variable que me llega del cliente y tengo que ver que hago con ella en el servidor
        // se puede usar para el juego o para una clase
    }
    close(clientData->descriptor);
    pthread_exit(NULL);
}

/**
 * Método setMensaje():
 *
 * Envia mensajes del servidor al cliente
 *
 * @author Juan Rodriiguez
 */
void SocketServer::setMensaje(const char *msn) {
    for (int i = 0; i < clientes.size(); i++) {
        send(clientes[i], msn, strlen(msn), 0);
    }
}
