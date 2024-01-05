// Authors: Antonio Cabrera y Alejandro Gómez
// Group: 3º MAIS  2023/2024

# include <stdio.h>
# include <stdlib.h>
# include <sstream>
# include <iostream>
# include "utils.h"
# include "operaciones.h"
# include "clientFileManager.h"


ClientFileManager::ClientFileManager(std::string path){

    this->server = initClient(this->ipServer, this->port);

    static std::vector<unsigned char> buffIn;
	static std::vector<unsigned char> buffOut;
    
	buffIn.resize(0);
	buffOut.resize(0);

	int dataLen = (path.length() + 1);
    pack(buffOut, opBuilder);
	pack(buffOut, dataLen);
	packv(buffOut, path.c_str(), dataLen);

    sendMSG(this->server.serverId, buffOut);
    recvMSG(this->server.serverId, buffIn);

    int ok = unpack<int>(buffIn);
	if (!ok) std::cout << "Error: " << __FILE__ << ":" << __LINE__ << std::endl;
}

ClientFileManager::~ClientFileManager(){
    std::vector<unsigned char> buffIn;
	std::vector<unsigned char> buffOut;
	
	buffIn.resize(0);
	buffOut.resize(0);

	pack(buffOut, opDestroyer);

	sendMSG(this->server.serverId, buffOut);	
	recvMSG(this->server.serverId, buffIn);
	
    int ok = unpack<int>(buffIn);
    if (!ok) std::cout << "Error: " << __FILE__ << __LINE__ << std::endl;

	closeConnection(this->server.serverId);
}

std::vector<std::string*>* ClientFileManager::listFiles(){
	static std::vector<unsigned char> buffIn;
	static std::vector<unsigned char> buffOut;
    std::vector<std::string*>* files = new std::vector<std::string*>();

    buffIn.resize(0);
	buffOut.resize(0);
	
	pack(buffOut, opListFiles);
	
	sendMSG(this->server.serverId, buffOut);
	recvMSG(this->server.serverId, buffIn);

    //Comprobamos si ha habído algún error
    int ok = unpack<int>(buffIn);
	if (ok){

		int filesTam = unpack<int>(buffIn);
		files->resize(filesTam);
		int fileTam = 0;
		
		for (int i = 0; i < filesTam; i++) {
			fileTam = unpack<int>(buffIn); 
			std::string* file = new std::string();
			file->resize(fileTam);
			unpackv(buffIn, (char*)file->data(), fileTam);
			(*files)[i] = file;
		}

	}else{
		std::cout << "Error: " << __FILE__ << ":" << __LINE__ << std::endl;
	}
	
	return files;
}

void ClientFileManager::readFile(char* fileName, char* &data, unsigned long int &dataLen){
    std::vector<unsigned char> buffIn;
	std::vector<unsigned char> buffOut;
	
	buffIn.resize(0);
	buffOut.resize(0);

    pack(buffOut, opReadFile);
    int fileNameLen = (strlen(fileName) + 1);
	pack(buffOut, fileNameLen);
	packv(buffOut, fileName, fileNameLen);
			
	sendMSG(this->server.serverId, buffOut);
	recvMSG(this->server.serverId, buffIn);
	
	dataLen = unpack<unsigned long int>(buffIn);
	data = new char[dataLen];
	unpackv(buffIn, data, dataLen);

    //Comprobamos por si ha habído algún error
    int ok = unpack<int>(buffIn);
    if (!ok){
        std::cout << "Error: " << __FILE__ << __LINE__ << std::endl;
    } 
}
void ClientFileManager::writeFile(char* fileName, char* data, unsigned long int dataLen){
    std::vector<unsigned char> buffIn;
	std::vector<unsigned char> buffOut;
	
	buffIn.resize(0);
	buffOut.resize(0);

    pack(buffOut, opWriteFile);
    int fileNameLen = (strlen(fileName) + 1);
	pack(buffOut, fileNameLen);
	packv(buffOut, fileName, fileNameLen);
			
	pack(buffOut, dataLen);
	packv(buffOut, data, dataLen);
			
	sendMSG(this->server.serverId, buffOut);
    recvMSG(this->server.serverId, buffIn);

    //Comprobamos por si ha habído algún error
    int ok = unpack<int>(buffIn);
    if (!ok){
        std::cout << "Error: " << __FILE__ << __LINE__ << std::endl;
    }
}