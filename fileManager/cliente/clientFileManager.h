#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

#include "utils.h"
#include "operaciones.h"

class ClientFileManager{
	private:
		std::string ipServer = "172.31.50.58"; // ip maquina 2
		int port = 31083;
		connection_t server;

	public:
		ClientFileManager(std::string path);
		~ClientFileManager();
		std::vector<std::string*>* listFiles();
		void readFile(char* fileName, char* &data, unsigned long int &dataLength);
		void writeFile(char* fileName, char* data, unsigned long int dataLength);
};