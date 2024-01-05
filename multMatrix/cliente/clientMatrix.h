// Authors: Antonio Cabrera y Alejandro Gómez
// Group: 3º MAIS 2023/2024

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "utils.h"
#include "multmatrix.h"
#include "operacionesMatrix.h"

class clientMatrix{
	private:
		std::string ipServer = "172.31.49.54"; // ip maquina 3
		int port = 31082;
		connection_t server;
		
	public:
		/* Funciones */

		clientMatrix();     //Constructor de clienteMatrix, realiza la conexión con el  servidor
		~clientMatrix();   //Destructor de clienteMatrix, desconexión con el servidor        
		matrix_t* readMatrix(const char* fileName);             //Función que lee una matriz del servidor
		matrix_t *multMatrices(matrix_t* m1, matrix_t *m2);     //Función que envia dos matrices al servidor, y recibe su multiplicación
		void writeMatrix(matrix_t* m, const char* fileName);    //Manda una matriz al servidor para que la escriba
		matrix_t *createIdentity(int rows, int cols);           //Envia al servidor el tamaño de una matriz, y recibe de este una matriz identidad
		matrix_t *createRandMatrix(int rows, int cols);         //Envia al servidor el tamaño de una matriz, y recibe de este una matriz aleatoria
	};
