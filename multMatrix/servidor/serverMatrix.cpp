// Authors: Antonio Cabrera y Alejandro Gómez
// Group: 3º MAIS  2023/2024

# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string>
# include "utils.h"
# include "operacionesMatrix.h"
# include "multmatrix.h"
# include "conexion_cliente.h"

// constantes
# define PUERTO 15000

void atiendeCliente(int clientId); // función que atiende a un cliente

int main(int argc, char** argv){
	
    std::cout << "Servidor iniciado en el puerto " << PUERTO << std::endl;
    int serverSocket = initServer(PUERTO);


    while(true){
		//esperar conexión cliente
		if(!checkClient()){
			//trabajo útil
			usleep(1000);
		
		}else{
            // obtenemos el id del cliente
        	auto clientId = getLastClientID();
        	// creamos un hilo para atender al cliente
		    std::thread* th=new std::thread (atiendeCliente,clientId);
        }
    }

    close(serverSocket);
	return 0;
}

void atiendeCliente(int clientId)
{
	// creamos un objeto de la clase ConexionCliente
    ConexionCliente c = ConexionCliente(clientId);
 
    // mientras no cierre conexión
    while(c.terminarConexion==false){
		c.recibeOp();
	}
}