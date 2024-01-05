// Authors: Antonio Cabrera y Alejandro Gómez
// Group: 3º MAIS 2023/2024

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "./utils.h"
#include "./operacionesMatrix.h"
#include "./multmatrix.h"

class ConexionCliente{
	private:
		int clientId = -1;
		multMatrix* m = new multMatrix();

	public:
		bool terminarConexion = false;

		ConexionCliente(int clientId)
		{
			if(clientId == -1)
				std::cout << "Error - ClientId no definido\n";
				
			this->clientId = clientId;
		};

		~ConexionCliente()
		{
			closeConnection(this->clientId);
		};

		void freeMatrix(matrix_t* m){
    		delete[] m->data;
    		delete[] m;
		}

		void recibeOp()
		{
			// declaramos los buffers de entrada y de salida
			std::vector<unsigned char> buffIn;
			std::vector<unsigned char> buffOut;
			buffIn.resize(0);
			buffOut.resize(0);
							
			// recibimos la operación
			std::cout << "Cliente " << clientId << " - recibiendo operación\n";
			recvMSG(clientId, buffIn);
	
			// desempaqueteamos el tipo de operación que es
			rpcTipoOperacion op;
			op=unpack<rpcTipoOperacion>(buffIn);
			
			switch(op)
			{
				case constructorClientOp:
				{
					std::cout << "Cliente " << clientId << " - invocando constructor\n";
					pack<int>(buffOut, 1);
					sendMSG(clientId, buffOut);	
				}break;

				case readOp:
				{
					std::cout << "Cliente " << clientId << " - leyendo matriz\n";
			
					// desempaquetar el nombre del archivo del que leemos la matriz
					std::string fileName;
					int datoLength=unpack<int>(buffIn);
					fileName.resize(datoLength);
					unpackv(buffIn, (char *)fileName.data(), datoLength);

					// leemos la matriz y la guardamos en res
					matrix_t* res = new matrix_t[1];
					res = m->readMatrix(fileName.data());

					if(res != NULL){  //Si la matriz leida no da  error

						//Empaquetamos la matriz leida
						pack(buffOut, (int)1); //Se ha leido correctamente
						pack(buffOut,(int)res->rows);
						pack(buffOut,(int)res->cols);
						packv(buffOut,res->data,(res->rows * res->cols));

					}else{
						std::cout << "Cliente " << clientId << " - No se ha podido leer la matriz\n";
						pack(buffOut, (int)0); //No se ha leido correctamente
					}
					sendMSG(clientId, buffOut);	
				}break;

				case multOp:
				{
					std::cout << "Cliente " << clientId << " - multiplicando matrices\n";

					matrix_t* m1 = new matrix_t[1];	
					matrix_t* m2 = new matrix_t[1];			

					//Desempaquetamos la primera matriz	
					m1->rows = unpack<int>(buffIn);
					m1->cols = unpack<int>(buffIn);
					m1->data = new int[m1->rows * m1->cols];
					unpackv(buffIn, m1->data,(m1->rows * m1->cols));

					//Desempaquetamos la segunda matriz
					m2->rows = unpack<int>(buffIn);
					m2->cols = unpack<int>(buffIn);
					m2->data = new int[m2->rows * m2->cols];
					unpackv(buffIn, m2->data,(m2->rows * m2->cols));
					
					// realizamos la operación y la guardamos en la matriz res
					matrix_t* res = new matrix_t[1];
					res = m->multMatrices(m1, m2);
				
					//Si la matriz resultante no da error
					if(res != NULL)
					{  
						//Empaquetamos respuesta
						pack(buffOut, (int)1); //Se ha realizado la multiplicación de forma correcta
						pack(buffOut, res->rows);
						pack(buffOut, res->cols);
						packv(buffOut, res->data, (res->rows * res->cols));
					}else{
						std::cout << "Cliente " << clientId << " - Error al multiplicar las matrices\n";
						pack(buffOut, (int)0); //Error al multiplicar
					}
					sendMSG(clientId, buffOut);	
					freeMatrix(m1);
					freeMatrix(m2);
					freeMatrix(res);
				}break;
						
				case writeOp:
				{
					std::cout << "Cliente " << clientId << " - Guardando matrices\n";
					
					// desempaquetar la matriz que queremos escribir
					matrix_t* m1 = new matrix_t[1];	
					m1->rows = unpack<int>(buffIn);
					m1->cols = unpack<int>(buffIn);
					m1->data = new int[(m1->rows * m1->cols)];
					unpackv(buffIn, m1->data,(m1->rows * m1->cols));
					
					// desempaquetar el nombre del archivo en el que vamos a escribir
					std::string fileName;
					int datoLength=unpack<int>(buffIn);
					fileName.resize(datoLength);
					unpackv(buffIn, (char *)fileName.data(), datoLength);
				
					// guardamos la matriz en local
					m->writeMatrix(m1, (char*)fileName.data());

					// empaquetamos la respuesta de éxito
					pack(buffOut, (int)1);
					sendMSG(clientId, buffOut);	
					freeMatrix(m1);
				}break;
					
				case identityOp:
				{
					std::cout << "Cliente " << clientId << " - Creando matriz identidad\n";
					
					// creamos la matriz identidad
					matrix_t* m1 = new matrix_t[1];	
					m1->rows = unpack<int>(buffIn);
					m1->cols = unpack<int>(buffIn);
					m1->data = new int[m1->rows * m1->cols];
					m1 = m->createIdentity(m1->rows, m1->cols);

					//Empaquetamos respuesta
					pack(buffOut, (int)1);
					pack(buffOut, m1->rows);
					pack(buffOut, m1->cols);
					packv(buffOut, m1->data, (m1->rows * m1->cols));
					sendMSG(clientId, buffOut);	
					freeMatrix(m1);
				}break;
					
				case randOp:
				{					
					std::cout << "Cliente " << clientId << " - Creando matriz aleatoria\n";
					
					// creamos la matriz aleatoria
					matrix_t* m1 = new matrix_t[1];	
					m1->rows = unpack<int>(buffIn);
					m1->cols = unpack<int>(buffIn);
					m1->data = new int[m1->rows * m1->cols];
					m1 = m->createRandMatrix(m1->rows, m1->cols);
				
					//Empaquetamos respuesta
					pack(buffOut, (int)1);
					pack(buffOut, m1->rows);
					pack(buffOut, m1->cols);
					packv(buffOut, m1->data, (m1->rows * m1->cols));
					sendMSG(clientId, buffOut);
					freeMatrix(m1);
				}break;
					
				case destructorClientOp:
				{
						//Mensaje comprobante
						std::cout << "Cliente " << clientId << " - Conexión cerrada con el cliente\n";
						pack(buffOut, (int)1);	
						this->terminarConexion = true;	
						sendMSG(clientId, buffOut);	
				}break;
					
				default:
				{
							
					std::cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<" operación no definida\n";
					//return NO OK
					pack(buffOut,(int)0);
					sendMSG(clientId, buffOut);	
				}break;
			} 
		};
};

